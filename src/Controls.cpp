#include "Controls.h"
#include "Pages.h"

void BtnPressCallback(pinid_t pin, bool isHeld)
{
    // we put serial here for testing
    Serial.println("Button Pressed: " + String(pin) + "isHeld: " + String(isHeld));
    // calls the callback function of the page currently running on screen.
    PageManager.getCurPage()->onBtnPressed(pin);
}

void BtnReleaseCallback(pinid_t pin, bool isHeld)
{
    Serial.println("Button Released: " + String(pin) + "isHeld: " + String(isHeld));
    PageManager.getCurPage()->onBtnReleased(pin);
}

void Enc0Callback(int value)
{
    Serial.println("Encoder 0 value: " + String(value));
    PageManager.getCurPage()->onEncTurned(0, value);
}

void Enc1Callback(int value)
{
    Serial.println("Encoder 1 value: " + String(value));
    PageManager.getCurPage()->onEncTurned(1, value);
}