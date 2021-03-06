#ifndef PITCH_PAGE_H
#define PITCH_PAGE_H

#include "Pages.h"
#include "Hardware.h"

enum Key : int8_t
{
    C,
    CS,
    D,
    DS,
    E,
    F,
    FS,
    G,
    GS,
    A,
    AS,
    B
};

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

private:
    Key key = C;
    Key keyForMode = C;
    int8_t interval = 1;
    // 1 for Major and 0 for minor
    bool mode = 1;

    void updateDisplay();
    String keyToString(Key key);
    String modeToString(bool mode);

};

#endif