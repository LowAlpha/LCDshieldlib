
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
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

// initialize the IO
	key_IO_init();  // initialize IO for a 4-bit interface

// initialize the LCD controller as determined by the defines (LCD instructions)
	key_init();
	
	static uint16_t  ADCValue = 0; 
	static uint8_t  key = 0; 
	static char s[22] ;
	static uint8_t i = 0 ;

// set cursor to start of second line
	lcd_write_instruction_4d(lcd_SetCursor | lcd_LineOne);

// display the second line of information
	lcd_write_string_4d((uint8_t *)">>> ADC Test <<<");
	
// endless loop
    for (i = 0 ; i < 100 ; i++)
	  {
	  ADCValue = ADC_read()	;
	  lcd_write_instruction_4d(lcd_SetCursor |lcd_LineTwo);         // Move to start of line 2
	  sprintf(s,"ADC Value = %04u",ADCValue) ;
	  lcd_write_string_4d((uint8_t *)s);
	  _delay_ms(100);
      }
	  
	  
// set cursor to start of first line
	lcd_write_instruction_4d( lcd_SetCursor | lcd_LineOne);

// display the second line of information
	lcd_write_string_4d((uint8_t *)">>> Key Test <<<");	  
	  
	while(1)
	  {
		key = key_read()	;
		lcd_write_instruction_4d(lcd_SetCursor |lcd_LineTwo);         // Move to start of line 2

	 
		  switch (key)               // depending on which button was pushed, we perform an action
		     {
			 case NO_KEY:
			    {
			    sprintf(s,"Key = NO KEY ") ;
			    break;
			    }
			  case SELECT_KEY:
				{
				sprintf(s,"Key = SELECT ") ;
				break;
				}
			  case LEFT_KEY:
				{
				sprintf(s,"Key = LEFT   ") ;
				break;
				}
			  case UP_KEY :
				{
				sprintf(s,"Key = UP     ") ;
				break;
				}
			  case DOWN_KEY:
				{
				sprintf(s,"Key = DOWN   ") ;
				break;
				}
			  case RIGHT_KEY :
				{
				sprintf(s,"Key = RIGHT  ") ;
				break;
				}
			 }
		lcd_write_string_4d((uint8_t *)s);
		_delay_ms(100);
	      }
    return 0;
}
/******************************* End of Main Program Code ******************/


