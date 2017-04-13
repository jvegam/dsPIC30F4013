/* 
 * File:   timer.h
 * Author: Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Description: 
 * This program contains the definitions used in the timer configuration of
 * microcontroller dsPIC30F3014 and dsPIC30F4013.
 * 
 * There are 4 functions relations  with the timers
 * 
 *  - void TimerX_Init( uint16 config, uint16 period, 
 *                   uint8 PriorityValue, uint8 EnableInt); 
 *    Initialize the Timer X.
 * 
 *  - uint16 ReadTimerX(void);
 *    Return the TMRx value.
 * 
 *  - void StopTimerX(void);
 *    Clear the bit TxCONbits.TON;
 * 
 *  - void StartTimerX(void);
 *    Set a '1' the bit TxCONbits.TON;
 * 
 * Where 'X' is the number of the timer.   
 *  
 * Compiler: XC16
 * Version: v0.1
 * Initial release.
 *
 * Date:	20170413
 * Created on 13 de April de 2017, 09:30 PM
 */

#ifndef TIMER_H
#define	TIMER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
void Timer1_Init(uint16_t config, uint16_t period, uint8_t PriorityValue, uint8_t EnableInt);
void Timer2_Init(uint16_t config, uint16_t period, uint8_t PriorityValue, uint8_t EnableInt);
void Timer3_Init(uint16_t config, uint16_t period, uint8_t PriorityValue, uint8_t EnableInt);

uint16_t ReadTimer1(void);
void StopTimer1(void);
void StartTimer1(void);

uint16_t ReadTimer2(void);
void StopTimer2(void);
void StartTimer2(void);

uint16_t ReadTimer3(void);
void StopTimer3(void);
void StartTimer3(void);

#if defined(__dsPIC30F4013__)
 void Timer4_Init(uint16_t config, uint16_t period, uint8_t PriorityValue, uint8_t EnableInt);
 void Timer5_Init(uint16_t config, uint16_t period, uint8_t PriorityValue, uint8_t EnableInt);
 
 uint16_t ReadTimer4(void);
 void StopTimer4(void);
 void StartTimer4(void);
 
 uint16_t ReadTimer5(void);
 void StopTimer5(void);
 void StartTimer5(void);
#endif
 
void Write_OSCCONL_LPOSCEN (uint8_t value);  
 
#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_H */

