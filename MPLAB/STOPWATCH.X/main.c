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