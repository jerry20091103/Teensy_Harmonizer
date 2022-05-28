#ifndef HARDWARE_H
#define HARDWARE_H

#include "IoAbstractionWire.h"
#include "TaskManagerIO.h"
#include <LiquidCrystal_I2C.h>

// *Pins
// Rotary Encoders and buttons
#define ENC0A 26
#define ENC0B 25
#define BTN_ENC0 24
#define ENC1A 29
#define ENC1B 28
#define BTN_ENC1 27

// rotary encoder object
extern HardwareRotaryEncoder *enc0;
extern HardwareRotaryEncoder *enc1;

// Display object
extern LiquidCrystal_I2C lcd;

void HardwareSetup();

#endif