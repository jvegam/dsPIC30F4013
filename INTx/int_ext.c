/* 
 * File:   int_ext.c
 * Author: Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Description: 
 * Program that define the development the functions relation to the 
 * External Interruptions of the dsPIC30F4013.  
 *  
 * Compiler: XC16  v1.26
 * Version: v0.1
 * Initial release.
 *
 * Date:	20170417
 * Created on 17 de April de 2017, 11:22 PM
 */

#include <xc.h>
#include <stdint.h>
#include "int_ext.h"

void IntExt0_Init (INTconfig_t *x){
    INTCON2bits.INT0EP = x->Edge; 
/*______ Interrupt_________*/
    IFS0bits.INT0IF = 0;
    IPC0bits.INT0IP = x->Priority;
    IEC0bits.INT0IE = x->EnableINT;
}

void Set_IntExt0Edge (INTconfig_t *x){
    INTCON2bits.INT0EP = x->Edge;
}

void Set_IntExt0FlagINT (uint16_t *y){
    IFS0bits.INT0IF=(*y);
}

void IntExt1_Init(INTconfig_t *x){
    INTCON2bits.INT1EP = x->Edge;
/*______ Interrupt_________*/
    IFS1bits.INT1IF = 0;
    IPC4bits.INT1IP = x->Priority;
    IEC1bits.INT1IE = x->EnableINT;
}

void Set_IntExt1Edge(INTconfig_t *x){
    INTCON2bits.INT1EP = x->Edge;
}

void Set_IntExt1FlagINT (uint16_t *y){
    IFS1bits.INT1IF=(*y);
}

void IntExt2_Init(INTconfig_t *x){
    INTCON2bits.INT2EP = x->Edge;
/*______ Interrupt_________*/
    IFS1bits.INT2IF = 0;
    IPC5bits.INT2IP = x->Priority;
    IEC1bits.INT2IE = x->EnableINT;
}

void Set_IntExt2Edge(INTconfig_t *x){
    INTCON2bits.INT2EP = x->Edge;
}

void Set_IntExt2FlagINT (uint16_t *y){
    IFS1bits.INT2IF=(*y);
}