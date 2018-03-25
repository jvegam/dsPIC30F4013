/* 
 * File:   INT0_main.c
 * Author: (c)Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Description: 
 * Program that configure the INT0 module to produce an interrupt and change state
 * of LEDs of  PORTB
 *
 * INT0 --> RB0
 *
 *   
 * Compiler: XC16 v1.32
 * Version: v0.1
 * Initial release.
 *
 * Date:	20180325
 * Created on 25 de March de 2018, 11:17 AM
 */
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#include "system.h"
#include <libpic30.h>

int main(int argc, char** argv) {
    ADPCFG = 0x1FFF;
    TRISB  = 0x0000;
    LATB   = 0x0000;
   
    /* INT0 configuration
     * Falling edge
     * Priority 7
     */
     
    INTCON2bits.INT0EP = 1;
    IPC0bits.INT0IP = 7;
    IFS0bits.INT0IF = 0;
    IEC0bits.INT0IE = 1;
    
    while (1){

    }
    return (EXIT_SUCCESS);
}

/* Interrupt Service Routine */
void __attribute__((interrupt, auto_psv)) _INT0Interrupt (void){
    LATBbits.LATB0 = ~ LATBbits.LATB0;
    IFS0bits.INT0IF=0; 		
}

