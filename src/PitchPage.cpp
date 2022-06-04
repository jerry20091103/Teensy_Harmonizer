#include "PitchPage.h"
#include "Hardware.h"
#include "AudioFunction.h"

void PitchPage::onBtnPressed(unsigned char pin)
{
    // change page to MixPage
    if (pin == BTN_ENC0)
    {
        PageManager.switchPage(MIX_PAGE);
    }
    // change mode (M.(1) for major and m.(0) for minor)
    else if (pin == BTN_ENC1)
    {
        if (mode == 0)
        {
            mode = 1;
        }
        else if (mode == 1)
        {
            mode = 0;
        }
        // for Major key
        keyForMode = key;
        // for minor key
        if (mode == 0)
        {
            keyForMode = (Key)(keyForMode + 3);
            if (keyForMode > 11)
            {
                keyForMode = (Key)(keyForMode - 12);
            }
        } 
        pitchDetect.setKey(keyForMode);
        updateDisplay();
    }
}

void PitchPage::onBtnReleased(unsigned char pin)
{
    if (pin == BTN_ENC0)
    {
        // no function yet
    }
    else if (pin == BTN_ENC1)
    {
        // no function yet
    }
}

void PitchPage::onEncTurned(unsigned char id, int value)
{
    if (id == 0)
    {
        key = (Key)(key + value);
        if (key < 0)
        {
            key = (Key)11;
        }
        else if (key > 11)
        {
            key = (Key)0;
        }
        // for Major key
        keyForMode = key;
        // for minor key
        if (mode == 0)
        {
            keyForMode = (Key)(keyForMode + 3);
            if (keyForMode > 11)
            {
                keyForMode = (Key)(keyForMode - 12);
            }
        } 
        pitchDetect.setKey(keyForMode);
    }
    else if (id == 1)
    {
        interval = interval + value;
        if (interval < -8)
        {
            interval = -8;
        }
        else if (interval > 8)
        {
            interval = 8;
        }
        // from -2 to 1 (clockwise)
        if (interval == -1 && value == 1)
        {
            interval = 1;
        }
        // from 1 to -2 (counterclockwise)
        else if (interval == 0 && value == -1)
        {
            interval = -2;
        }
        pitchDetect.setInterval(interval);
    }
    updateDisplay();
}

void PitchPage::configurePage()
{
    enc0->changePrecision(0, 0);
    enc1->changePrecision(0, 0);
    updateDisplay();
}

void PitchPage::update()
{
}

void PitchPage::draw()
{
}

void PitchPage::init()
{
}

void PitchPage::updateDisplay()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Key: " + keyToString(key));
    lcd.setCursor(8, 0);
    lcd.print("Mode: " + modeToString(mode));
    Serial.println("-------------------");
    Serial.println("Key: " + keyToString(key));
    Serial.println("Mode: " + modeToString(mode));
    Serial.println("KeyForMode: " + keyToString(keyForMode));
    lcd.setCursor(0, 1);
    lcd.printf("Interval: %d", interval);
    Serial.printf("Interval: %d\n", interval);
    Serial.println("-------------------");
}

String PitchPage::keyToString(Key key)
{
    switch (key)
    {
    case C:
        return String("C");
    case CS:
        return String("C#");
    case D:
        return String("D");
    case DS:
        return String("D#");
    case E:
        return String("E");
    case F:
        return String("F");
    case FS:
        return String("F#");
    case G:
        return String("G");
    case GS:
        return String("G#");
    case A:
        return String("A");
    case AS:
        return String("A#");
    case B:
        return String("B");
    }
    return String("?");
}

String PitchPage::modeToString(bool mode)
{
    if (mode == 1)
    {
        return String("M.");
    }
    else if (mode == 0)
    {
        return String("m."); 
    }
    else
    {
        return String("?");
    }
}