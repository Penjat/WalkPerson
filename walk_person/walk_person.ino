#include "app_state.h"
#include "input_service.h"
#include "audio_service.h"
#include "lcd_service.h"


void setup() {
  Serial.begin(9600);
  Serial.println("starting walkperson...");
  
  setupInputs();
  setupAudio();
  setupLCD();
  listWavFiles();
}


void loop() {
  readInputs();

  // updateAudio();

  updateDisplay();
}
