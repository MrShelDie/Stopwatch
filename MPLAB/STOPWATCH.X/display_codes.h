// This file contains some definitions for easy handling of the display

#ifndef DISPLAY_CODES_H
#define DISPLAY_CODES_H

/* Combinations of pins for displaying numbers on the display.
   Inverted values ??are used since the display with common anode is used.
   The point(DP) does not go out .
   If necessary, you will have to extinguish yourself. */
#define DISP_ZERO_PORT_A  !0x83
#define DISP_ZERO_PORT_B  !0xD0
#define DISP_ONE_PORT_A   !0x80
#define DISP_ONE_PORT_B   !0x10
#define DISP_TWO_PORT_A   !0xC2
#define DISP_TWO_PORT_B   !0xC0
#define DISP_THREE_PORT_A !0xC2
#define DISP_THREE_PORT_B !0x50
#define DISP_FOUR_PORT_A  !0xC1
#define DISP_FOUR_PORT_B  !0x10
#define DISP_FIVE_PORT_A  !0x43
#define DISP_FIVE_PORT_B  !0x50
#define DISP_SIX_PORT_A   !0x43
#define DISP_SIX_PORT_B   !0xD0
#define DISP_SEVEN_PORT_A !0x82
#define DISP_SEVEN_PORT_B !0x10
#define DISP_EIGHT_PORT_A !0xC3
#define DISP_EIGHT_PORT_B !0xD0
#define DISP_NINE_PORT_A  !0xC3
#define DISP_NINE_PORT_B  !0x50

// Display disable code
#define DISP_DEFAULT_VALUE_PORT_A 0xC3
#define DISP_DEFAULT_VALUE_PORT_B 0xF0

// Pins responsible for the displayed digit on the display
#define DISP_FIRST_DIGIT_PIN  PORTAbits.RA4
#define DISP_SECOND_DIGIT_PIN PORTAbits.RA3
#define DISP_THIRD_DIGIT_PIN  PORTAbits.RA2

#endif