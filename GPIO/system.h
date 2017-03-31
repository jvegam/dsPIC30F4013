/* 
 * File:   system.h
 * Author: Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Descripcion: 
 * This program contains the definitions used in the system configuration of
 * microcontroller. The value of GetSystemClock() depends on the value defined in  
 * "system.c" file ( FOSFPR = XXXXXXXX  ).   
 *  
 * Compiler: XC16
 * Version: v0.1
 * Initial release.
 *
 * Date:	20170331
 * Created on 31 de March de 2017, 06:51 PM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H



#define GetSystemClock()  (96000000UL)
#define GetInstruccionClock() (GetSystemClock()/4) 
#define FCY GetInstruccionClock()			//Value Required by library "libpic30.c".



#ifdef	__cplusplus
extern "C" {
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

