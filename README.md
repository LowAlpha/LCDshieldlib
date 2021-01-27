## LCDShieldLib


LCDShieldLib is a C library to support the Arduino LCD Shield. It provides support to read from ADC/Key and write to the LCD display.  An example programme shows how to write to the LCD, and how to read from the ADC channel to return a raw value from keys and how to read key with value assigned to each key. 
The software is written in C and built using Microchip Studio and AVR-GCC on Windows. The module may be built directly with AVR-GCC either on Windows or Linux.
It uses LCD_AVR_4d.c to write to the LCD written by Donald Weiman (weimandn@alfredstate.edu) Very good LCD and AVR resources are available from Donald at http://web.alfredstate.edu/faculty/weimandn.


![Optional Text](../main/extras/LCDshieldimage.jpg)

## Description 

Arduino LCD Shield use 16x2 HD44780 compatible LCD and a keypad consisting of 5 keys — select, up, right, down and left to provide a user interface.  The keypad interface uses one ADC channel (AD0) to read an analogue key value determined by voltage divider network. This minimises use of the digital IO pins.

## Read from Key Pad

There functions to read from Keys are :-

```
void key_IO_init(void) ; 	                      // Initialize the IO for to read the keys
void key_init(void) ;	                          // Initialize the ADC to read the keys
uint16_t ADC_read(void) ;	                      // Read the ADC to read the keys. Returns raw ADC value in // range 0 to 1023.
uint8_t key_read(void) ;	                      // Returns a key value based on the defined values below

#define NO_KEY 0
#define SELECT_KEY 1
#define LEFT_KEY 2
#define UP_KEY 3
#define DOWN_KEY 4
#define RIGHT_KEY 5
```

## Write to Display

There functions to write to the display are :-

```
void lcd_IO_init_4d(void); 			                // Initialize the IO for the LCD
void lcd_init_4d(void); 			                  // Initialize the LCD
void lcd_write_character_4d(uint8_t);	          // Write as single ASCII Character
void lcd_write_string_4d(uint8_t *);	          // Write as null terminated C String
void lcd_write_instruction_4d(uint8_t); 	      // Write as single 8 but value as display command as list below

// LCD instructions
#define lcd_Clear           0b00000001          // replace all characters with ASCII 'space'
#define lcd_Home            0b00000010          // return cursor to first position on first line
#define lcd_EntryMode       0b00000110          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0b00001000          // turn display off
#define lcd_DisplayOn       0b00001100          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0b00110000          // reset the LCD
#define lcd_FunctionSet4bit 0b00101000          // 4-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0b10000000          // set cursor position
```
## IO Used

Arduino pins 4, 5, 6, 7, 8, 9 (AVR Port B bits 0,1 and 4,5,6,7) are used to interface with the LCD. Backlight on/off function is controlled via pin 10. Analog (pin 0 Port C bit 0) is used to read the buttons. Backlight on/off function is controlled via pin 10. (Not implemented).

The schematic for an [ LCD Shield ](../main/extras/lcdshieldschematic.jpg).

## Build Environment

Microchip Studio 7 Version: 7.0

avr-gcc (AVR_8_bit_GNU_Toolchain_3.6.2_1778) 5.4.0

Microsoft Windows 10




