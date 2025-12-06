#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "WavFilePlayer/effect_vocoder.h"
#include "app_state.h"


AudioPlaySdWav playWav1;
AudioOutputI2S audioOutput;
AudioEffectVocoder vocoder;
AudioMixer4 mix;

AudioConnection patch1    (playWav1, vocoder);
AudioConnection patch2    (vocoder, 0, mix, 0);
AudioConnection patch_dac (mix, audioOutput);

AudioControlSGTL5000 sgtl5000_1;

void setupAudio() {
	AudioMemory(15);

	sgtl5000_1.enable();
	sgtl5000_1.volume(0.5);

	SPI.setMOSI(SDCARD_MOSI_PIN);
	SPI.setSCK(SDCARD_SCK_PIN);

	if (!(SD.begin(SDCARD_CS_PIN))) {
    	while (1) {
      	Serial.println("Unable to access the SD card");
      	delay(500);
    	}
  	}
}

void updateAudio() {
	vol = volumeKnobValue / 1024;
	sgtl5000_1.volume(vol);
}

void playFile(const char *filename)
{
  Serial.print("Playing file: ");
  Serial.println(filename);

}
