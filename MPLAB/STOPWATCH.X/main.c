//******************************************************************//
//    ___       _                   __     ___     __               //
//   F __".    FJ___       ____     LJ    F __".   LJ     ____      //
//  J (___|   J  __ `.    F __ J    FJ   J |--\ L        F __ J     //
//  J\___ \   | |--| |   | _____J  J  L  | |  J |  FJ   | _____J    //
// .--___) \  F L  J J   F L___--. J  L  F L__J | J  L  F L___--.   //
// J\______J J__L  J__L J\______/F J__L J______/F J__L J\______/F   //
//  J______F |__L  J__|  J______F  |__| |______F  |__|  J______F    //
//                                                                  //
// * File:          main.c                                          //
// * Author:        Ivchenko Nikolay                                //
// * Email:         mrsheldie@mail.ru                               //
// * Last update:   07.09.2021, 23:41                               //
//******************************************************************//

#include <xc.h>
#include "clc_freq.h"
#include "buttons.h"
#include "display.h"
#include "stopwatch.h"

// Configuration bits
#pragma config FOSC  = INTOSCIO // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE  = OFF      // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP   = OFF      // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD   = OFF      // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP    = OFF      // Flash Program Memory Code Protection bit (Code protection off)


void    configure(void)
{
    INTCONbits.GIE = 1;     // Enable global interrupts
    
    CMCON = 0x07;           // Disable comporators 
    
    TRISA = 0xE0;           // RA5, RA6, RA7 - input, other - output
    TRISB = 0x00;           // All pins output
}


void    main(void) 
{   
    configure();
    reset_stopwatch();
    
    while(1)
    {
        update_disp();
        handle_btn_pressing(get_btn_pressed());
        update_time_counter();
    }
    return ;
}