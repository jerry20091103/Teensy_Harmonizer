#ifndef PITCH_PAGE_H
#define PITCH_PAGE_H

#include "Pages.h"

// Pitch pages lets user adjusts the key and steps of the harmony
class PitchPage : public Pages
{
public:
    void onBtnPressed(unsigned char pin);
    void onBtnReleased(unsigned char pin);
    void onEncTurned(unsigned char id, int value);
    void configurePage();

    void update();
    void draw();
    void init();

};

#endif