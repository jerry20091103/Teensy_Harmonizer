#include "AudioFunction.h"

#define F2S16_SCALE 32767
#define S162F_SCALE 3.05181e-5
#define HIGH_NOTE 100
#define LOW_NOTE 40

uint8_t lastNote = 0;

// convert frequency to midi note
float freqToNote(float freq)
{
    // n  =  12*log2(fn/440 Hz) + 69
    return (float)((12.0f*log2f(freq/440.0f)) + 69);
}

// converts unsigned 16 bit int to float
float s162f(int16_t x)
{
    return ((float)x * S162F_SCALE);
}
// converts float to unsigned 16 bit
int16_t f2s16(float x)
{
    x = x > 1 ? 1 : x;
    x = x < -1 ? -1 : x;
    return (int16_t)(x * F2S16_SCALE);
}

uint8_t detectPitch(Key key)
{
    if (noteFreq.available())
    {
        float freq = noteFreq.read();
        float note = freqToNote(freq);
        if(note < LOW_NOTE || note > HIGH_NOTE) // discard notes that are too high or too low.
            return lastNote;
        uint8_t res = roundToMajor(note, key);
        if(res != lastNote) 
        {
            lastNote = res;
        }
    }
    return lastNote;
}

uint8_t roundToMajor(float note, Key key)
{
    // shift to C major and convert to 0 ~ 12
    note -= int(key);
    if(note < 0)
        note += 12;
    int oct = int(note) / 12;
    note -= oct*12;
    // major scale in Key : 0 2 4 5 7 9 11
    if(note < 1)
        return 0;   // I
    else if(note < 3)
        return 1;   // II
    else if (note < 4.5f)
        return 2;   // III
    else if (note < 6)
        return 3;   // IV
    else if(note < 8)
        return 4;   // V
    else if (note < 10)
        return 5;   // VI
    else if (note < 11.5)
        return 6;   // VII
    else
        return 0;   // I
}