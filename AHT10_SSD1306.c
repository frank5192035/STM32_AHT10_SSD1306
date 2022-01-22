// This example is for Nucleo-F411 board connecting with AHT10 Module by I2C1 @ PB8&PB9
//                                                   & SSD1306 Module by I2C3 @ PA8&PB4
// State Machine of AHT10 @ AHT10_SSD1306.graphml(yEd)
//                                                  2021 Dec, by Frank Hsiung

#include "main.h"
#include <string.h>
#include <stdio.h>
#include "images_fonts.h"

I2C_HandleTypeDef hi2c1, hi2c3;

const uint32_t tickWait = 1000; // read data every tickWait mini-second
const uint8_t yByte = 3;        // Display Area

static uint32_t tickEnd;                           // for State Machine Time-out
static uint8_t buf_Str[6];                         // String for SSD1306 Display
static uint8_t buf_AHT_Tx[3] = {0xE1, 0x08, 0x00}; // AHT10 Initialization: datasheet is not clear here!
static uint8_t buf_AHT_Rx[6];                      // Rx Buffer for further processing

typedef struct __PACKED
{
    const uint8_t cmd[1]; // Figure 8-7 : I2C-bus data format
    uint8_t px[1024];     // Refresh Buffer for Next Frame throught DMA
} FRAME;

FRAME frame __ALIGN_END = {
    .cmd = {0x40}, // the transmission of the following information will contain data bytes only.
};

void s_AHT10_SSD1306_Init(void);             // state machine
void s_AHT10_SSD1306_InitDelay(void);        //
void s_AHT10_SSD1306_IssueMeasureCmd(void);  //
void s_AHT10_SSD1306_MeasurementDelay(void); //
void (*ps_AHT10_SSD1306)(void);              // state machine functional pointer of AHT10_SSD1306

HAL_StatusTypeDef SSD1306_Cmd1(uint8_t ctrl) // Function for One-Byte Command
{
    uint8_t buf[2] = {0x00, 0x00}; // Figure 8-7 : I2C-bus data format
    buf[1] = ctrl;
    return HAL_I2C_Master_Transmit(&hi2c3, 0x78, buf, 2, HAL_MAX_DELAY);
}

HAL_StatusTypeDef SSD1306_Cmd2(uint8_t ctrl1, uint8_t ctrl2) // Function for Double-Byte Command
{
    uint8_t buf[4] = {0x80, 0x00, 0x00, 0x00};
    buf[1] = ctrl1;
    buf[3] = ctrl2;
    return HAL_I2C_Master_Transmit(&hi2c3, 0x78, buf, 4, HAL_MAX_DELAY);
}

void s_AHT10_SSD1306_Init(void)
{
    // --------------------------------- AHT10 Initialization --------------------------------------
    HAL_I2C_Master_Transmit(&hi2c1, 0x70, buf_AHT_Tx, 3, HAL_MAX_DELAY);

    // --------------------------------- SSD1306 Initialization-------------------------------------
    SSD1306_Cmd1(0xAE);       // Set Display OFF
    SSD1306_Cmd2(0x20, 0x00); // Addressing Mode= 10:Page(RESET), 00: Horizontal(for DMA) ; 01:Vertical ;
    SSD1306_Cmd2(0xA8, 0x3F); // Set Multiplex Ratio; The following Sequence @ Fig 2 of Application Note
    SSD1306_Cmd2(0xD3, 0x00); // Set Display Offset
    SSD1306_Cmd1(0x40);       // Set Display StartLine
    SSD1306_Cmd1(0xA0);       // Set Segment Re-map (A0h/A1h); A1: re-Map;
    SSD1306_Cmd1(0xC8);       // Set COM Output Scan Direction; 0xC8: up-right (yellow pixel)
    SSD1306_Cmd2(0xDA, 0x12); // Table 10-3 : COM Pins Hardware Configuration; Combination-7:
    SSD1306_Cmd2(0x81, 0x7F); // Set Contrast Control
    SSD1306_Cmd1(0xA4);       // enable display outputs according to the GDDRAM contents.
    SSD1306_Cmd1(0xA6);       // Set Normal Display
    SSD1306_Cmd2(0xD5, 0x80); // Set Osc Frequency
    SSD1306_Cmd2(0x8D, 0x14); // ChargePump On
    SSD1306_Cmd1(0xAF);       // Set Display ON

    uint16_t i;
    for (i = 0; i < 256; i++)          // [Row0:Row1]
        frame.px[i] = title[i];        // "temperature and humidity" bitmap title
    memset(frame.px + 256, 0x0A, 128); // [Row2]
    memset(frame.px + 896, 0x0A, 128); // [Row7]

    tickEnd = HAL_GetTick() + tickWait;           // set None Blocking Delay for Initialization
    ps_AHT10_SSD1306 = s_AHT10_SSD1306_InitDelay; // change state
}

void s_AHT10_SSD1306_InitDelay(void)
{
    if (HAL_GetTick() > tickEnd) // non-blocking delay
    {
        buf_AHT_Tx[0] = 0xAC; // rewrite Measurement Command Buffer
        buf_AHT_Tx[1] = 0x33; // set once only
        ps_AHT10_SSD1306 = s_AHT10_SSD1306_IssueMeasureCmd;
    }
}

