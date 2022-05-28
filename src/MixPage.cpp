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
}

void MixPage::configurePage()
{
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