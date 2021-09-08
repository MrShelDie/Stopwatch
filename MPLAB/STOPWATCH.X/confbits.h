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