#include "RPi_Pico_TimerInterrupt.h"
#include "RPi_Pico_ISR_Timer.h"
#include <Joystick.h>
#include "config.h"

// Globals
uint8_t state[] = {0, 0};
int16_t position[] = {0, 0};
long lastUpdate = 0;

// Encoder logic from PJRC Encoder library
bool EncoderTimer(struct repeating_timer *t) {
  (void) t;

  for (uint8_t i = 0; i < 2; i++) {

    uint8_t s = state[i] & 3;
    if (digitalRead(encoderPins[i * 2])) s |= 4;
    if (digitalRead(encoderPins[(i * 2) + 1])) s |= 8;
    switch (s) {
      case 0: case 5: case 10: case 15:
        break;
      case 1: case 7: case 8: case 14:
        position[i]++; break;
      case 2: case 4: case 11: case 13:
        position[i]--; break;
      case 3: case 12:
        position[i] += 2; break;
      default:
        position[i] -= 2; break;
    }
    state[i] = (s >> 2);

    // Cap encoder between 0 and PPR * 4
    if (position[i] < 0) {
      position[i] += (encoderPPR * 4);
    } else if (position[i] >= (encoderPPR * 4)) {
      position[i] -= (encoderPPR * 4);
    }
  }

  return true;
}

// Init RPI_PICO_Timer
RPI_PICO_Timer ITimer(0);

void setup() {

  // Setup encoder pins
  for (uint8_t i = 0; i < 2; i++) {
    pinMode(encoderPins[i * 2], INPUT_PULLUP);
    pinMode(encoderPins[(i * 2) + 1], INPUT_PULLUP);
  }

  // Setup button pins
  for (uint8_t i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  // Setup timer
  ITimer.attachInterrupt(32000.0, EncoderTimer);

  // Setup Joystick
  Joystick.begin();
  Joystick.useManualSend(true);
  Joystick.use8bit(false);

  // Setup serial
  Serial.begin(115200);

}

void loop() {

  if ((millis() - lastUpdate) > 1) {

    // Read pins
    for (uint8_t i = 0; i < numButtons; i++) {
      Joystick.button(i, digitalRead(buttonPins[i]) == LOW);
    }

    // Convert encoder to proper range
    Joystick.X(position[0] * 1024 / (encoderPPR * 4));
    Joystick.Y(position[1] * 1024 / (encoderPPR * 4));

    // Send joystick state
    Joystick.send_now();

//    for (uint8_t i = 0; i < 2; i++) {
//      Serial.println(position[i]);
//    }

    lastUpdate = millis();
  }
}
