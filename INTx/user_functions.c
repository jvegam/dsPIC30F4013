/* 
 * File:   user_functions.c
 * Author: Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Description: 
 * Program that define the development the functions general to be used in the 
 * main program. 
 *  
 * Compiler: XC16  v1.26
 * Version: v0.1
 * Initial release.
 *
 * Date:	20170418
 * Created on 18 de April de 2017, 15:00 PM
 */

#include "user_functions.h"
#include <stdint.h>
#include "int_ext.h"

void INTx_initialize(void){
    
    /*External Interrupt 0*/
    IntExt0.config.Edge = 1;
    IntExt0.config.Priority = 7;
    IntExt0.config.EnableINT= 1;
    IntExt0.Set_Edge(IntExt0_SELF);
    IntExt0.Init(IntExt0_SELF);
    
     /*External Interrupt 1*/
    IntExt1.config.Edge = 1;
    IntExt1.config.Priority = 7;
    IntExt1.config.EnableINT= 1;
    IntExt1.Init(IntExt1_SELF);
    
     /*External Interrupt 1*/
    IntExt2.config.Edge = 1;
    IntExt2.config.Priority = 7;
    IntExt2.config.EnableINT= 1;
    IntExt2.Init(IntExt2_SELF); 
}
    