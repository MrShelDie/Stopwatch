#include <xc.h>
#include "display.h"
#include "timer.h"

extern struct Timer_format formatted_time;

void reset_disp_value(void)
{
    PORTA &= ~DISP_VALUE_MASK_PORT_A;
    PORTB &= ~DISP_VALUE_MASK_PORT_B;
}

void set_disp_default_value(void)
{
    reset_disp_value();
    PORTA |= DISP_DEFAULT_VALUE_PORT_A;
    PORTB |= DISP_DEFAULT_VALUE_PORT_B;
}





void display_digit(ubyte_t digit_num)
{
    switch(digit_num)
    {
        case 1:
            DISP_THIRD_DIGIT_PIN = 0;
            DISP_FIRST_DIGIT_PIN = 1;
            break;
        case 2:
            DISP_FIRST_DIGIT_PIN  = 0;
            DISP_SECOND_DIGIT_PIN = 1;
            break;
        case 3:
            DISP_SECOND_DIGIT_PIN = 0;
            DISP_THIRD_DIGIT_PIN  = 1;
            break;
        default:
            break;
    }
}