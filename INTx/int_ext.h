/* 
 * File:   int_ext.h
 * Author: Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Description: 
 * This program contains the definitions used in the external interrupts configuration of
 * microcontroller dsPIC30F3014 and dsPIC30F4013.
 * 
 * There are 3 functions relations  with the external interrupts.
 * 
 *  - IntExt#.Init(INTconfig_t *x); 
 *    Structure Function pointer, that use the Function void IntExt#_Init(INTconfig_t *x); 
 *    to configurate the External Interrupt # .
 * 
 *      *The struct INTconfig_t, contains informations of configuration and status.
 *       of the external interrupt.
 *       ejm:
 *     
 *        **Edge.      Set the type of EDGE, It may be FALLING_EDGE(1) 
 *                     o RISING_EDGE(0), in the bits INT#EP of INTCON2 register 
 *        **Priority.  Set the interrupt priority (0-7) in the registers IPCx 
 *        **EnableINT. Enable the ISR for External Interrupt. 
 *                       0 -> Disable
 *                       1 -> Enable  
 *      Note:
 *      IntExt#_SELF, is the equivalent to "&IntExt#.config" that is an INTconfig_t type
 *      in the struct: INTx_t     
 * 
 * Example of use of the functions of configuration
 *      
 *   IntExt#.config.Edge = 1;      // FALLING_EDGE
 *   IntExt#.config.Priority = 7;  // Priority 7
 *   IntExt#.config.EnableINT= 1;  // Enable Interrupt
 *   IntExt#.Init(IntExt#_SELF);   // Call inititialize function to the INT#
 *  
 * Where '#' is the number of the external interrupt,They may be 0,1,2.      
 *                      
 *  - IntExt#.Set_Edge(IntExt#_SELF);
 *    Structure Function pointer, that use the Function to Set_IntExt#Edge(uint16_t *y);
 *    to set Value to EDGE to INTCON2bits.INT0EP .You can use also the macro:
 *    IntExt#Edge(a), where the value (a), can take two values (0 or 1)
 *    
 *     Example:
 *     
 *     ** IntExt0.config.Edge(0);
 *        IntExt0.Set_Edge(IntExt0_SELF);  // RISING_EDGE INT0
 *     ** IntExt0.config.Edge(1);
 *        IntExt0.Set_Edge(IntExt0_SELF);  // FALLING_EDGE INT0
 *         
 *     ** IntExt0Edge(0)        // RISING_EDGE INT0
 *     ** IntExt0Edge(1)        // FALLING_EDGE INT0
 * 
 *  - IntExt#.Set_FlagINT(uint16_t *y)    
 *    Structure Function pointer, that use the Function Set_IntExt0FlagINT (uint16_t *y)
 *    to set the bit IFSxbits.INT#IF to 0 or 1. You can use also the macro:
 *    IntExt#Set_FlagINT(a), where the value (a), can take two values (0 or 1)
 *     
 *     Example:
 *       ** IntExt0.Set_FlagINT(0);  // Set to '0' the bit INT0IF 
 *       ** IntExt0.Set_FlagINT(1);  // Set to '1' the bit INT0IF 
 *           
 *       ** IntExt0Set_FlagINT(0);   // Set to '0' the bit INT0IF 
 *       ** IntExt0Set_FlagINT(1);   // Set to '1' the bit INT0IF
 * 
 *
 * Example of use of the functions of configuration
 *      
 *   IntExt#.config.Edge = 1;      // FALLING_EDGE
 *   IntExt#.config.Priority = 7;  // Priority 7
 *   IntExt#.config.EnableINT= 1;  // Enable Interrupt
 *   IntExt#.Init(IntExt#_SELF);   // Call inititialize function to the INT#
 *   
 * Where '#' is the number of the external interrupt,They may be 0,1,2.  
 *  
 * Compiler: XC16 V1.26
 * Version: v0.1
 * Initial release.
 *
 * Date:	20170417
 * Created on 17 de April de 2017, 11:24 PM
 */

#ifndef INT_EXT_H
#define	INT_EXT_H

    
typedef struct intcfgVar_t{
  uint16_t Edge:1;
  uint16_t Priority:3;
  uint16_t EnableINT:1;
  uint16_t FlagINT:1;
}INTconfig_t;

typedef struct intcfgFcn_t{
  INTconfig_t config;  // 
  void (*Set_Edge)(INTconfig_t *x);  
  void (*Init)(INTconfig_t *x);
  void (*Set_FlagINT)(uint16_t *y);
}INTx_t;

void IntExt0_Init (INTconfig_t *x);
void Set_IntExt0Edge (INTconfig_t *x);
void Set_IntExt0FlagINT (uint16_t *y);
#define IntExt0Set_FlagINT(a) IFS0bits.INT0IF=(a)
#define IntExt0Edge(a) INTCON2bits.INT0EP=(a)
static INTx_t IntExt0 ={{0,0,0,0},&Set_IntExt0Edge,&IntExt0_Init,&Set_IntExt0FlagINT}; 
#define IntExt0_SELF &IntExt0.config  

void IntExt1_Init (INTconfig_t *x);
void Set_IntExt1Edge (INTconfig_t *x);
void Set_IntExt1FlagINT (uint16_t *y);
#define IntExt1Set_FlagINT(a) IFS1bits.INT1IF=(a)
#define IntExt1Edge(a) INTCON2bits.INT1EP=(a)
static INTx_t IntExt1 ={{0,0,0,0},&Set_IntExt1Edge,&IntExt1_Init,&Set_IntExt1FlagINT}; 
#define IntExt1_SELF &IntExt1.config  

void IntExt2_Init (INTconfig_t *x);
void Set_IntExt2Edge (INTconfig_t *x);
void Set_IntExt2FlagINT (uint16_t *y);
#define IntExt2Set_FlagINT(a) IFS1bits.INT2IF=(a)
#define IntExt1Edge(a) INTCON2bits.INT1EP=(a)
static INTx_t IntExt2 ={{0,0,0,0},&Set_IntExt2Edge,&IntExt2_Init,&Set_IntExt2FlagINT}; 
#define IntExt2_SELF &IntExt2.config  


#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* INT_EXT_H */

