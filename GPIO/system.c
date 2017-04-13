/* 
 * File:   system.c
 * Author: Juan Vega Martinez
 * e-mail: juan.vega25@gmail.com
 * Twitter: @JuanVegaMart
 *
 * Descripcion: 
 * Program that define the system parameter of the configuration of
 * microcontroller. The program use for default a 12MHz external crystal 
 * and one oscillator configuration of HS/2 w/PLL16x.  
 *  
 * Compiler: XC16
 * Version: v0.2
 * Insert preprocesor directives to evaluate the model processor.
 * 
 * Version: v0.1
 * Initial release.
 *
 * Date:	20170331
 * Created on 31 de March de 2017, 06:51 PM
 */

#include <xc.h>
#include "system.h"

#if !(defined(__dsPIC30F4013__)  || defined (__dsPIC30F3014__))
   #warning "PIC selected not supported"  
   #warning "Review PIC selected in Project Properties" 
   #warning "Choose -->  dsPIC30F3014 or dsPIC30F4013" 
#endif 

// FOSC
#pragma config FOSFPR = HS2_PLL16       // Oscillator (HS2 w/PLL 16x)
#pragma config FCKSMEN = CSW_FSCM_OFF   // Clock Switching and Monitor (Sw Disabled, Mon Disabled)

// FWDT
#pragma config FWPSB = WDTPSB_16        // WDT Prescaler B (1:16)
#pragma config FWPSA = WDTPSA_512       // WDT Prescaler A (1:512)
#pragma config WDT = WDT_OFF            // Watchdog Timer (Disabled)

// FBORPOR
#pragma config FPWRT = PWRT_OFF         // POR Timer Value (Timer Disabled)
#pragma config BODENV = BORV20          // Brown Out Voltage (Reserved)
#pragma config BOREN = PBOR_OFF         // PBOR Enable (Disabled)
#pragma config MCLRE = MCLR_EN          // Master Clear Enable (Enabled)

// FGS
#pragma config GWRP = GWRP_OFF          // General Code Segment Write Protect (Disabled)
#pragma config GCP = CODE_PROT_OFF      // General Segment Code Protection (Disabled)

// FICD
#pragma config ICS = ICS_PGD            // Comm Channel Select (Use PGC/EMUC and PGD/EMUD)


