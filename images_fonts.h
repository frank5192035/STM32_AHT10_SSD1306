
// Jan 12, 2022 by Frank Hsiung
// image file that generate at http://javl.github.io/image2cpp/
const uint8_t title [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 0xfc, 0x00, 0x00, 0x00, 0x7c, 
0x7e, 0x7e, 0x7f, 0x7e, 0x7e, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xc7, 0x81, 
0x01, 0x00, 0x7c, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 
0xff, 0x7f, 0x7f, 0x7e, 0x7c, 0xf3, 0xe7, 0x9f, 0x3f, 0x7f, 0xff, 0xff, 0x01, 0x01, 0x7c, 0xfe, 
0x38, 0x01, 0x03, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 
0xf9, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xf9, 0x81, 0x03, 0x07, 0x0f, 0x7f, 0xff, 0x81, 
0x99, 0x3c, 0x3c, 0x3c, 0x99, 0x81, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x7f, 0x3f, 0x00, 0x00, 0x00, 0x3f, 
0x7f, 0x7f, 0xff, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 
0x03, 0x81, 0xe0, 0xf0, 0xf8, 0x7e, 0x7e, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xc1, 
0x80, 0x00, 0x7f, 0x3e, 0x00, 0x80, 0xe3, 0xff, 0xff, 0xfc, 0xf9, 0xe3, 0xcf, 0x9f, 0x7e, 0xfe, 
0xfe, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 
0xbf, 0xbf, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x9f, 0x81, 0xc0, 0xc0, 0xf0, 0xfc, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// -------------------------------------------------------------------------------------------------
const uint8_t font1_Idx[] = { // Dialog_plain_width
// Width: 24, Height: 29; are generated at https://oleddisplay.squix.ch/#/home
	0x18, // Width: 24; max. width
	0x1D, // Height: 29; store in 4 bytes
	0x20, // First Char: 32
	0x19, // Numbers of Chars: 26

	// Jump Table: B0+B1:jump value, B2: Font Bytes, B3: Font Bits
	0xFF, 0xFF, 0x00, 0x08,  // 32:65535; real font start from 33
	0x00, 0x00, 0x17, 0x0A,  // 33:0
	0x00, 0x17, 0x1E, 0x0B,  // 34:23
	0x00, 0x35, 0x46, 0x14,  // 35:53
	0x00, 0x7B, 0x33, 0x0F,  // 36:123
	0x00, 0xAE, 0x53, 0x17,  // 37:174
	0x01, 0x01, 0x43, 0x13,  // 38:257
	0x01, 0x44, 0x0E, 0x07,  // 39:324
	0x01, 0x52, 0x1C, 0x09,  // 40:338
	0x01, 0x6E, 0x1B, 0x09,  // 41:366
	0x01, 0x89, 0x2A, 0x0C,  // 42:393
	0x01, 0xB3, 0x4A, 0x14,  // 43:435
	0x01, 0xFD, 0x13, 0x08,  // 44:509
	0x02, 0x10, 0x1B, 0x09,  // 45:528
	0x02, 0x2B, 0x13, 0x08,  // 46:555
	0x02, 0x3E, 0x1D, 0x08,  // 47:574
	0x02, 0x5B, 0x37, 0x0F,  // 48:603
	0x02, 0x92, 0x33, 0x0F,  // 49:658
	0x02, 0xC5, 0x33, 0x0F,  // 50:709
	0x02, 0xF8, 0x37, 0x0F,  // 51:760
	0x03, 0x2F, 0x37, 0x0F,  // 52:815
	0x03, 0x66, 0x33, 0x0F,  // 53:870
	0x03, 0x99, 0x37, 0x0F,  // 54:921
	0x03, 0xD0, 0x31, 0x0F,  // 55:976
	0x04, 0x01, 0x37, 0x0F,  // 56:1025
	0x04, 0x38, 0x37, 0x0F,  // 57:1080
};

const uint8_t font1[] = { // Dialog_plain // each SSD1306 data byte is 8-bit vertical pixels.
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xFF,0x71,0x00,0xE0,0xFF,0x71,	// 33
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x0F,0x00,0x00,0xE0,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x0F,0x00,0x00,0xE0,0x0F,	// 34
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x0C,0x03,0x00,0x00,0x0C,0x03,0x00,0x00,0x0C,0x7F,0x00,0x00,0xCC,0x3F,0x00,0x00,0xFC,0x03,0x00,0xE0,0x1F,0x03,0x00,0xE0,0x0D,0x03,0x00,0x00,0x0C,0x7B,0x00,0x00,0x8C,0x7F,0x00,0x00,0xFC,0x03,0x00,0xC0,0x3F,0x03,0x00,0xE0,0x0F,0x03,0x00,0x00,0x0C,0x03,0x00,0x00,0x0C,0x03,0x00,0x00,0x0C,	// 35
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x30,0x00,0x00,0x7E,0x20,0x00,0x00,0xE6,0x60,0x00,0x00,0xC3,0x60,0x00,0x00,0xC3,0x60,0x00,0xE0,0xFF,0xFF,0x07,0x00,0x83,0x61,0x00,0x00,0x83,0x61,0x00,0x00,0x83,0x33,0x00,0x00,0x06,0x3F,0x00,0x00,0x00,0x1E,	// 36
	0x00,0x00,0x00,0x00,0x80,0x1F,0x00,0x00,0xC0,0x3F,0x00,0x00,0x60,0x60,0x00,0x00,0x20,0x40,0x00,0x00,0x20,0x40,0x60,0x00,0x60,0x60,0x70,0x00,0xC0,0x3F,0x3C,0x00,0x80,0x1F,0x0F,0x00,0x00,0x80,0x07,0x00,0x00,0xE0,0x01,0x00,0x00,0x78,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x8F,0x1F,0x00,0xC0,0xC3,0x3F,0x00,0xE0,0x60,0x60,0x00,0x60,0x20,0x40,0x00,0x00,0x20,0x40,0x00,0x00,0x60,0x60,0x00,0x00,0xC0,0x3F,0x00,0x00,0x80,0x1F,	// 37
	0x00,0x00,0x00,0x00,0x00,0x80,0x0F,0x00,0x00,0xC0,0x1F,0x00,0x80,0xEF,0x38,0x00,0xC0,0x7F,0x30,0x00,0xE0,0x38,0x60,0x00,0x60,0x70,0x60,0x00,0x60,0xE0,0x60,0x00,0x60,0xC0,0x61,0x00,0x60,0x80,0x73,0x00,0x60,0x00,0x37,0x00,0xC0,0x00,0x1E,0x00,0x00,0x00,0x1C,0x00,0x00,0x00,0x3F,0x00,0x00,0xC0,0x73,0x00,0x00,0xC0,0x60,0x00,0x00,0x00,0x40,	// 38
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x0F,0x00,0x00,0xE0,0x0F,	// 39
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x0F,0x00,0x00,0xFF,0x7F,0x00,0xC0,0x07,0xF0,0x01,0xE0,0x00,0x80,0x03,0x20,0x00,0x00,0x02,	// 40
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x02,0xE0,0x00,0x80,0x03,0xC0,0x07,0xF0,0x01,0x00,0xFF,0x7F,0x00,0x00,0xF0,0x0F,	// 41
	0x80,0x10,0x00,0x00,0x80,0x19,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x06,0x00,0x00,0xE0,0x7F,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x09,0x00,0x00,0x80,0x19,0x00,0x00,0x80,0x10,	// 42
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x80,0xFF,0x7F,0x00,0x80,0xFF,0x7F,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,	// 43
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0xF0,0x03,0x00,0x00,0xF0,	// 44
	0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x80,0x01,0x00,0x00,0x80,0x01,0x00,0x00,0x80,0x01,0x00,0x00,0x80,0x01,0x00,0x00,0x80,0x01,	// 45
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,0x70,	// 46
	0x00,0x00,0x00,0x01,0x00,0x00,0xF0,0x01,0x00,0x00,0xFF,0x00,0x00,0xE0,0x0F,0x00,0x00,0xFC,0x01,0x00,0xC0,0x3F,0x00,0x00,0xE0,0x03,0x00,0x00,0x60,	// 47
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x03,0x00,0x80,0xFF,0x1F,0x00,0xC0,0x03,0x3C,0x00,0xC0,0x00,0x30,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0xC0,0x00,0x30,0x00,0xC0,0x03,0x3C,0x00,0x80,0xFF,0x1F,0x00,0x00,0xFC,0x03,	// 48
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x60,0x00,0xC0,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0xE0,0xFF,0x7F,0x00,0xE0,0xFF,0x7F,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,	// 49
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x60,0x00,0xC0,0x00,0x70,0x00,0x60,0x00,0x78,0x00,0x60,0x00,0x6C,0x00,0x60,0x00,0x66,0x00,0x60,0x00,0x63,0x00,0x60,0x80,0x61,0x00,0xE0,0xE0,0x60,0x00,0xC0,0x71,0x60,0x00,0x80,0x3F,0x60,0x00,0x00,0x0F,0x60,	// 50
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0xC0,0x00,0x20,0x00,0x60,0x00,0x60,0x00,0x60,0x60,0x60,0x00,0x60,0x60,0x60,0x00,0x60,0x60,0x60,0x00,0x60,0x60,0x60,0x00,0xE0,0x60,0x60,0x00,0xC0,0xF0,0x30,0x00,0xC0,0xDF,0x30,0x00,0x00,0x8F,0x1F,0x00,0x00,0x00,0x0F,	// 51
	0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0xC0,0x07,0x00,0x00,0xF0,0x06,0x00,0x00,0x38,0x06,0x00,0x00,0x1E,0x06,0x00,0x00,0x07,0x06,0x00,0xC0,0x01,0x06,0x00,0x60,0x00,0x06,0x00,0xE0,0xFF,0x7F,0x00,0xE0,0xFF,0x7F,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x06,	// 52
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0xE0,0x3F,0x60,0x00,0xE0,0x1F,0x60,0x00,0x60,0x18,0x60,0x00,0x60,0x18,0x60,0x00,0x60,0x18,0x60,0x00,0x60,0x18,0x60,0x00,0x60,0x38,0x30,0x00,0x60,0x70,0x38,0x00,0x60,0xE0,0x1F,0x00,0x00,0xC0,0x0F,	// 53
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x03,0x00,0x00,0xFF,0x1F,0x00,0x80,0xE3,0x3F,0x00,0xC0,0x71,0x38,0x00,0xC0,0x38,0x70,0x00,0x60,0x18,0x60,0x00,0x60,0x18,0x60,0x00,0x60,0x18,0x60,0x00,0x60,0x38,0x70,0x00,0x60,0x70,0x38,0x00,0xC0,0xE0,0x1F,0x00,0x00,0xC0,0x0F,	// 54
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x40,0x00,0x60,0x00,0x78,0x00,0x60,0x00,0x3E,0x00,0x60,0xC0,0x0F,0x00,0x60,0xF0,0x01,0x00,0x60,0x7E,0x00,0x00,0xE0,0x0F,0x00,0x00,0xE0,0x03,0x00,0x00,0x60,	// 55
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x0F,0x00,0xC0,0x9F,0x3F,0x00,0xC0,0xF0,0x30,0x00,0xE0,0xE0,0x70,0x00,0x60,0x60,0x60,0x00,0x60,0x60,0x60,0x00,0x60,0x60,0x60,0x00,0x60,0x60,0x60,0x00,0xE0,0xF0,0x70,0x00,0xC0,0xF0,0x30,0x00,0xC0,0x9F,0x3F,0x00,0x00,0x0F,0x0F,	// 56
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x80,0x7F,0x30,0x00,0xC0,0xE1,0x60,0x00,0xE0,0xC0,0x61,0x00,0x60,0x80,0x61,0x00,0x60,0x80,0x61,0x00,0x60,0x80,0x61,0x00,0xE0,0xC0,0x31,0x00,0xC0,0xE1,0x38,0x00,0xC0,0x7F,0x1C,0x00,0x80,0xFF,0x0F,0x00,0x00,0xFC,0x03,	// 57
};
// -------------------------------------------------------------------------------------------------
