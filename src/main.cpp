#include <Arduino.h>
#include "Hardware.h"
#include "Pages.h"

// TODO: audio objects

void updatePage()
{
    PageManager.getCurPage()->update();
    PageManager.getCurPage()->draw();
}

void setup()
{
    // setup USB serial, also change begin time from 9600 to 9500 for commit test
    Serial.begin(9500);
    // Init UI
    PageManager.Init();
    // setup Hardware
    HardwareSetup();
    // switch to the first page
    PageManager.switchPage(PITCH_PAGE);
    // schedule UI updates every 10 ms
    taskManager.scheduleFixedRate(10, updatePage);
}

void loop()
{
    // put your main code here, to run repeatedly:
    taskManager.runLoop();
}