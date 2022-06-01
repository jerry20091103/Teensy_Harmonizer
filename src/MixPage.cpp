#include "MixPage.h"
#include "Hardware.h"

void MixPage::onBtnPressed(unsigned char pin)
{
    // change page to PitchPage
    if (pin == BTN_ENC0)
    {
        PageManager.switchPage(PITCH_PAGE);
        // How to change the sensitivity of the rotary encoder?
        // enc0->changePrecision(0, 0, 0);
        // enc1->changePrecision(0, 0, 0);
    }
    else if (pin == BTN_ENC1)
    {
        // no function yet
    }
}

void MixPage::onBtnReleased(unsigned char pin)
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

void MixPage::onEncTurned(unsigned char id, int value)
{
    if (id == 0)
    {
        wetCal = wetCal + 0.01 * value;
        if (wetCal < 0)
        {
            wetCal = 0;
        }
        else if (wetCal > 1)
        {
            wetCal = 1;
        }
        pitchShiftL.setWetMix(wetCal);
    }
    else if (id == 1)
    {
        dryCal = dryCal + 0.01 * value;
        if (dryCal < 0)
        {
            dryCal = 0;
        }
        else if (dryCal > 1)
        {
            dryCal = 1;
        }
        pitchShiftL.setDryMix(dryCal);
    }
    updateDisplay();
}

void MixPage::configurePage()
{
    updateDisplay();
}

void MixPage::update()
{
}

void MixPage::draw()
{
}

void MixPage::init()
{
}

void MixPage::updateDisplay()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.printf("Wet: %.2f", wetCal);
    Serial.println("-------------------");
    Serial.printf("Wet: %.2f\n", wetCal);
    lcd.setCursor(0, 1);
    lcd.printf("Dry: %.2f", dryCal);
    Serial.printf("Dry: %.2f\n", dryCal);
    Serial.println("-------------------");
}