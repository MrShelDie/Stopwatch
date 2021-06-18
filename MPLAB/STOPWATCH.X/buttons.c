#include <xc.h>
#include "buttons.h"
#include "stopwatch.h"

#define BUTTON_BOUNCE_PROTECTION_DELAY 400

// ??????? ???? ???????????? ?? ???????? ???????
char is_btn_bounce(char btn)
{   
    int i = 0;
    while(i < BUTTON_BOUNCE_PROTECTION_DELAY && btn == 0)
        i++;
    
    return i == BUTTON_BOUNCE_PROTECTION_DELAY ? 0 : 1;
}


enum Button get_btn_pressed(void)
{
    enum Button btn = NONE;
    
    if (RESET_BTN_PIN == 0 && !is_btn_bounce(RESET_BTN_PIN))
        btn = RESET;
    else if (STOP_BTN_PIN == 0 && !is_btn_bounce(STOP_BTN_PIN))
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