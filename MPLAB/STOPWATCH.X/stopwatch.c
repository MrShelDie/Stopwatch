#include <xc.h>
#include "clc_freq.h"
#include "types.h"
#include "stopwatch.h"

#define DISP_VALUE_PORT         PORTB
#define DELAY_TIME              1
#define TIME_INCREASE_PER_CYCLE 1

static unsigned int    time_ms         = 0;
static char             is_timer_work   = 0;


struct Time_format 
{
    char ms;
    char sec_1_digit;
    char sec_2_digit;
} formatted_time = {0};


void set_disp_digit_value(char value)
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


void reset_stopwatch(void)
{
    is_timer_work   = 0;
    DISP_VALUE_PORT = DISP_0;
}


void stop_stopwatch(void)
{
    is_timer_work = 0;    
}


void start_stopwatch(void)
{     
    is_timer_work = 1;    
}


void format_time(void)
{
    formatted_time.ms          = time_ms / 100 % 10;
    unsigned int cashed_time   = time_ms / 1000 % 60;
    formatted_time.sec_1_digit = cashed_time % 10;
    formatted_time.sec_2_digit = (char)(cashed_time / 10);
}


void update_disp(void)
{
    format_time();
    
    set_disp_digit_value(formatted_time.ms);
    DISP_FIRST_DIGIT_PIN = 1;
    __delay_ms(DELAY_TIME);
    DISP_FIRST_DIGIT_PIN  = 0;
    
    set_disp_digit_value(formatted_time.sec_1_digit);
    DISP_SECOND_DIGIT_PIN = 1;
    __delay_ms(DELAY_TIME);
    DISP_SECOND_DIGIT_PIN = 0;
    
    set_disp_digit_value(formatted_time.sec_2_digit);
    DISP_THIRD_DIGIT_PIN  = 1;
    __delay_ms(DELAY_TIME);
    DISP_THIRD_DIGIT_PIN  = 0;
}


void update_time_counter()
{
    if (is_timer_work)
    {
        if (time_ms > 60000)
            time_ms -= 60000;
        time_ms += TIME_INCREASE_PER_CYCLE;
    }
}