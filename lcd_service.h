#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET 4

// Display Modes
#define DISPLAY_INPUT_TEST 0

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

	// Volume Bar
	display.drawRect(0, 0, 16, display.height(), SSD1306_WHITE);
	display.fillRect(1, 1, 9, display.height(), SSD1306_WHITE);
	display.display();

	
	// display.setCursor(0,0);
	// display.println("Got the screen");
	// display.setCursor(0,10);

	// display.println("working");
	

	
	// display.setTextSize(2);
	// display.setTextColor(SSD1306_BLACK);
  	// display.fillCircle(display.width() / 2 + 8, 10, circleRadius, SSD1306_WHITE);
  	// display.drawCircle(display.width() / 2 + 8, 10, circleRadius, SSD1306_WHITE);
}
