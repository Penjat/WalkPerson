#include "app_state.h"
#include "input_service.h"
// #include "audio_service.h"
#include "lcd_service.h"


void setup() {
  setupInputs();
  setupAudio();
  setupLCD();
}


void loop() {
  readInputs();

  // updateAudio();

  updateDisplay();
}
