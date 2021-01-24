
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "LCDshieldlib.h"

// Program ID
uint8_t program_author[]   = ">>>>  Mark  <<<<";
uint8_t program_version[]  = "LCDshieldlib V1.0";

/******************************* Main Program Code *************************/
int main(void)
{
// initialize the IO
    lcd_IO_init_4d();  // initialize IO for a 4-bit interface
                                
// initialize the LCD controller as determined by the defines (LCD instructions)
    lcd_init_4d();                                  // initialize the LCD display for a 4-bit interface

// display the first line of information
    lcd_write_string_4d(program_author);

// set cursor to start of second line
    lcd_write_instruction_4d(lcd_SetCursor | lcd_LineTwo);
                                 
// display the second line of information
    lcd_write_string_4d(program_version);

    _delay_ms(3000);

// set cursor to start of second line
    lcd_write_instruction_4d(lcd_SetCursor | lcd_LineTwo);

// display the second line of information
    lcd_write_string_4d((uint8_t *)"LCD-AVR-LIB    ");

// endless loop
    while(1);
    return 0;
}
/******************************* End of Main Program Code ******************/


