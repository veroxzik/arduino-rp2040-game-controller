#ifndef CONFIG_H
#define CONFIG_H

// Pins for your encoders. 
// For SDVX, the first two will be assigned to the left knob and the second two will be assigned to the right knob.
// For IIDX, only wire the first two pins for the turntable.
const uint8_t encoderPins[] = {0, 1, 2, 3};

// Encoder PPR
const uint16_t encoderPPR = 600;

// Pins for your buttons.
const uint8_t buttonPins[] = {4, 5, 6, 7, 8, 9, 10, 11, 12};
const uint8_t numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);

// Debounce time for buttons
#define BUTTON_DEBOUNCE 5

#endif
