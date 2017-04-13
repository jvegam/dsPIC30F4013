/* 
 * File:   Timer.c
 * Author: Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Description: 
 * Program that define the development the functions relation to the 
 * Timers of dsPIC30F4013.  
 *  
 * Compiler: XC16
 * Version: v0.1
 * Initial release.
 *
 * Date:	20170413
 * Created on 13 de April de 2017, 09:30 PM
 */

#include <xc.h>
#include <stdint.h>
#include "timer.h"

void Timer1_Init(uint16_t config, uint16_t period, uint8_t PriorityValue, uint8_t EnableInt){
/*_________Módulo Temporizador__________*/
    PR1= period;
    TMR1= 0;    
/*______ Manejo de Interrupción_________*/
    IFS0bits.T1IF = 0;
    IPC0bits.T1IP = PriorityValue & 0x07;
    IEC0bits.T1IE = EnableInt & 0x01;
/*_______ Iniciar el Temporizador_______*/
    T1CON=config; 
}

void Timer2_Init(uint16_t config, uint16_t period, uint8_t PriorityValue, uint8_t EnableInt){
/*_________Módulo Temporizador__________*/
    PR2= period;
    TMR2= 0;
/*______ Manejo de Interrupción_________*/
    IFS0bits.T2IF = 0;
    IPC1bits.T2IP = PriorityValue & 0x07;
    IEC0bits.T2IE = EnableInt & 0x01;
/*_______ Iniciar el Temporizador_______*/
    T2CON=config;    
}

void Timer3_Init(uint16_t config, uint16_t period, uint8_t PriorityValue, uint8_t EnableInt){
/*_________Módulo Temporizador__________*/
    PR3= period;
    TMR3= 0;    
/*______ Manejo de Interrupción_________*/
    IFS0bits.T3IF = 0;
    IPC1bits.T3IP = PriorityValue & 0x07;
    IEC0bits.T3IE = EnableInt & 0x01;
/*_______ Iniciar el Temporizador_______*/
    T3CON=config;    
}

uint16_t ReadTimer1(void){
    return(TMR1);  
}

uint16_t ReadTimer2(void){
    return(TMR2);  
}

uint16_t ReadTimer3(void){
    return(TMR3);  
}

void StopTimer1(void){
    T1CONbits.TON= 0;
}

void StopTimer2(void){
    T2CONbits.TON= 0;
}

void StopTimer3(void){
    T2CONbits.TON= 0;
}

void StartTimer1(void){
    T1CONbits.TON= 1;
}

void StartTimer2(void){
    T2CONbits.TON= 1;
}

void StartTimer3(void){
    T3CONbits.TON= 1;
}



#if defined(__dsPIC30F4013__)
 void Timer4_Init( uint16_t config, uint16_t period, uint8_t PriorityValue, uint8_t EnableInt){
/*_________Módulo Temporizador__________*/
    PR4= period;
    TMR4= 0;    
/*______ Manejo de Interrupción_________*/
    IFS1bits.T4IF = 0;
    IPC5bits.T4IP = PriorityValue & 0x07;
    IEC1bits.T4IE = EnableInt & 0x01;
/*_______ Iniciar el Temporizador_______*/
    T4CON=config;      
 }
 
 
 void Timer5_Init( uint16_t config, uint16_t period, uint8_t PriorityValue, uint8_t EnableInt){
/*_________Módulo Temporizador__________*/
    PR5= period;
    TMR5= 0;    
/*______ Manejo de Interrupción_________*/
    IFS1bits.T5IF = 0;
    IPC5bits.T5IP = PriorityValue & 0x07;
    IEC1bits.T5IE = EnableInt & 0x01;
/*_______ Iniciar el Temporizador_______*/
    T5CON=config;       
 }
void StopTimer4(void){
    T4CONbits.TON= 0;
}

void StopTimer5(void){
    T5CONbits.TON= 0;
}

 void StartTimer4(void){
    T4CONbits.TON= 1;
}

void StartTimer5(void){
    T5CONbits.TON= 1;
}
#endif
 
void Write_OSCCONL_LPOSCEN(uint8_t value){
    if (value>0) {
        asm volatile ("mov #0x46, w0 \n"         
                      "mov #0x57, w1 \n"
                      "mov #_OSCCON,w2 \n"
                      "mov.b w0, [w2] \n"
                      "mov.b w1, [w2] \n"
                      "bset.b [w2],#1;");
    }
    else {
        asm volatile ("mov #0x46, w0 \n"         
                      "mov #0x57, w1 \n"
                      "mov #_OSCCON,w2 \n"
                      "mov.b w0, [w2] \n"
                      "mov.b w1, [w2] \n"
                      "bclr.b [w2],#1;");
    }        
}
