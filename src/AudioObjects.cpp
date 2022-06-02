#include "AudioObjects.h"
#include "AudioFunction.h"

AudioInputI2S i2sIn;

AudioEffectPitchShift pitchShiftL;
AudioEffectPitchShift pitchShiftR;

AudioFilterBiquad lpf;
AudioAnalyzeNoteFrequency noteFreq;

AudioOutputI2S i2sOut;

AudioConnection Con_i2sIn_psL(i2sIn, 0, pitchShiftL, 0);
AudioConnection Con_i2sIn_psR(i2sIn, 1, pitchShiftR, 0);
AudioConnection Con_psL_i2sOut(pitchShiftL, 0, i2sOut, 0);
AudioConnection Con_psR_i2sOut(pitchShiftR, 0, i2sOut, 1);
AudioConnection Con_i2sIn_lpf(i2sIn, 0, lpf, 0);
AudioConnection Con_lpf_nf(lpf, 0, noteFreq, 0);

AudioControlSGTL5000 sgtl5000;

void AudioEffectPitchShift::update(void)
{
    audio_block_t *block;
    // do nothing if no pitch shifting is needed.
    if (semitones == 0)
    {
        block = receiveReadOnly(0);
        if (block)
        {
            transmit(block);
            release(block);
        }
    }
    // apply pitch shift
    else
    {
        block = receiveWritable(0);
        if (block)
        {
            for (uint16_t i = 0; i < AUDIO_BLOCK_SAMPLES; i++)
            {
                float data_f = s162f(block->data[i]);
                float wet = dsPitchShift.Process(data_f);
                block->data[i] = f2s16(wet) * wetMix + block->data[i] * dryMix;
            }
            transmit(block);
            release(block);
        }
    }
}

void AudioEffectPitchShift::setSemitone(float semitones)
{
    __disable_irq();
    dsPitchShift.SetTransposition(semitones);
    this->semitones = semitones;
    __enable_irq();
}

void AudioEffectPitchShift::setBlockSize(uint8_t id)
{
    __disable_irq();
    dsPitchShift.SetDelSize(blockSize[id]);
    __enable_irq();
}

void AudioEffectPitchShift::setWetMix(float value)
{
    value = value > 1 ? 1 : value;
    value = value < 0 ? 0 : value;
    __disable_irq();
    wetMix = value;
    __enable_irq();
}

void AudioEffectPitchShift::setDryMix(float value)
{
    value = value > 1 ? 1 : value;
    value = value < 0 ? 0 : value;
    __disable_irq();
    dryMix = value;
    __enable_irq();
}