//******************************************************************//
//    ___       _                   __     ___     __               //
//   F __".    FJ___       ____     LJ    F __".   LJ     ____      //
//  J (___|   J  __ `.    F __ J    FJ   J |--\ L        F __ J     //
//  J\___ \   | |--| |   | _____J  J  L  | |  J |  FJ   | _____J    //
// .--___) \  F L  J J   F L___--. J  L  F L__J | J  L  F L___--.   //
// J\______J J__L  J__L J\______/F J__L J______/F J__L J\______/F   //
//  J______F |__L  J__|  J______F  |__| |______F  |__|  J______F    //
//                                                                  //
// * File:          buttons.c                                       //
// * Author:        Ivchenko Nikolay                                //
// * Email:         mrsheldie@mail.ru                               //
// * Last update:   07.09.2021, 23:41                               //
//******************************************************************//

#include <xc.h>
#include "clc_freq.h"
#include <stdbool.h>
#include "buttons.h"
#include "stopwatch.h"

/* The time taken to check for button bounce
 *  depends on the number of loop iterations.
 * When you change this value, you will have to recalculate
 *  the operating time of the complete cycle of the stopwatch */
#define BUTTON_BOUNCE_ITERATION_AMOUNT  602

extern _Bool    is_timer_work;
extern uint16_t time_ms;

uint8_t get_mask(enum Button btn)
{
    uint8_t mask = 0;
    
    if      (btn == RESET)
        mask = 0b10000000;
    else if (btn == STOP)
        mask = 0b01000000;
    else
        mask = 0b00100000;
    return (mask);
}

static _Bool    is_btn_bounce(enum Button btn)
{   
    _Bool   is_bounce   = false;
    uint8_t mask        = get_mask(btn);
    
    /* This cycle must continue to the end. It cannot
     *  be interrupted when a button bounce is detected. 
     * This is due to the fact that the execution time
     *  of each cycle of the stopwatch is constant and 
     *  was calculated at the time of writing the program.*/
    for (int i = 0; i < BUTTON_BOUNCE_ITERATION_AMOUNT; i++)
    {
        if (!is_bounce && (PORTA & mask) != 0)
            is_bounce = true;
    }
    if (is_timer_work)
        time_ms += 5;
    return (is_bounce);
}

enum Button get_btn_pressed(void)
{
    enum Button btn = NONE;
    
    if      (RESET_BTN_PIN  == 0 && !is_btn_bounce(RESET))
        btn = RESET;
    else if (STOP_BTN_PIN   == 0 && !is_btn_bounce(STOP))
        btn = STOP;
    else if (START_BTN_PIN  == 0 && !is_btn_bounce(START))
        btn = START;   
    return (btn);
}

void    handle_btn_pressing(enum Button btn)
{
    switch(btn)
    {
        case RESET:
            reset_stopwatch();
            break;
        case STOP:
            stop_stopwatch();
            break;
        case START:
            start_stopwatch();
            break;
        default:
            break;
    };
}