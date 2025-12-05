#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

// Display Modes
#define DISPLAY_INPUT_TEST 0


#define OLED_RESET     4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setupLCD() {
	if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    // for(;;); // Don't proceed, loop forever
    return;
  }
}

void updateDisplay() {

	display.clearDisplay();
	display.setCursor(0,0);
	display.println("Got the screen");
	display.setCursor(0,10);

	display.println("working");
	display.display();
}
