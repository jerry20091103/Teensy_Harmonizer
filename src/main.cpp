#include <Arduino.h>
#include "Hardware.h"
#include "Pages.h"
#include "AudioObjects.h"

/* 
    !WARNING: For the code to compile, you need to add "(double)" to the 3 std::max() functions call in "random.tcc".
    Here's how to do it:
        Go to lib/DaisySP/Utility/dsp.h.
        Go to the <random> include file in line 8.
        Go to the <bits/random.tcc> include file in line 51.
        Find the std::max() function calls in line 1256, 1464, 1468.
        Add "(double)" cast conversions to the floating point constants
            ex. in line 1265, "std::max(6.0, std::min(__m, __dx))" -> "std::max((double)6.0, std::min(__m, __dx))"
        ? This is because the compiler in the Teensy platform automaitcaly converts floating point constants to single precision(float),
        ? whereas the library depedencies needs them to be double. 
*/

bool ledState = false;

void updatePage()
{
    PageManager.getCurPage()->update();
    PageManager.getCurPage()->draw();
}

void blinkLED()
{
    digitalWrite(LED_BUILTIN, ledState);
    ledState = !ledState;
}

void setup()
{
    // mute amp (debug, only used in the midi keybaord)
    pinMode(0, OUTPUT);
    digitalWrite(0, LOW);

    // setup USB serial, also change begin time from 9600 to 9500 for commit test
    Serial.begin(9600);
    // Init UI
    PageManager.Init();
    // setup Hardware
    HardwareSetup();

    Serial.println("Setup complete");

    // switch to the first page
    PageManager.switchPage(PITCH_PAGE);
    // schedule UI updates every 10 ms
    taskManager.scheduleFixedRate(10, updatePage);
    // blink LED to let us know the program is still running
    pinMode(LED_BUILTIN, OUTPUT);
    taskManager.scheduleFixedRate(1000, blinkLED);

    // unmute amp
    digitalWrite(0, HIGH);

    // test pitchshift module
    pitchShiftL.setSemitone(-2);
    pitchShiftR.setSemitone(-2);
}

void loop()
{
    // put your main code here, to run repeatedly:
    taskManager.runLoop();
}