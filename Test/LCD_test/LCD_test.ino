// Teensy 4.1 – Two Push Buttons Example
// Buttons wired to GND, using internal pull-ups

const int button1Pin = 32;   // Choose any digital pin
const int button2Pin = 30;

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };
  

void setup() {
  Serial.begin(115200);

  pinMode(button1Pin, INPUT_PULLUP);  // Enable internal pull-up
  pinMode(button2Pin, INPUT_PULLUP);

  Serial.println("Ready...");

  Serial.begin(9600);
  Serial.println(F("starting up..."));
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    // for(;;); // Don't proceed, loop forever
    return;
  }

  Serial.println(F("found lcd"));

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
//  display.drawPixel(10, 10, SSD1306_WHITE);


  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println(F("Hello, assmass!"));
  display.display();
}

void loop() {
  bool b1 = !digitalRead(button1Pin);   // LOW = pressed
  bool b2 = !digitalRead(button2Pin);

  if (b1) {
    Serial.println("Button 1 pressed");
    delay(200); // simple debounce
  }

  if (b2) {
    Serial.println("Button 2 pressed");
    delay(200);
  }

   display.clearDisplay();
   display.setCursor(0,0);
//  display.println((sensorValue-minValue)*100/(maxValue-minValue));
  display.println("Got the screen");
display.setCursor(0,10);

display.println("working");
display.display();
//  display.display();
  
//  for(int16_t i=0; i<display.height()/2; i+=2) {
//    display.drawRect(0, 0, display.width()*(sensorValue-minValue)/(maxValue-minValue), display.height()-2, SSD1306_WHITE);
    display.display(); // Update screen with each newly-drawn rectangle
    delay(500);
}