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
// * Last update:   07.09.2021, 22:54                               //
//******************************************************************//

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