/****************************************************************************

LCDshieldlib provides support to read from ADC/Key and write to the LCD
display on an Arduino LCD Shield.

It uses LCD_AVR_4d.c to write to the LCD written by Donald Weiman
(weimandn@alfredstate.edu)

****************************************************************************/
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "LCDshieldlib.h"

// Program ID
uint8_t program_author[]   = "LCDshieldlib";
uint8_t program_version[]  = "Version V1.0";

/******************************* Main Program Code ******************************/

int main(void)
{
	
 /********************** Example of the Writing to the LCD **********************/

// initialize the IO
    lcd_IO_init_4d();  
                                
// initialize the LCD controller as determined by the defines (LCD instructions)
    lcd_init_4d();			
	
// display the first line of information
    lcd_write_string_4d(program_author);

// set cursor to start of second line
    lcd_write_instruction_4d(lcd_SetCursor | lcd_LineTwo);
                                 
// display the second line of information
    lcd_write_string_4d(program_version);

// Display for 5 seconds
    _delay_ms(5000);

/*********************** Example of the Reading the ADC  **********************/

uint16_t  ADCValue = 0;
uint8_t  key = 0;
char s[22] ;
uint8_t i = 0 ;
	
// initialize the IO
	key_IO_init(); 

// initialize the ADC to read teh key value
	key_init();
	
// set cursor to start of second line
	lcd_write_instruction_4d(lcd_SetCursor | lcd_LineOne);

// display the second line of information
	lcd_write_string_4d((uint8_t *)">>> ADC Test <<<");
	
// Display the ADC value for 10 seconds ie 100 loops of 100msec
    for (i = 0 ; i < 100 ; i++)
	  {
// read the ADC
	  ADCValue = ADC_read()	;
	  
// Move to start of line 2
	  lcd_write_instruction_4d(lcd_SetCursor |lcd_LineTwo); 
	   
// write the ADC value to a string and write the string to the LCD        
	  sprintf(s,"ADC Value = %04u",ADCValue) ;
	  lcd_write_string_4d((uint8_t *)s);
	  
// delay form 100msec	  
	  _delay_ms(100);
      }

/******************** Example of the Reading the Key Value  ******************/  
 	  
// set cursor to start of first line
	lcd_write_instruction_4d( lcd_SetCursor | lcd_LineOne);

// display the second line of information
	lcd_write_string_4d((uint8_t *)">>> Key Test <<<");	  
	  
	while(1)
	  {
		  
// read a key value 
		key = key_read()	;
		
// assign a string base on which button was pushed
		  switch (key)              
		     {
			 case NO_KEY:
			    {
			    sprintf(s,"Key = NO KEY    ") ;
			    break;
			    }
			  case SELECT_KEY:
				{
				sprintf(s,"Key = SELECT    ") ;
				break;
				}
			  case LEFT_KEY:
				{
				sprintf(s,"Key = LEFT      ") ;
				break;
				}
			  case UP_KEY :
				{
				sprintf(s,"Key = UP        ") ;
				break;
				}
			  case DOWN_KEY:
				{
				sprintf(s,"Key = DOWN      ") ;
				break;
				}
			  case RIGHT_KEY :
				{
				sprintf(s,"Key = RIGHT     ") ;
				break;
				}
			 }
// move to start of line 2
		lcd_write_instruction_4d(lcd_SetCursor |lcd_LineTwo); 
		
// write the key string      
		lcd_write_string_4d((uint8_t *)s);
		
// delay form 100msec
		_delay_ms(100);
	      }
    return 0;
}
/***************************** End of Main Program Code ********************/