void s_AHT10_SSD1306_IssueMeasureCmd(void) // issue measurement command
{
    HAL_I2C_Master_Transmit(&hi2c1, 0x70, buf_AHT_Tx, 3, HAL_MAX_DELAY);
    HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin); // LED Blinking; alive signal
    tickEnd = HAL_GetTick() + tickWait;         // for None Blocking Delay
    ps_AHT10_SSD1306 = s_AHT10_SSD1306_MeasurementDelay;
}

void s_AHT10_SSD1306_MeasurementDelay(void)
{
    if (HAL_GetTick() > tickEnd) // non-blocking delay
    {
        // ------------------------- calculate Temperature ---------------------------------------
        HAL_I2C_Master_Receive(&hi2c1, 0x70, buf_AHT_Rx, 6, HAL_MAX_DELAY); // AHT10 data back
        static uint32_t bits20;
        static float tempHumi;
        static uint8_t chrLen;
        // restructure to 20-bit data ------------------------------------------
        bits20 = ((uint32_t)(buf_AHT_Rx[3] & 0x0F) << 16) | ((uint32_t)buf_AHT_Rx[4] << 8) | buf_AHT_Rx[5];
        tempHumi = (float)bits20 * 0.000191 - 50;   // formula in datasheet
        sprintf((char *)buf_Str, "%.1f", tempHumi); // output formating
        chrLen = strlen((char *)buf_Str);           // number of character to be sent

        // Display Temperature -------------------------------------------------
        static uint8_t iChr;           // character index of Temperature String
        static uint8_t xByte;          // Anchor point of each Font; (Original at Top-Right Corner)
        static uint8_t iX, iY;         // Relative Distance to (xByte, yByte)
        static uint8_t jmp;            // Index of Font Jump Table
        static uint16_t jGap, jGapEnd; // Jump Value from Jump Table
        static uint16_t iFrame;        // Index of Frame Buffer
        static uint8_t fontHeight;     // Font Height
        static uint8_t fontWidth;      // Font Width

        memset(frame.px + 384, 0, 512); // clear Temperature & Humidity data Buffer
        fontHeight = font1_Idx[1] >> 3; // How many bytes in one column
        if ((font1_Idx[1] % 8) > 0)     // Font Height is fixed for all character
            fontHeight++;               // take care residual bytes

        xByte = 123;
        if (tempHumi < 0) // for negative value
            xByte = 127;  // Left most pixel; X-axis decreased by Byte

        for (iChr = 0; iChr < chrLen; iChr++) // string counter; number of char to be displayed
        {
            jmp = (buf_Str[iChr] - font1_Idx[2] + 1) * 4;      // Jump Table Index
            jGap = (font1_Idx[jmp] << 8) + font1_Idx[jmp + 1]; // Jump Value from Jump Table
            jGapEnd = jGap + font1_Idx[jmp + 2];               // Last Byte of Font

            fontWidth = font1_Idx[jmp + 3];    // It is variable width for different character
            for (iX = 0; iX < fontWidth; iX++) // font width counter
            {
                for (iY = 0; iY < fontHeight; iY++) // font-byte height counter
                {
                    iFrame = (xByte - iX) + (yByte + iY) * 128; // Which Byte of Frame Buffer
                    frame.px[iFrame] = font1[jGap];
                    if (jGap++ >= jGapEnd)
                        break; // no more residual bytes
                }
            }
            xByte = xByte - fontWidth + 1; // +1:compact; move to next char.
        }

        // ----------------------- calculate Humidity ------------------------------------------
        // restructure to 20-bit data ------------------------------------------
        bits20 = ((uint32_t)buf_AHT_Rx[1] << 12) | ((uint32_t)buf_AHT_Rx[2] << 4) | (buf_AHT_Rx[3] >> 4);
        tempHumi = (float)bits20 * 0.000095;        // formula in datasheet
        sprintf((char *)buf_Str, "%.1f", tempHumi); // output formating (truncation)

        // fill Humidity data to Buffer ----------------------------------------
        xByte -= 17;                          // Left most pixel; X-axis decreased by Byte
        for (iChr = 0; iChr < chrLen; iChr++) // string; number of char to be displayed
        {
            jmp = (buf_Str[iChr] - font1_Idx[2] + 1) * 4;      // Jump Table Index
            jGap = (font1_Idx[jmp] << 8) + font1_Idx[jmp + 1]; // Jump Value from Jump Table
            jGapEnd = jGap + font1_Idx[jmp + 2];               // Last Byte of Font

            fontWidth = font1_Idx[jmp + 3];    // It is variable width for different character
            for (iX = 0; iX < fontWidth; iX++) // font width counter
            {
                for (iY = 0; iY < fontHeight; iY++) // font height (by Byte)
                {
                    iFrame = (xByte - iX) + (yByte + iY) * 128; // Which Byte of Frame Buffer
                    frame.px[iFrame] = font1[jGap];             // fill one-byte font data
                    if (jGap++ >= jGapEnd)
                        break; // no more residual bytes
                }
            }
            xByte = xByte - fontWidth + 1; // move to next char. (+1:more compact)
        }
        HAL_I2C_Master_Transmit_DMA(&hi2c3, 0x78, (uint8_t *)&frame, sizeof(frame));
        ps_AHT10_SSD1306 = s_AHT10_SSD1306_IssueMeasureCmd; // change state
    }
}
