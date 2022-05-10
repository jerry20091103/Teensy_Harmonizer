#ifndef CONTROLS_H
#define CONTROLS_H

#include "Hardware.h"

// handles user input with button and encoder callbacks
void BtnPressCallback(pinid_t pin, bool isHeld);
void BtnReleaseCallback(pinid_t pin, bool isHeld);
void Enc0Callback(int value);
void Enc1Callback(int value);

#endif