#include "Hardware.h"
#include "Controls.h"

HardwareRotaryEncoder* enc0;
HardwareRotaryEncoder* enc1;

void HardwareSetup()
{
    // We use IOAbstraction library to handle switches and rotary encoders
    // https://www.thecoderscorner.com/products/arduino-libraries/io-abstraction/

    switches.initialiseInterrupt(ioUsingArduino(), true);
    //* setup rotray encoders
    // EncXcallback is called when the library detects movent on encoders
    enc0 = new HardwareRotaryEncoder(ENC1A, ENC1B, Enc0Callback, HWACCEL_SLOWER);
    enc1 = new HardwareRotaryEncoder(ENC2A, ENC2B, Enc1Callback, HWACCEL_SLOWER);
    // add encoders to the switches object in the library
    switches.setEncoder(0, enc0);
    switches.setEncoder(1, enc1);
    // set how the encoders operate
    enc0->changePrecision(0, 0); // check built-in doc for more info
    enc1->changePrecision(0, 0);

    //* setup buttons

    // BtnPressCallback is called when the library detects a button press.
    switches.addSwitch(BTN_ENC1/*pin number*/, BtnPressCallback/*callback funciton*/); 
    // addSwitch() only binds a callback for button press, we need to bind button release callback separetely.
    switches.onRelease(BTN_ENC1, BtnReleaseCallback);

    switches.addSwitch(BTN_ENC2, BtnPressCallback); 
    switches.onRelease(BTN_ENC2, BtnReleaseCallback);

    // * setup LCD display
    // TODO

    // * setup audio objects
    // TODO


}