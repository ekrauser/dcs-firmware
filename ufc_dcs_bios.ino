//UFC DCS-BIOS Sketch

//backlight setup
#include <Wire.h>
#include "FastLED.h"
#define BACKLIGHTPIN  5  // Which pin on the Arduino is connected to the NeoPixels?
#define NUMPIXELS  12    // How many NeoPixels are attached
#define LED_TYPE    WS2812b
#define COLOR_ORDER GRB

#define BUTTONLEDS 6 //which pin for the button leds

uint8_t backlightBrightness = 64; // initial value - will be reset in brightness function later (255 max)
CRGB BacklightLEDs[NUMPIXELS];  // Memory array for the fastLED function

//DCS Setup

#define DCSBIOS_DEFAULT_SERIAL  //one or the other #define DCSBIOS_IRQ_SERIAL or #define DCSBIOS_DEFAULT_SERIAL

#include "DcsBios.h"

//Gets lighting valule from DCS
void onLcpConsoleChange(unsigned int newValue) {
   backlightBrightness = map(newValue,0, 65535, 0, 255); // Change 16-bit input to 8-bit for FastLED brightness function
   LEDbacklight(backlightBrightness); // Run the lighting routine
}

//Sees if there is power in the plane
unsigned int powerStatus;     //  Power on/off flag - really an unsigned int

void onAoaPwroffChange(unsigned int newValue) {
  powerStatus = newValue;
  LEDbacklight(backlightBrightness); // Run the lighting routine
}

void LEDbacklight(unsigned int newValue) {       // LED backlight brightness control
  if (powerStatus != 0){                         // check if power is on - might need to change to != 65535 or == 0
    FastLED.setBrightness(newValue);             // Set the new level
    FastLED.show();                              // Send it to the LEDs
    analogWrite(BUTTONLEDS, newValue);           // Set the button brightness
  }
  else {
    FastLED.setBrightness(0);                    // Set the LEDs off
    FastLED.show();                              // Send it to the LEDs
    analogWrite(BUTTONLEDS, 0);                  // Set the button brightness
  }
}

//definitions from control reference doc

//backlight from dcs
DcsBios::IntegerBuffer lcpConsoleBuffer(0x1150, 0xffff, 0, onLcpConsoleChange);
DcsBios::IntegerBuffer aoaPwroffBuffer(0x1076, 0xffff, 0, onAoaPwroffChange);

//3pos select buttons left to right
DcsBios::Switch3Pos ufcSteer("UFC_STEER", 44, 45);
DcsBios::Switch3Pos ufcData("UFC_DATA", 46, 47);
DcsBios::Switch3Pos ufcInten("UFC_INTEN", 48, 49);
DcsBios::Switch3Pos ufcSel("UFC_SEL", 50, 51);
DcsBios::Switch3Pos ufcDepr("UFC_DEPR", 52, 53);

//master caution led and reset
DcsBios::LED masterCaution(0x1012, 0x0800, 2); //led (5v)
DcsBios::Switch2Pos ufcMasterCaution("UFC_MASTER_CAUTION", 3); //reset button

//buttons
DcsBios::Switch2Pos ufc1("UFC_1", 22);
DcsBios::Switch2Pos ufc2("UFC_2", 23);
DcsBios::Switch2Pos ufc3("UFC_3", 24);
DcsBios::Switch2Pos ufc4("UFC_4", 25);
DcsBios::Switch2Pos ufc5("UFC_5", 26);
DcsBios::Switch2Pos ufc6("UFC_6", 27);
DcsBios::Switch2Pos ufc7("UFC_7", 28);
DcsBios::Switch2Pos ufc8("UFC_8", 29);
DcsBios::Switch2Pos ufc9("UFC_9", 30);
DcsBios::Switch2Pos ufcHack("UFC_HACK", 31);
DcsBios::Switch2Pos ufcFunc("UFC_FUNC", 32);
DcsBios::Switch2Pos ufcEnt("UFC_ENT", 33);
DcsBios::Switch2Pos ufcLtr("UFC_LTR", 34);
DcsBios::Switch2Pos ufcMk("UFC_MK", 35);
DcsBios::Switch2Pos ufcClr("UFC_CLR", 36);
DcsBios::Switch2Pos ufcAltAlrt("UFC_ALT_ALRT", 37);

//blank buttons
DcsBios::Switch2Pos ufcNa1("UFC_NA1", 38);
DcsBios::Switch2Pos ufcNa2("UFC_NA2", 39);
DcsBios::Switch2Pos ufcNa3("UFC_NA3", 40);
DcsBios::Switch2Pos ufcNa4("UFC_NA4", 41);
DcsBios::Switch2Pos ufcNa5("UFC_NA5", 42);
DcsBios::Switch2Pos ufcNa6("UFC_NA6", 43);

//loop and setup always last
void setup() {  
  DcsBios::setup();
  
  pinMode(BUTTONLEDS, OUTPUT);
  
  FastLED.addLeds<NEOPIXEL, BACKLIGHTPIN>(BacklightLEDs, NUMPIXELS);  // Set up LED strip parameters
  FastLED.setBrightness(backlightBrightness);   // Set strip initial master brightness
  fill_solid( BacklightLEDs, NUMPIXELS, CRGB::Green); // Fill strip with green - CRGB(0,255,0) also works
  BacklightLEDs[0] = CRGB::Red; // Set 1st led as red - because why not?
  FastLED.show();  // Send LED changes to the strip
}

void loop() {
  DcsBios::loop();
}
