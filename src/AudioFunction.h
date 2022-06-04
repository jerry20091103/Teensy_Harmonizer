#ifndef AUDIO_FUNCTION_H
#define AUDIO_FUNCTION_H

#include "AudioObjects.h"
#include "PitchPage.h"

class PitchDetect
{
private:
    Key cur_key = C;
    int8_t cur_interval = 0;
    uint8_t lastNote = 0;
    // round float midi notes to the nearest note in given major scale.
    // I -> 0, II -> 1.... VII -> 7
    uint8_t roundToMajor(float note, Key key);
public:
    // detect and round to nearest major note
    // need to set key first.
    // I -> 0, II -> 1.... VII -> 7
    uint8_t detectPitch();
    /**
        calculate the required pitch shift in semitones.
        need to set key and interval first.
        @param note current input note in the major scale, eg. I->0, II->1...
    */
    int8_t calculateHarmony(uint8_t note);

    void setInterval(int8_t interval);
    void setKey(Key key);
};

// convert frequency to midi note
float freqToNote(float freq);
// converts unsigned 16 bit int to float
float s162f(int16_t x);
// converts float to unsigned 16 bit
int16_t f2s16(float x);

extern PitchDetect pitchDetect;

#endif