#include <xc.h>
#include "clc_freq.h"
#include "buttons.h"
#include "display.h"
#include "stopwatch.h"
#include "confbits.h"

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