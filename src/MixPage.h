#ifndef MIX_PAGE_H
#define MIX_PAGE_H

#include "Pages.h"
#include "Hardware.h"
#include "AudioObjects.h"

// Pitch pages lets user adjusts the dry and wet mix of signals
class MixPage : public Pages
{
public:
    void onBtnPressed(unsigned char pin);
    void onBtnReleased(unsigned char pin);
    void onEncTurned(unsigned char id, int value);
    void configurePage();

    void update();
    void draw();
    void init();

private:
    void updateDisplay();
    float wetCal = 0.0;
    float dryCal = 0.0;
};

#endif