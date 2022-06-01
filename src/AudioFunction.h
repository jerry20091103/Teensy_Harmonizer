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

#endif