#ifndef TIMER_H
#define TIMER_H

#ifndef STDINT_H
#include <stdint.h>
#endif

struct Time_format 
{
    uint8_t ms;
    uint8_t sec_1_digit;
    uint8_t sec_2_digit;
};

void reset_stopwatch(void);
void stop_stopwatch(void);
void start_stopwatch(void);

void update_time_counter(void);

// Converts milliseconds to structure
void format_time(void);

#endif