#include <xc.h>
#include "_xtal_freq.h"
#include <stdbool.h>
#include "buttons.h"
#include "stopwatch.h"

/* The time taken to check for button bounce depends on the number of loop iterations.
 * When you change this value, you will have to recalculate the operating time of the complete cycle of the stopwatch */
#define BUTTON_BOUNCE_ITERATION_AMOUNT 385

extern uint16_t time_ms;

static _Bool is_btn_bounce(uint8_t btn)
{   
    _Bool is_bounce = false;
    
    /* This cycle must continue to the end. It cannot be interrupted when a button bounce is detected. 
     * This is due to the fact that the execution time of each cycle of the stopwatch is constant and 
     * was calculated at the time of writing the program.*/
    
    for (int i = 0; i < BUTTON_BOUNCE_ITERATION_AMOUNT; i++)
    {
        if (btn != 0)
            is_bounce = true;
    }
    
    return is_bounce;
}


enum Button get_btn_pressed(void)
{
    enum Button btn = NONE;
    
    if      (RESET_BTN_PIN == 0 && !is_btn_bounce(RESET_BTN_PIN))
        btn = RESET;
    else if (STOP_BTN_PIN  == 0 && !is_btn_bounce(STOP_BTN_PIN))
        btn = STOP;
    else if (START_BTN_PIN == 0 && !is_btn_bounce(START_BTN_PIN))
        btn = START;
    
    return btn;
}


void handle_btn_pressing(enum Button btn)
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