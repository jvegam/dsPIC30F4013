/* 
 * File:   INTx_main.c
 * Author: (c)Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Description: 
 * Program that configure the INTx modules to produce an interrupt and change state
 * of LEDs of  PORTB
 *
 * INT0 --> RB1
 * INT1 --> RB2
 * INT2 --> RB3
 *
 * The functions to configure the timers, it find inside of timer.c 
 * and timer.h files.
 * 
 *   
 * Compiler: XC16 v1.26
 * Version: v0.1
 * Initial release.
 *
 * Date:	20170417
 * Created on 17 de April de 2017, 11:17 AM
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "system.h"
#include "int_ext.h"
#include "user_functions.h"
#include <libpic30.h>

/*          Declaration of Routines Service Interrupt             */
void __attribute__((interrupt,auto_psv)) _INT0Interrupt(void);
void __attribute__((interrupt,auto_psv)) _INT1Interrupt(void);
void __attribute__((interrupt,auto_psv)) _INT2Interrupt(void);

int main(int argc, char** argv) {
             
    ADPCFG = 0x1FFF;			// All the PORTB as digital
    TRISB  = 0x1F00;			// PORTB[7..0] as digital out
    LATB   = 0x0000;			    // Initial Value PORTB[7..0] = 0 
 
    INTx_initialize();
    
    while(true){       
      
    }    
    return (EXIT_SUCCESS);
}

/*                Routines Service Interrupt                    */
void __attribute__((interrupt,auto_psv)) _INT0Interrupt(void){
    LATBbits.LATB0=~LATBbits.LATB0;
    IntExt0Set_FlagINT(0);         //Other option:  IntExt0.Set_FlagINT(0);    
}

void __attribute__((interrupt,auto_psv)) _INT1Interrupt(void){
    LATBbits.LATB1=~LATBbits.LATB1;
    IntExt1Set_FlagINT(0);
}

void __attribute__((interrupt,auto_psv)) _INT2Interrupt(void){
    LATBbits.LATB2=~LATBbits.LATB2;
    IntExt2Set_FlagINT(0);
}



