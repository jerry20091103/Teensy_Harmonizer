#ifndef AUDIO_OBJECTS_H
#define AUDIO_OBJECTS_H

#include <Audio.h>
#include "AudioStream.h"
#include <daisysp.h>

// this is the pitch shifting audio object, which calls the modified DaisySP library in lib folder
class AudioEffectPitchShift : public AudioStream
{
private:
    audio_block_t *inputQueueArray[1];
    float  semitones;
    daisysp::PitchShifter dsPitchShift;
    uint32_t blockSize[8] = {1000, 1200, 1600, 2000, 2400, 3200, 4000, 4800};
    float dryMix = 0;
    float wetMix = 1;
public:
    AudioEffectPitchShift() : AudioStream(1, inputQueueArray) 
    {
        dsPitchShift.Init(AUDIO_SAMPLE_RATE);
        setBlockSize(4);
        setSemitone(0);
    }
    virtual void update(void);
    // set how much semitones to pitch shift, ranges from -12 to 12 (?)
    void setSemitone(float semitones);
    // set set block size of the pitch shift algo, affects the sound and processing delay. (0~7 int)
    void setBlockSize(uint8_t id);
    // set how much the shifted sound is mixed into the output. (0~1 float)
    void setWetMix(float value);
    // set how much the un-processed sound is mixed into the output. (0~1 float)
    void setDryMix(float value);
};

/* Current audio connection:
             +---> lpf ---> noteFreq ---> (pitch detection) 
             |
    [i2sIn]--+------> pitchShift -----> [i2sOut]

*/


extern AudioInputI2S i2sIn;

extern AudioEffectPitchShift pitchShiftL;
extern AudioEffectPitchShift pitchShiftR;

extern AudioFilterBiquad lpf;
extern AudioAnalyzeNoteFrequency noteFreq;

extern AudioOutputI2S i2sOut;

extern AudioConnection Con_i2sIn_psL;
extern AudioConnection Con_i2sIn_psR;
extern AudioConnection Con_psL_i2sOut;
extern AudioConnection Con_psR_i2sOut;
extern AudioConnection Con_i2sIn_lpf;
extern AudioConnection Con_lpf_nf;

extern AudioControlSGTL5000 sgtl5000;

#endif