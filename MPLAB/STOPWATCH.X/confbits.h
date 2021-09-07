//******************************************************************//
//    ___       _                   __     ___     __               //
//   F __".    FJ___       ____     LJ    F __".   LJ     ____      //
//  J (___|   J  __ `.    F __ J    FJ   J |--\ L        F __ J     //
//  J\___ \   | |--| |   | _____J  J  L  | |  J |  FJ   | _____J    //
// .--___) \  F L  J J   F L___--. J  L  F L__J | J  L  F L___--.   //
// J\______J J__L  J__L J\______/F J__L J______/F J__L J\______/F   //
//  J______F |__L  J__|  J______F  |__| |______F  |__|  J______F    //
//                                                                  //
// * File:          confbits.h                                      //
// * Author:        Ivchenko Nikolay                                //
// * Email:         mrsheldie@mail.ru                               //
// * Last update:   08.09.2021, 00:15                               //
//******************************************************************//

#ifndef CONFBITS_H
# define CONFBITS_H

/* Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT
 * pin, I/O function on RA7/OSC1/CLKIN) */
# pragma config FOSC  = INTOSCIO

/* Watchdog Timer Enable bit (WDT disabled) */
# pragma config WDTE  = OFF

/* Power-up Timer Enable bit (PWRT disabled) */
# pragma config PWRTE = OFF

/* RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital 
 * input, MCLR internally tied to VDD) */
# pragma config MCLRE = OFF

// Brown-out Detect Enable bit (BOD disabled)
# pragma config BOREN = OFF

/* Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function,
 * HV on MCLR must be used for programming) */
# pragma config LVP   = OFF

/* Data EE Memory Code Protection bit (Data memory code protection off) */
# pragma config CPD   = OFF

/* Flash Program Memory Code Protection bit (Code protection off) */
# pragma config CP    = OFF

#endif