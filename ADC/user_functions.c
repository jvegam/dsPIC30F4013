/* 
 * File:   user_functions.c
 * Author: (c)Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Descripcion: 
 * Describe the user functions to use in the main program.  
 *  
 * Compiler: XC16
 * 
 * Version: v0.1
 * Initial release.
 *
 * Date:	20180325
 * Created on 25 de March de 2017, 1:00 PM
 */
 
#include "system.h"
#include <libpic30.h>

#include "user_functions.h"
#include "xlcd.h"


/*_________________________ LCD SUPPORT FUNCTIONS ____________________________*/
/* Required by the LCD function library */
void Delay_1us( void )
{
	__delay_us(2);	 		
	return;
}
/* Provide at least a 15ms delay */
void DelayPORXLCD( void )
{
	__delay_ms(25);		
	return;
}
/* Provide at least a 5ms delay */
void DelayXLCD( void )
{
	__delay_ms(7);	     
	return;
}

void DelayExecution( void )
{
	__delay_us(100);	      //  46us to Read/Write data operation
	return;
}

/*              Row  column                 */
void XLCDgotoXY(int x,int y)
{
    if ( x>0 ){WriteCmdXLCD(DDRAM_LINE2+y);}
    else {WriteCmdXLCD(DDRAM_LINE1+y);}
    return;
}

void XLCDInit(void)
{ 

    DelayPORXLCD();                               // Init delay routine
    OpenXLCD( FOUR_BIT & LINES_5X7 );             // Initialize LCD
    WriteCmdXLCD( DON & CURSOR_OFF & BLINK_OFF ); // Set parameters
    WriteCmdXLCD(CLEAR_XLCD); 						  // Clear LCD 
    WriteCmdXLCD(0x80);                           // Set Cursor to X=0 and Y=0 
    														     // XLCDgotoXY(0,0)

}

void XLCD_WriteChr_CGRAM( const char *buffer, unsigned char Address)
{ unsigned char i=0;
  
    SetCGRamAddr(Address*8);  	   // Set address
    for (i=0;i<8;i++)               // Write data to CGRAM LCD
    {  WriteDataXLCD(*buffer);      // Write character to LCD
       ++buffer;
    }
}
/*_______________________ END LCD SUPPORT FUNCTIONS __________________________*/