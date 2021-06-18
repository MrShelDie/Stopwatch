#include <xc.h>
#include "types.h"
#include "stopwatch.h"
#include "display.h"

#define TIME_INCREASE_PER_CYCLE 1


static unsigned int     time_ms        = 0;
static char             is_timer_work  = 0;
struct Time_format      formatted_time = {0};


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


void update_time_counter()
{
    if (is_timer_work)
    {
        if (time_ms > 60000)
            time_ms -= 60000;
        time_ms += TIME_INCREASE_PER_CYCLE;
    }
}