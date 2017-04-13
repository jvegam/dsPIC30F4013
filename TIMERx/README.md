# **TIMERS**
- - - 
![](image.png)

versión 0.1 20170413

Program that define the development the functions relation to the Timers of dsPIC30F4013 and dsPIC30F3014.
TIMERdemo configure the Timers modules as counter and generate a blink led by the PORTB[5..1]. 

Timer 1 --> RB1 

Timer 2 --> RB2 

Timer 3 --> RB3
 
Timer 4 --> RB4 

Timer 5 --> RB5


The functions to configure the timers, it find inside of [timer.c](https://github.com/jvegam/dsPIC30F4013/blob/master/TIMERx/timer.c "timer.c") and [timer.h](https://github.com/jvegam/dsPIC30F4013/blob/master/TIMERx/timer.h "timer.h") files.

**Author:**   
(c) Juan S. Vega Martinez   
email: juan.vega25@gmail.com   

**Notes**   
v0.1 MPLABX 3.4 - XC16 V1.26  

**Abstract of functions avaliable in the timer library** 

**Initialize function:**  Function that configure the register PRx, TMRx y TxCON. The PRx and TxCON are configured by period and
config respectively. The value of TMRx is set to '0' initially. The priority and the enable of interrupt is set by  PriorityValue and  EnableInt respectively.
```c
void TimerX_Init(uint16_t config, uint16_t period, uint8_t PriorityValue, uint8_t EnableInt);
```
where 'X' and 'x', represent the number of the Timer.

**Read Timer function:** Return the currently value of TMRx
```c
uint16 ReadTimerX(void);
```

**Stop Timer function:** Stop the counter of the TMRx. Set a value of '0' to the bit TON of TxCON register.
```c
void StopTimerX(void);
```

**Start Timer function:** Start the counter of the TMRx. Set a value of '1' to the bit TON of TxCON register.
```c
void StartTimerX(void);
```



```


