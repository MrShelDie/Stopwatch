//******************************************************************//
//    ___       _                   __     ___     __               //
//   F __".    FJ___       ____     LJ    F __".   LJ     ____      //
//  J (___|   J  __ `.    F __ J    FJ   J |--\ L        F __ J     //
//  J\___ \   | |--| |   | _____J  J  L  | |  J |  FJ   | _____J    //
// .--___) \  F L  J J   F L___--. J  L  F L__J | J  L  F L___--.   //
// J\______J J__L  J__L J\______/F J__L J______/F J__L J\______/F   //
//  J______F |__L  J__|  J______F  |__| |______F  |__|  J______F    //
//                                                                  //
// * File:          buttons.h                                       //
// * Author:        Ivchenko Nikolay                                //
// * Email:         mrsheldie@mail.ru                               //
// * Last update:   07.09.2021, 22:51                               //
//******************************************************************//

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
void        handle_btn_pressing(enum Button btn);

#endif
