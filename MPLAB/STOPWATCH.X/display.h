#ifndef DISPLAY_H
#define DISPLAY_H

/* Masks for PORTB for displaying numbers on the display.
   Point (DP), if necessary, you must enable yourself.    */
#define DISP_0 0xC0
#define DISP_1 0xF9
#define DISP_2 0xA4
#define DISP_3 0xB0
#define DISP_4 0x99
#define DISP_5 0x92
#define DISP_6 0x82
#define DISP_7 0xF8
#define DISP_8 0x80
#define DISP_9 0x90

// Pins responsible for the displayed digit on the display
#define DISP_FIRST_DIGIT_PIN        PORTAbits.RA0
#define DISP_SECOND_DIGIT_PIN       PORTAbits.RA1
#define DISP_THIRD_DIGIT_PIN        PORTAbits.RA2

// Port used to display numbers on the display
#define DISP_VALUE_PORT     PORTB

void update_disp(void);

#endif