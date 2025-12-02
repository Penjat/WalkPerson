#include <Arduino.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

#include "AudioEffectHello.h"   // Your custom effect

// Audio objects
AudioPlaySdWav playWav;
AudioEffectHello hello;
AudioOutputI2S audioOut;

AudioConnection patchCord1(playWav, 0, hello, 0);
AudioConnection patchCord2(hello, 0, audioOut, 0);
AudioConnection patchCord3(hello, 0, audioOut, 1);

AudioControlSGTL5000 sgtl5000;

void setup() {
    Serial.begin(115200);
    AudioMemory(20);

    sgtl5000.enable();
    sgtl5000.volume(0.7);

    if (!SD.begin(BUILTIN_SDCARD)) {
        Serial.println("SD card failed!");
        while (1);
    }

    Serial.println("Playing test2.wav through Hello effect…");
    playWav.play("test2.wav");
    delay(10);
}

void loop() {
    if (!playWav.isPlaying()) {
        playWav.play("test2.wav");
        delay(10);
    }
}
