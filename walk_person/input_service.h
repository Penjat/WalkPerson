#include "app_state.h"
#include "hardware_config.h"

void setupInputs() {
  
  Serial.begin(9600);

  pinMode(ROTARY_1, INPUT);
  pinMode(ROTARY_2, INPUT);
  pinMode(ROTARY_PRESS, INPUT);
  pinMode(BUTTON_R, INPUT);
  pinMode(BUTTON_L, INPUT);
}

void readInputs() {
  tempoKnobValue = analogRead(TEMPO_KNOB);
  pitchKnobValue = analogRead(PITCH_KNOB);
  timeLowKnobValue = analogRead(TIME_LOW_KNOB);
  timeHighKnobValue = analogRead(TIME_HIGH_KNOB);
  volumeKnobValue = analogRead(VOLUME_KNOB);

  rotary1 = digitalRead(ROTARY_1);
  rotary2 = digitalRead(ROTARY_2);
  rotary2 = digitalRead(ROTARY_PRESS);
  rotary1 = digitalRead(BUTTON_R);
  rotary2 = digitalRead(BUTTON_L);
}
