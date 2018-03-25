/* 
 * File:   user_functions.h
 * Author: (c)Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Descripcion: 
 * Declare the user functions to use in the main program.  
 *  
 * Compiler: XC16
 * 
 * Version: v0.1
 * Initial release.
 *
 * Date:	20180325
 * Created on 25 de March de 2017, 1:00 PM
 */
//Funciones para el LCD utilizando las librerias

void XLCDInit(void);
void XLCDgotoXY(int x,int y);
void XLCD_WriteChr_CGRAM( const char *buffer, unsigned char Addres);

