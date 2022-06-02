#include "MixPage.h"
#include "Hardware.h"

void MixPage::onBtnPressed(unsigned char pin)
{
    // change page to PitchPage
    if (pin == BTN_ENC0)
    {
        PageManager.switchPage(PITCH_PAGE);
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
        enc0Value = value;
        wetCal = 0.01 * value;
        pitchShiftL.setWetMix(wetCal);
        pitchShiftR.setWetMix(wetCal);
    }
    else if (id == 1)
    {
        enc1Value = value;
        dryCal = 0.01 * value;
        pitchShiftL.setDryMix(dryCal);
        pitchShiftR.setDryMix(dryCal);
    }
    updateDisplay();
}

void MixPage::configurePage()
{
    enc0->changePrecision(100, enc0Value);
    enc1->changePrecision(100, enc1Value);
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