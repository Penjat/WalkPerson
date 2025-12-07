#include "app_state.h"
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

AudioPlaySdWav           playWav1;
// Use one of these 3 output types: Digital I2S, Digital S/PDIF, or Analog DAC
AudioOutputI2S           audioOutput;
// AudioEffectVocoder vocoder;
//AudioOutputSPDIF       audioOutput;
//AudioOutputAnalog      audioOutput;
//On Teensy LC, use this for the Teensy Audio Shield:
//AudioOutputI2Sslave    audioOutput;

AudioMixer4          mix;

// AudioConnection patch1    (playWav1, vocoder);
AudioConnection patch2    (playWav1, 0, mix, 0);
// AudioConnection patch3    (playWav1,   0, mix, 1);
AudioConnection patch_dac (mix, audioOutput);

// AudioConnection          patchCord2(vocoder, 1, audioOutput, 1);

AudioControlSGTL5000     sgtl5000_1;


#define SDCARD_MOSI_PIN 7
#define SDCARD_SCK_PIN 14
#define SDCARD_CS_PIN    BUILTIN_SDCARD

void updateAudio() {

}

void setupAudio() {
	AudioMemory(15);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);

  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    // stop here, but print a message repetitively
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
}


void listWavFiles() {
	Serial.println("loading files...");
  File root = SD.open("/");

  if (!root) {
    Serial.println("Failed to open root directory");
    return;
  }

  File file = root.openNextFile();

  while (file) {
    if (!file.isDirectory()) {
      String name = file.name();

      // Look for .WAV or .wav
      if (name.endsWith(".WAV") || name.endsWith(".wav")) {
        Serial.print("Found WAV: ");
        Serial.println(name);

        // Try to parse "Artist - Title.wav"
        String artist = "";
        String title = "";

        // Remove extension
        int dot = name.lastIndexOf('.');
        String base = name.substring(0, dot);

        // Format: "Artist - Title"
        int dash = base.indexOf('-');
        if (dash > 0) {
          artist = base.substring(0, dash);
          title  = base.substring(dash + 1);
        } else {
          // Fall back to "artist_title"
          int underscore = base.indexOf('_');
          if (underscore > 0) {
            artist = base.substring(0, underscore);
            title  = base.substring(underscore + 1);
          } else {
            // No pattern detected
            artist = "Unknown";
            title  = base;
          }
        }

        // Clean whitespace
        artist.trim();
        title.trim();

        Serial.print("  Artist: ");
        Serial.println(artist);

        Serial.print("  Title : ");
        Serial.println(title);
      }
    }

    file = root.openNextFile();
  }
}