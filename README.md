# STM32_AHT10_SSD1306
Read AHT10 Temperature and Humidity data, then display them on 128*64 SSD1306 OLED. The Project was developed at STM32CubeIDE 1.8.0.

* AHT10_SSD1306.ioc: The setting of Nucleo-F411RE board; It set I2C1 and I2C3 port for this project.
* AHT10_SSD1306.graphml: state machine diagram in yEd. It should be opened by yEd graph editor. yEd web link: https://www.yworks.com/products/yed
* main.c: check all of codes in "USER CODE BEGIN/END" for add AHT10_SSD1306 state machine process.
* AHT10_SSD1306.c: The state machine for initialization AHT10 and SSD1306. Then read temperature and humidity data and display them on 128*64 OLED per second.
* images_fonts.h: This header file contents image bitmap data and font data. It should be copy into .\Core\inc directory after code generation by STM32CubeIDE.
