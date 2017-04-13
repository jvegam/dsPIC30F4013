/* 
 * File:   GPIO.c
 * Author: (c)Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Descripcion: 
 * Program that configure the PORTB as digital and generate
 * a blink in the PORTB[7..0] each 500 ms.
 *  
 * Compiler: XC16
 * Version: v0.1
 * Initial release.
 *
 * Date:	20170331
 * Created on 31 de March de 2017, 06:51 PM
 */
 
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include <libpic30.h>
 
int main(int argc, char** argv) {

    ADPCFG = 0x1FFF;			// All the PORTB as digital
    TRISB  = 0x1F00;			// PORTB[7..0] as digital out
    LATB   = 0x00;			// Initial Value PORTB[7..0] = 0 
    
    while(1){       
       LATB=0xFF;
       __delay_ms(500);
       LATB=0x00;
       __delay_ms(500);
    }
    
    return (EXIT_SUCCESS);
}

