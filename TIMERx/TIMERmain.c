/* 
 * File:   TIMERMain.c
 * Author: Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Description: 
 * Program that configure the Timers modules as counter and generate
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
 * Date:	20170413
 * Created on 13 de April de 2017, 09:30 AM
 */
 
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "system.h"
#include "timer.h"

void __attribute__((interrupt,auto_psv)) _T1Interrupt(void);
void __attribute__((interrupt,auto_psv)) _T2Interrupt(void);
void __attribute__((interrupt,auto_psv)) _T3Interrupt(void);

#if defined(__dsPIC30F4013__)
 void __attribute__((interrupt,auto_psv)) _T4Interrupt(void);
 void __attribute__((interrupt,auto_psv)) _T5Interrupt(void);
#endif 


int main(int argc, char** argv) {
    
    ADPCFG = 0x1FFF;			// All the PORTB as digital
    TRISB  = 0x1F00;			// PORTB[7..0] as digital out
    LATB   = 0x0000;			    // Initial Value PORTB[7..0] = 0 

    Timer1_Init(0x8020,15624,7,1);
    Timer2_Init(0x8020,23436,6,1);
    Timer3_Init(0x8020,37499,5,1);
    
#if defined(__dsPIC30F4013__)    
    Timer4_Init(0x8030,23436,4,1);
    Timer5_Init(0x8030,46874,3,1);
#endif 
    
    while(true){       
      
    }    
    return (EXIT_SUCCESS);
}

void __attribute__((interrupt,auto_psv)) _T1Interrupt(void){
    LATBbits.LATB1=~LATBbits.LATB1;
    IFS0bits.T1IF=0;
}

void __attribute__((interrupt,auto_psv)) _T2Interrupt(void){
    LATBbits.LATB2=~LATBbits.LATB2;
    IFS0bits.T2IF=0;
}

void __attribute__((interrupt,auto_psv)) _T3Interrupt(void){
    LATBbits.LATB3=~LATBbits.LATB3;
    IFS0bits.T3IF=0;
}

#if defined(__dsPIC30F4013__)
void __attribute__((interrupt,auto_psv)) _T4Interrupt(void){
    LATBbits.LATB4=~LATBbits.LATB4;
    IFS1bits.T4IF=0;
}

void __attribute__((interrupt,auto_psv)) _T5Interrupt(void){
    LATBbits.LATB5=~LATBbits.LATB5;
    IFS1bits.T5IF=0;
}
#endif 

