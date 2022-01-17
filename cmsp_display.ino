/*
  Tell DCS-BIOS to use a serial connection and use interrupt-driven
  communication. The main program will be interrupted to prioritize
  processing incoming data.
  
  This should work on any Arduino that has an ATMega328 controller
  (Uno, Pro Mini, many others).
 */
#define DCSBIOS_IRQ_SERIAL

#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"
#include "DcsBios.h"

Adafruit_LiquidCrystal lcd(0);

/* paste code snippets from the reference documentation here */

void onCmsp1Change(char* newValue) {
    // your code here 
    lcd.setCursor(0,0);
    lcd.print(newValue);
    
}

void onCmsp2Change(char* newValue) {
    // your code here 
    lcd.setCursor(0,1);
    lcd.print(newValue);
}


DcsBios::StringBuffer<19> cmsp1Buffer(0x1000, onCmsp1Change);
DcsBios::StringBuffer<19> cmsp2Buffer(0x1014, onCmsp2Change);


void setup() {
  lcd.begin(20, 2);
  lcd.setBacklight(HIGH);
  
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
}

