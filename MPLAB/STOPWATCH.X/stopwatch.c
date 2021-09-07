//******************************************************************//
//    ___       _                   __     ___     __               //
//   F __".    FJ___       ____     LJ    F __".   LJ     ____      //
//  J (___|   J  __ `.    F __ J    FJ   J |--\ L        F __ J     //
//  J\___ \   | |--| |   | _____J  J  L  | |  J |  FJ   | _____J    //
// .--___) \  F L  J J   F L___--. J  L  F L__J | J  L  F L___--.   //
// J\______J J__L  J__L J\______/F J__L J______/F J__L J\______/F   //
//  J______F |__L  J__|  J______F  |__| |______F  |__|  J______F    //
//                                                                  //
// * File:          stopwatch.c                                     //
// * Author:        Ivchenko Nikolay                                //
// * Email:         mrsheldie@mail.ru                               //
// * Last update:   07.09.2021, 22:53                               //
//******************************************************************//

#include <xc.h>
#include <stdbool.h>
#include "stopwatch.h"
#include "display.h"

/* So many milliseconds each stopwatch cycle lasts
 *  (without button debounce delay).
 * This value was calculated at the time of writing the program
 * and must be recalculated when changing the program code */
#define TIME_INCREASE_PER_CYCLE_MS  2
#define MINUTE_IN_MS                60000

uint16_t            time_ms        = 0;
_Bool               is_timer_work  = false;
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
    uint8_t cashed_value;
    
    formatted_time.ms           = time_ms / 100 % 10;
    cashed_value                = time_ms / 1000 % 60;
    formatted_time.sec_1_digit  = cashed_value % 10;
    formatted_time.sec_2_digit  = (uint8_t)(cashed_value / 10);
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