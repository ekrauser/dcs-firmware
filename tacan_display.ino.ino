/*
  Tell DCS-BIOS to use a serial connection and use the default Arduino Serial
  library. This will work on the vast majority of Arduino-compatible boards,
  but you can get corrupted data if you have too many or too slow outputs
  (e.g. when you have multiple character displays), because the receive
  buffer can fill up if the sketch spends too much time updating them.
  
  If you can, use the IRQ Serial connection instead.
*/
//#define DCSBIOS_DEFAULT_SERIAL
#define DCSBIOS_IRQ_SERIAL

//#include <Servo.h> //this has to be before dcsbios if using one, ties up timers, also needs shit loads of curent 
#include <LedControl.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include <LiquidCrystal.h>


#include "DcsBios.h"


LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

Adafruit_AlphaNum4 tacanD = Adafruit_AlphaNum4();
LedControl uhfD=LedControl(4,6,5,2); //dataPin, clockPin, csPin, numDevices

//Panel routines

//TACAN block works! -------------------------------------------------------
void onTacanChannelChange(char* newValue) {
  // your code here

  tacanD.clear();  //clear the display
  tacanD.writeDisplay();

  // set every digit to the buffer
  tacanD.writeDigitAscii(0, newValue[0]);
  tacanD.writeDigitAscii(1, newValue[1]);
  tacanD.writeDigitAscii(2, newValue[2]);
  tacanD.writeDigitAscii(3, newValue[3]);

  // write it out
  tacanD.writeDisplay();
  delay(100);
}

/* 
//VHF FM Block works! ------------------------------------------------
void onVhffmFreq1Change(char* newValue) {  //digits 1-2
    // your code here
    
    uhfD.setChar(0, 0, newValue[0], false);
    uhfD.setChar(0, 1, newValue[1], false);
    delay(50);
}

void onVhffmFreq2Change(unsigned int newValue) {  //digit 3
    // your code here 
    uhfD.setChar(0, 2, newValue, true);
    delay(50);
}

void onVhffmFreq3Change(unsigned int newValue) { //digit 4
    // your code here 
    uhfD.setChar(0, 3, newValue, false);
    delay(50);
}

void onVhffmFreq4Change(char* newValue) {  //digit 5-6
    // your code here 
    uhfD.setChar(0, 4, newValue[0], false);
    uhfD.setChar(0, 5, newValue[1], false);
    delay(50);
}

void onVhffmPresetChange(char* newValue) {  //digit 7-8
    // your code here
    uhfD.setChar(0, 6, newValue[0], false);
    uhfD.setChar(0, 7, newValue[1], false); 
    delay(50);
}

//UHF block works! ---------------------------------------------------------
void onUhfFrequencyChange(char* newValue) {
    // your code here /
    // setChar(chip addr,digit,value.dp) /

    uhfD.clearDisplay(0);

    uhfD.setChar(0, 0, newValue[0], false);
    uhfD.setChar(0, 1, newValue[1], false);
    uhfD.setChar(0, 2, newValue[2], true);
    uhfD.setChar(0, 3, newValue[4], false);
    uhfD.setChar(0, 4, newValue[5], false);
    uhfD.setChar(0, 5, newValue[6], false);
    delay(100);
}

void onUhfPresetChange(char* newValue) {
    // your code here 
    uhfD.setChar(0, 6, newValue[0], false);
    uhfD.setChar(0, 7, newValue[1], false);
    delay(100);
}
*/

//VHF AM BLOCK works! ----------------------------------------------------------
void onVhfamFreq1Change(char* newValue) {
    // your code here 
    uhfD.setChar(0, 0, newValue[0], false);
    uhfD.setChar(0, 1, newValue[1], false);
    delay(50);
}

void onVhfamFreq2Change(unsigned int newValue) {
    // your code here 
    uhfD.setChar(0, 2, newValue, true);
}

void onVhfamFreq3Change(unsigned int newValue) {
    // your code here 
    uhfD.setChar(0, 3, newValue, false);
}

void onVhfamFreq4Change(char* newValue) {
    // your code here 
    uhfD.setChar(0, 4, newValue[0], false);
    uhfD.setChar(0, 5, newValue[1], false);
    delay(50);
}

