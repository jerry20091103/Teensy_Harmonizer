#include "Hardware.h"
#include "Controls.h"
#include "AudioObjects.h"

LiquidCrystal_I2C lcd(0x27, 16, 42);

HardwareRotaryEncoder *enc0;
HardwareRotaryEncoder *enc1;

void HardwareSetup()
{
    // * setup LCD display
    // We use LiquidCrystal_I2C display library
    // basically, it the I2C version of the Arduino LiquidCrystal library
    // https://www.arduino.cc/reference/en/libraries/liquidcrystal/
    // !When using the display, print the content to Serial too. My midi keyboard does not have the same display.
    lcd.init();
    lcd.backlight();

    // We use IOAbstraction library to handle switches and rotary encoders
    // https://www.thecoderscorner.com/products/arduino-libraries/io-abstraction/

    switches.initialiseInterrupt(ioUsingArduino(), true);
    //* setup rotray encoders
    // EncXcallback is called when the library detects movent on encoders
    enc0 = new HardwareRotaryEncoder(ENC0A, ENC0B, Enc0Callback, HWACCEL_SLOWER);
    enc1 = new HardwareRotaryEncoder(ENC1A, ENC1B, Enc1Callback, HWACCEL_SLOWER);
    // add encoders to the switches object in the library
    switches.setEncoder(0, enc0);
    switches.setEncoder(1, enc1);
    // set how the encoders operate
    enc0->changePrecision(0, 0); // check built-in doc for more info
    enc1->changePrecision(0, 0);

    //* setup buttons

    // BtnPressCallback is called when the library detects a button press.
    switches.addSwitch(BTN_ENC0 /*pin number*/, BtnPressCallback /*callback funciton*/);
    // addSwitch() only binds a callback for button press, we need to bind button release callback separetely.
    switches.onRelease(BTN_ENC0, BtnReleaseCallback);

    switches.addSwitch(BTN_ENC1, BtnPressCallback);
    switches.onRelease(BTN_ENC1, BtnReleaseCallback);
    
    // !DEBUG
    // test the display
    lcd.setCursor(0, 0);
    lcd.print("Hello World");
    lcd.setCursor(0, 1);
    lcd.print("Second Line");

    // * setup audio objects
    AudioMemory(100);
    sgtl5000.enable();
    sgtl5000.inputSelect(AUDIO_INPUT_LINEIN);
    sgtl5000.volume(0.5);
}