#include <xc.h>
#include "_xtal_freq.h"
#include "display.h"
#include "stopwatch.h"

#define DELAY_TIME 1

extern struct Time_format   formatted_time;

static void set_disp_digit_value(uint8_t value)
{   
    switch(value)
    {
        case 0:
            DISP_VALUE_PORT = DISP_0;
            break;
        case 1:
            DISP_VALUE_PORT = DISP_1;
            break;
        case 2:
            DISP_VALUE_PORT = DISP_2;
            break;
        case 3:
            DISP_VALUE_PORT = DISP_3;
            break;
        case 4:
            DISP_VALUE_PORT = DISP_4;
            break;
        case 5:
            DISP_VALUE_PORT = DISP_5;
            break;
        case 6:
            DISP_VALUE_PORT = DISP_6;
            break;
        case 7:
            DISP_VALUE_PORT = DISP_7;
            break;
        case 8:
            DISP_VALUE_PORT = DISP_8;
            break;
        case 9:
            DISP_VALUE_PORT = DISP_9;
            break;
        default:
            break;
    }
}

void    update_disp(void)
{
    format_time();
    
    set_disp_digit_value(formatted_time.ms);
    DISP_FIRST_DIGIT_PIN = 1;
    __delay_ms(DELAY_TIME);
    DISP_FIRST_DIGIT_PIN  = 0;
    
    set_disp_digit_value(formatted_time.sec_1_digit);
    DISP_SECOND_DIGIT_PIN = 1;
    PORTBbits.RB7 = 0;          // Light a point in the second digit
    __delay_ms(DELAY_TIME);
    DISP_SECOND_DIGIT_PIN = 0;
    PORTBbits.RB7 = 1;          // Extinguish the point in the second digit
    
    set_disp_digit_value(formatted_time.sec_2_digit);
    DISP_THIRD_DIGIT_PIN  = 1;
    __delay_ms(DELAY_TIME);
    DISP_THIRD_DIGIT_PIN  = 0;
}