void onVhfamPresetChange(char* newValue) {
    // your code here 
    uhfD.setChar(0, 6, newValue[0], false);
    uhfD.setChar(0, 7, newValue[1], false);
    delay(50);
}

//--------------------------ILS Display Block
void onIlsKhzChange(char* newValue) {
    //here
    uhfD.setChar(1, 1, newValue[0], false);
    uhfD.setChar(1, 0, newValue[1], false);
    delay(50);
}

void onIlsMhzChange(char* newValue) {
    //here
    uhfD.setChar(1, 4, newValue[0], false);
    uhfD.setChar(1, 3, newValue[1], false);
    uhfD.setChar(1, 2, newValue[2], true);
    delay(50);
}

//------------------CMSP LCD Display Block
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



//DCS Definitions Start

//DcsBios::LED mcLed(0x1012, 0x0800, 9); //warning light test led on pin 9 COMMS DEBUG

//vhf fm block--------------------------------------------------
//DcsBios::StringBuffer<2> vhffmFreq1StrBuffer(0x119a, onVhffmFreq1Change);
//DcsBios::IntegerBuffer vhffmFreq2Buffer(0x119c, 0x000f, 0, onVhffmFreq2Change);
//DcsBios::IntegerBuffer vhffmFreq3Buffer(0x119c, 0x00f0, 4, onVhffmFreq3Change);
//DcsBios::StringBuffer<2> vhffmFreq4StrBuffer(0x119e, onVhffmFreq4Change);
//DcsBios::StringBuffer<2> vhffmPresetStrBuffer(0x1196, onVhffmPresetChange);

//UHF block ----------------------------------------------------
//DcsBios::StringBuffer<7> uhfFrequencyBuffer(0x1180, onUhfFrequencyChange); //these work
//DcsBios::StringBuffer<2> uhfPresetBuffer(0x1188, onUhfPresetChange);

//vhf am block ----------------------------------------------
DcsBios::StringBuffer<2> vhfamFreq1StrBuffer(0x1190, onVhfamFreq1Change);
DcsBios::IntegerBuffer vhfamFreq2Buffer(0x118e, 0x00f0, 4, onVhfamFreq2Change);
DcsBios::IntegerBuffer vhfamFreq3Buffer(0x118e, 0x0f00, 8, onVhfamFreq3Change);
DcsBios::StringBuffer<2> vhfamFreq4StrBuffer(0x1192, onVhfamFreq4Change);
DcsBios::StringBuffer<2> vhfamPresetStrBuffer(0x118a, onVhfamPresetChange);

//tacan block ---------------------------------------------------
DcsBios::StringBuffer<4> tacanChannelBuffer(0x1162, onTacanChannelChange);

//ils rotary test
//DcsBios::RotaryEncoder ilsKhz("ILS_KHZ", "DEC", "INC", 7, 8);
//DcsBios::RotaryEncoder ilsMhz("ILS_MHZ", "DEC", "INC", 9, 10);

//DcsBios::ServoOutput flapPos(0x10a0, 3, 544, 2400); //flaps servo test on pin3, servo is kinda beefed but works

//ILS Freq Diplay
DcsBios::StringBuffer<2> ilsKhzStrBuffer(0x1172, onIlsKhzChange);
DcsBios::StringBuffer<3> ilsMhzStrBuffer(0x116e, onIlsMhzChange);

//Yaw Trim Rotary Test
DcsBios::RotaryEncoder saspYawTrim("SASP_YAW_TRIM", "-3200", "+3200", A0, A1);

//CMSP LCD Display
DcsBios::StringBuffer<19> cmsp1Buffer(0x1000, onCmsp1Change);
DcsBios::StringBuffer<19> cmsp2Buffer(0x1014, onCmsp2Change);


//DCS Definitions End


void setup() {
  DcsBios::setup();

  uhfD.shutdown(0,false); //wake display chain 1, set brightness to med, clear display
  uhfD.setIntensity(0,8);
  uhfD.clearDisplay(0);

  uhfD.shutdown(1,false); //wake display chain 2, set brightness to med, clear display
  uhfD.setIntensity(1,8);
  uhfD.clearDisplay(1);

  tacanD.begin(0x70);  /* pass in the address */
  tacanD.clear();
  tacanD.writeDisplay();

  lcd.begin(20, 2);

}

void loop() {
  DcsBios::loop();
}

