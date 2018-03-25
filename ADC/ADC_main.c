/* 
 * File:   ADC_main.c
 * Author: (c)Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Description: 
 * Program that convert the AN0 the Timers modules as counter and generate
 * a blink led by the PORTB[5..1].
 * Timer 1 --> RB1
 * Timer 2 --> RB2
 * Timer 3 --> RB3
 * Timer 4 --> RB4
 * Timer 5 --> RB5
 * 
 * The functions to configure the timers, it find inside of timer.c 
 * and timer.h files.
 * 
 *   
 * Compiler: XC16
 * Version: v0.1
 * Initial release.
 *
 * Date:	20180325
 * Created on 25 de March de 2017, 1:00 PM
 */
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "system.h"         
#include "user_functions.h" 
#include "xlcd.h"           
#include <libpic30.h>

unsigned int ADCvalue;

void InitPort(void)
{
    ADPCFG= 0X1F7F;     // AN7 only as input analog.
    LATB  = 0x0000;
    TRISB = 0x0080;     
    LATD  = 0x00;
    TRISD = 0x00;       
}

/* Programa que configura el LCD y saca un mensaje inicial*/
int main (void)
{  char string_tmp[6];
    
    InitPort();
    
    //____________________ Inicializacion del ADC ______________________//
    ADCON1= 0x0000;         // SSRC = 000 manual , ASAM=0 , SAMP = 0;
    ADCHS = 0x0007;         // Seleccion del canal AN7
    ADCSSL = 0x0000;        // Desactivado
    ADCON3 = 0x0020;        // SAMC = 0TAD , ADRC = 0 y  ADCS = 32 ó 0x20
    ADCON1bits.ADON = 1;    //ADC = ON
    //___________________________________________________________________//
    
    //_____________________ Inicializacion del LCD ______________________//
    XLCDInit();
    putrsXLCD("  ADC DEMO AN7 ");
    XLCDgotoXY(1,0);              
    putrsXLCD("BY:JUAN VEGA-UTP");
    __delay_ms(1000);
    WriteCmdXLCD(CLEAR_XLCD);  
    putrsXLCD("ADC CHANNEL AN7");
    XLCDgotoXY(1,0);
    putrsXLCD("VALUE = ");
    //___________________________________________________________________//
    
    while(1)
    { 
        ADCON1bits.SAMP=1;                  // Init signal sampling
        __delay_ms(200);                    // delay > 1TCY
        ADCON1bits.SAMP=0;                  // Init conversion secuence.
        while(!ADCON1bits.DONE);            // wait for DONE conversion
        ADCvalue=ADCBUF0;                   // Read buffer ADC
        sprintf( string_tmp,"%u",ADCvalue); // Convert Decimal value to String
        XLCDgotoXY(1,8);                    // Set Cursor to LCD 
        putrsXLCD("     ");                 // clear previous value 
        XLCDgotoXY(1,8);                    // Set Cursor to LCD 
        putsXLCD(string_tmp);               // print new value 
     }
}

