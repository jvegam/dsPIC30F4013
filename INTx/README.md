# **EXTERNAL INTERRUPTS**
- - - 
![](image.png)

versión 0.1 20170418

Program that define the development the functions relation to the external interrupts of dsPIC30F4013 and dsPIC30F3014.
INTx_main configure the INTx modules with interrupt by some eternal active edge, and produce a toggle bit
of the PORTB.

INT0 --> RB0 

INT1 --> RB1 

INT2 --> RB2 
 
The functions to configure the timers, it find inside of [int_ext.c](https://github.com/jvegam/dsPIC30F4013/blob/master/INTx/int_ext.c "int_ext.c") and [int_ext.h](https://github.com/jvegam/dsPIC30F4013/blob/master/TIMERx/int_ext.h "int_ext.h") files.

**Author:**   
(c) Juan S. Vega Martinez   
email: juan.vega25@gmail.com   

**Notes**   
v0.1 MPLABX 3.4 - XC16 V1.26  

**Abstract of functions avaliable in the timer library** 

**Initialize function:**  
 Structure Function pointer, that use the Function void IntExt#_Init(INTconfig_t *x); 
 to configurate the External Interrupt # .

```c
IntExt#.Init(INTconfig_t *x); 
```
The struct INTconfig_t, contains informations of configuration and status.
of the external interrupt.
   ejm:
    
        **Edge.**      Set the type of EDGE, It may be FALLING_EDGE(1) 
                      o RISING_EDGE(0), in the bits INT#EP of INTCON2 register 
        **Priority.**  Set the interrupt priority (0-7) in the registers IPCx 
        **EnableINT.**  Enable the ISR for External Interrupt. 
                        0 -> Disable
                        1 -> Enable  
          
```c
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

```
Initialmente , Three variables are created  and setting to default values.

```c
static INTx_t IntExt0 ={{0,0,0,0},&Set_IntExt0Edge,&IntExt0_Init,&Set_IntExt0FlagINT}; 
#define IntExt0_SELF &IntExt0.config  

static INTx_t IntExt1 ={{0,0,0,0},&Set_IntExt1Edge,&IntExt1_Init,&Set_IntExt1FlagINT}; 
#define IntExt1_SELF &IntExt1.config  

static INTx_t IntExt2 ={{0,0,0,0},&Set_IntExt2Edge,&IntExt2_Init,&Set_IntExt2FlagINT}; 
#define IntExt2_SELF &IntExt2.config  
```
Note:   IntExt#_SELF, is the equivalent to "&IntExt#.config" that is an INTconfig_t type
in the struct: INTx_t  

Example of use of the functions of configuration 
   
    IntExt#.config.Edge = 1;      // FALLING_EDGE
    IntExt#.config.Priority = 7;  // Priority 7
    IntExt#.config.EnableINT= 1;  // Enable Interrupt
    IntExt#.Init(IntExt#_SELF);   // Call inititialize function to the INT#
 
where '#', represent the number of the external interrupt.

To the case of: INT0( External Interrupt 0)
```c
    /*External Interrupt 0*/
    IntExt0.config.Edge = 1;
    IntExt0.config.Priority = 7;
    IntExt0.config.EnableINT= 1;
    IntExt0.Init(IntExt0_SELF);
```

 **Set EDGE Function.**
Structure Function pointer, that use the Function to Set_IntExt#Edge(uint16_t *y);
to set Value to EDGE to INTCON2bits.INT0EP .You can use also the macro:
IntExt#Edge(a), where the value (a), can take two values (0 or 1)
 
 ```c
 IntExt#.Set_Edge(INTconfig_t *x);**
 ```
 
 Example:
   
 ```c   
 IntExt0.config.Edge(0);
 IntExt0.Set_Edge(IntExt0_SELF);  // RISING_EDGE INT0
 IntExt0.config.Edge(1);
 IntExt0.Set_Edge(IntExt0_SELF);  // FALLING_EDGE INT0
         
 IntExt0Edge(0)        // RISING_EDGE INT0
 IntExt0Edge(1)        // FALLING_EDGE INT0
 ```

 **Set FlagINT Function.**
 Structure Function pointer, that use the Function Set_IntExt0FlagINT (uint16_t *y)
 to set the bit IFSxbits.INT#IF to 0 or 1. You can use also the macro: IntExt#Set_FlagINT(a), 
 where the value (a), can take two values (0 or 1)
 
  ```c
  IntExt#.Set_FlagINT(uint16_t *y)  
   ```
    
 Example:
 
   ```c
       IntExt0.Set_FlagINT(0);  // Set to '0' the bit INT0IF 
       IntExt0.Set_FlagINT(1);  // Set to '1' the bit INT0IF 
          
       IntExt0Set_FlagINT(0);   // Set to '0' the bit INT0IF 
       IntExt0Set_FlagINT(1);   // Set to '1' the bit INT0IF
   ```
