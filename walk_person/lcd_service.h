#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define SCREEN_ADDRESS 0x3C
#define OLED_RESET -1

// Display Modes
#define DISPLAY_INPUT_TEST 0

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setupLCD() {
	if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    // for(;;); // Don't proceed, loop forever
    return;
  }
}

void updateDisplay() {
	display.clearDisplay();

	// Volume Bar
	// display.setCursor(0,0);
	display.drawRect(0, 0, 8, 31, SSD1306_WHITE);

	display.fillRect(1, 31-20, 6, 31, SSD1306_WHITE);
	// display.drawRect(32, 0, 31, 31, SSD1306_WHITE);
	// display.drawRect(64, 0, 31, 31, SSD1306_WHITE);
	// display.drawRect(96, 0, 31, 31, SSD1306_WHITE);
	// display.drawLine(0, 0, display.width()-1, display.height()-1, SSD1306_WHITE);
	// display.drawLine(display.width()-1, 0, 0, display.height()-1, SSD1306_WHITE);

	// display.setCursor(0,0);
	// display.drawRect(0, 16, 31, 31, SSD1306_WHITE);
	// display.fillRect(1, 1, 14, 9, SSD1306_WHITE);
	
	
	
	// 
	// display.println("Got the screen");
	// display.setCursor(0,10);

	// display.println("working");
	

	
	// display.setTextSize(2);
	// display.setTextColor(SSD1306_BLACK);
	// display.fillCircle(16, 16, 12, SSD1306_WHITE);
	// // display.display();
  	// display.fillCircle(display.width() / 2 + 8, 10, 12, SSD1306_WHITE);
  	// display.drawRect(4, 4, 12, 12, SSD1306_WHITE);
  	// display.display();
  	// delay(400);
  	// display.drawCircle(display.width() / 2 + 8, 10, circleRadius, SSD1306_WHITE);

  	// int16_t i;

  // display.clearDisplay(); // Clear display buffer

  // for(i=0; i<display.width(); i+=4) {
  //   display.drawLine(0, 0, i, display.height()-1, SSD1306_WHITE);
    display.display(); // Update screen with each newly-drawn line
  //   delay(1);
  // }
  // for(i=0; i<display.height(); i+=4) {
  //   display.drawLine(0, 0, display.width()-1, i, SSD1306_WHITE);
  //   display.display();
  //   delay(1);
  // }
  delay(250);
}
