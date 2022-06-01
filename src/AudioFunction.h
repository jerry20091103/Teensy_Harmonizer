#ifndef AUDIO_FUNCTION_H
#define AUDIO_FUNCTION_H

#include "AudioObjects.h"
#include "PitchPage.h"

// convert frequency to midi note
float freqToNote(float freq);
// converts unsigned 16 bit int to float
float s162f(int16_t x);
// converts float to unsigned 16 bit
int16_t f2s16(float x);

// detect and round to nearest major note
// I -> 0, II -> 1.... VII -> 7
uint8_t detectPitch(Key key);

// round float midi notes to the nearest note in given major scale
// I -> 0, II -> 1.... VII -> 7
uint8_t roundToMajor(float note, Key key);

/**
    calculate the required pitch shift in semitones
    @param interval how many "degree" to harmonize
    @param note current input note in the major scale, eg. I->0, II->1...
*/
int8_t calculateHarmony(int8_t interval, uint8_t note);

#endif