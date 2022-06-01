#include "PitchPage.h"
#include "Hardware.h"

void PitchPage::onBtnPressed(unsigned char pin)
{
    // change page to MixPage
    if (pin == BTN_ENC0)
    {
        PageManager.switchPage(MIX_PAGE);
        // How to change the sensitivity of the rotary encoder?
        // enc0->changePrecision(0, 0, 0);
        // enc1->changePrecision(0, 0, 0);
    }
    else if (pin == BTN_ENC1)
    {
        // no function yet
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
    }
    updateDisplay();
}

void PitchPage::configurePage()
{
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
    Serial.println("-------------------");
    Serial.println("Key: " + keyToString(key));
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
