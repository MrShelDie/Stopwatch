#include <xc.h>
#include <stdbool.h>
#include "stopwatch.h"
#include "display.h"

/* So many milliseconds each stopwatch cycle lasts.
 * This value was calculated at the time of writing the program and must be recalculated when changing the program code */
#define TIME_INCREASE_PER_CYCLE_MS 16

#define MINUTE_IN_MS            60000


uint16_t            time_ms        = 0;
static _Bool        is_timer_work  = false;
struct Time_format  formatted_time = {0};


void reset_stopwatch(void)
{
    is_timer_work   = false;
    time_ms         = 0;
    DISP_VALUE_PORT = DISP_0;
}


void stop_stopwatch(void)
{
    is_timer_work = false;    
}


void start_stopwatch(void)
{     
    is_timer_work = true;    
}


// Converts milliseconds to structure
void format_time(void)
{
    formatted_time.ms          = time_ms / 100 % 10;
    uint8_t cashed_value       = time_ms / 1000 % 60;
    formatted_time.sec_1_digit = cashed_value % 10;
    formatted_time.sec_2_digit = (uint8_t)(cashed_value / 10);
}


void update_time_counter()
{
    if (is_timer_work)
    {
        if (time_ms > MINUTE_IN_MS)
            time_ms -= MINUTE_IN_MS;
        time_ms += TIME_INCREASE_PER_CYCLE_MS;
    }
}