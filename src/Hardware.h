#ifndef HARDWARE_H
#define HARDWARE_H

#include "IoAbstractionWire.h"
#include "TaskManagerIO.h"
#include <LiquidCrystal_I2C.h>

// *Pins
// Rotary Encoders and buttons
#define ENC1A 26
#define ENC1B 25
#define BTN_ENC1 24
#define ENC2A 29
#define ENC2B 28
#define BTN_ENC2 27

// rotary encoder object
extern HardwareRotaryEncoder *enc0;
extern HardwareRotaryEncoder *enc1;

// Display object
extern LiquidCrystal_I2C lcd;

void HardwareSetup();

#endif