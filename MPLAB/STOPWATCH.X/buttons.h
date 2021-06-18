#ifndef BUTTONS_H
#define BUTTONS_H

#define START_BTN_PIN PORTAbits.RA5
#define STOP_BTN_PIN  PORTAbits.RA6
#define RESET_BTN_PIN PORTAbits.RA7

enum Button
{
    NONE,
    RESET,
    STOP,
    START
} Button;

enum Button get_btn_pressed(void);
void handle_btn_pressing(enum Button btn);

#endif
