# Arduino RP2040 Game Controller

Code for a Bemani-focused game controller targeting the RP2040 microcontroller.

**THIS IS A WORK IN PROGRESS** - Feedback is always welcome, but please don't expect it to be full featured yet!

## Pre-Requisites

* Install the [Arduino IDE](https://www.arduino.cc/en/software). I recommend downloading 1.8.19 and running in [portable mode](https://docs.arduino.cc/software/ide-v1/tutorials/PortableIDE/), but 2.x should work without issue.
* Install the [arduino-pico core](https://github.com/earlephilhower/arduino-pico?tab=readme-ov-file#installing-via-arduino-boards-manager) using the instructions in the README.
* Install the [RPI_PICO_TimerInterrupt](https://github.com/khoih-prog/RPI_PICO_TimerInterrupt?tab=readme-ov-file#use-arduino-library-manager) library using the instructions in the README.

## How to Use

1. Download this repo and open the sketch in the Arduino IDE.
2. Select the correct board for your setup.
3. Press upload! If Arduino does not auto-restart your board into bootloader mode, do so yourself by holding BOOTSEL on the board and plugging the board in.