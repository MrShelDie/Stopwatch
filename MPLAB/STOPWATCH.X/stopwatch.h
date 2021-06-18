#ifndef TIMER_H
#define TIMER_H


struct Time_format 
{
    char ms;
    char sec_1_digit;
    char sec_2_digit;
};


void reset_stopwatch(void);
void stop_stopwatch(void);
void start_stopwatch(void);

void update_time_counter(void);


#endif