/* 
 * File:   xlcd.h
 * Author: Puneet Khattar
 *
 * Description 
 * Functions to controller the LCD 16x2.
 *
 * Based on : 
 * $Id: openxlcd.c,v 1.1 2003/12/09 22:52:09 GrosbaJ Exp $ 
 * Edited by Puneet Khattar for use with PICDEM 2+ Demo Board 
 *
 * Edited by: Juan Vega Martinez for dsPIC30F4013 or dsPIC30F4013
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Compiler: XC16
 * Version: v0.1
 * Initial release.
 * Date:	20180325
 * Created on 25 de March de 2018, 12:54 AM
 */
 
#ifndef __XLCD_H
#define __XLCD_H

/* PIC18 XLCD peripheral routines.
 * Provided with C18 compiler from Microchip.com
 * Edited by Puneet Khattar for use with PICDEM 2+ Demo Board
 *
 *   Notes:
 *      - These libraries routines are written to support the
 *        Hitachi HD44780 LCD controller.
 *      - The user must define the following items:
 *          - The LCD interface type (4- or 8-bits)
 *          - If 4-bit mode
 *              - whether using the upper or lower nibble
 *          - The data port
 *              - The tris register for data port
 *              - The control signal ports and pins
 *              - The control signal port tris and pins
 *          - The user must provide three delay routines:
 *              - DelayFor18TCY() provides a 18 Tcy delay
 *              - DelayPORXLCD() provides at least 15ms delay
 *              - DelayXLCD() provides at least 5ms delay
 */

/* Interface type 8-bit or 4-bit
 * For 8-bit operation uncomment the #define BIT8
 */
/*#define BIT8 */

/* When in 4-bit interface define if the data is in the upper
 * or lower nibble.  For lower nibble, comment the #define UPPER
 */
/*#define UPPER */

/* DATA_PORT defines the port to which the LCD data lines are connected */
#define DATA_PORT  PORTD
#define TRIS_DATA_PORT  TRISD

/* CTRL_PORT defines the port where the control lines are connected.
 * These are just samples, change to match your application.
 */
#define RW_PIN   LATBbits.LATB10   /* PORT for RW */
#define TRIS_RW  TRISBbits.TRISB10    /* TRIS for RW */
#define RS_PIN   LATBbits.LATB9   /* PORT for RS */
#define TRIS_RS  TRISBbits.TRISB9    /* TRIS for RS */
#define E_PIN    LATBbits.LATB11   /* PORT for E  */
#define TRIS_E   TRISBbits.TRISB11    /* TRIS for E  */
//#define PWR_PIN	 PORTDbits.RD7	 /* PORT for PWR */
//#define TRIS_PWR DDRDbits.RD7	 /* TRIS for PWR */

/* Display ON/OFF Control defines */
#define DON         0b00001111  /* Display on      */
#define DOFF        0b00001011  /* Display off     */
#define CURSOR_ON   0b00001111  /* Cursor on       */
#define CURSOR_OFF  0b00001101  /* Cursor off      */
#define BLINK_ON    0b00001111  /* Cursor Blink    */
#define BLINK_OFF   0b00001110  /* Cursor No Blink */

/* Some Command Type defines							*/
#define CLEAR_XLCD		0x01		/* Clears the LCD		*/
#define RETURN_CURSOR_HOME	0x02		/* Returns the cursor to the HOME position	*/

/* Cursor or Display Shift defines */
#define SHIFT_CUR_LEFT    0b00010011  /* Cursor shifts to the left   */
#define SHIFT_CUR_RIGHT   0b00010111  /* Cursor shifts to the right  */
#define SHIFT_DISP_LEFT   0b00011011  /* Display shifts to the left  */
#define SHIFT_DISP_RIGHT  0b00011111  /* Display shifts to the right */

/* Function Set defines */
#define FOUR_BIT   0b00101111  /* 4-bit Interface               */
#define EIGHT_BIT  0b00111111  /* 8-bit Interface               */
#define LINE_5X7   0b00110011  /* 5x7 characters, single line   */
#define LINE_5X10  0b00110111  /* 5x10 characters               */
#define LINES_5X7  0b00111011  /* 5x7 characters, multiple line */
/* LINES*/
#define DDRAM_LINE1   0b10000000  /* 4-bit Interface               */
#define DDRAM_LINE2   0b11000000  /* 4-bit Interface               */
#define CGRAM_ADDRESS 0b01000000  /* 4-bit Interface               */

/* OpenXLCD
 * Configures I/O pins for external LCD
 */
void OpenXLCD(unsigned char lcdtype);

/* SetCGRamAddr
 * Sets the character generator address
 */
void SetCGRamAddr(unsigned char);

/* SetDDRamAddr
 * Sets the display data address
 */
void SetDDRamAddr(unsigned char);

/* BusyXLCD
 * Returns the busy status of the LCD
 */
unsigned char BusyXLCD(void);

/* ReadAddrXLCD
 * Reads the current address
 */
unsigned char ReadAddrXLCD(void);

/* ReadDataXLCD
 * Reads a byte of data
 */
char ReadDataXLCD(void);

/* WriteCmdXLCD
 * Writes a command to the LCD
 */
void WriteCmdXLCD(unsigned char cmd);

/* WriteDataXLCD
 * Writes a data byte to the LCD
 */
void WriteDataXLCD(char);

/* putcXLCD
 * A putc is a write
 */
#define putcXLCD WriteDataXLCD

/* putsXLCD
 * Writes a string of characters to the LCD
 */
void putsXLCD(char *);

/* putrsXLCD
 * Writes a string of characters in ROM to the LCD
 */
void putrsXLCD(const char *buffer);

/* User defines these routines according to the oscillator frequency */
//extern void DelayFor18TCY(void);   // 1us delay
//extern void DelayPORXLCD(void);    // 15ms delay
//extern void DelayXLCD(void); // 4.1ms

extern void Delay_1us(void);   // 1us delay
extern void DelayPORXLCD(void);    // 15ms delay
extern void DelayXLCD(void); // 4.1ms
extern void DelayExecution(void);

#endif
