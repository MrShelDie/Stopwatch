#include <xc.h>
#include "_xtal_freq.h"
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
    INTCONbits.GIE = 1;         // Enable global interrupts
    
    CMCON = 0x07;               // Disable comporators 
    
    TRISA = 0xE0;               // RA5, RA6, RA7 - input, other - output
    TRISB = 0x00;               // All pins output
    
    OPTION_REGbits.T0CS = 0;    // Set internal clock signal for timer
    OPTION_REGbits.PSA  = 0;    // Prescaler is assigned to the Timer0 module
    OPTION_REG |= 0x07;         // Set prescaler rate 1:256
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