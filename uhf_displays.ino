/*
  Sketch for only the UHF radio display (6 freq + 2 chan) with a single max7221(19)
  can be chained for all 3 left hand radios

 
  Tell DCS-BIOS to use a serial connection and use the default Arduino Serial
  library. This will work on the vast majority of Arduino-compatible boards,
  but you can get corrupted data if you have too many or too slow outputs
  (e.g. when you have multiple character displays), because the receive
  buffer can fill up if the sketch spends too much time updating them.
  
  If you can, use the IRQ Serial connection instead.
*/
//#define DCSBIOS_DEFAULT_SERIAL
#define DCSBIOS_IRQ_SERIAL

#include "DcsBios.h"
#include <LedControl.h>

LedControl LeftRadio=LedControl(4,5,6,3); //dataPin, clockPin, csPin, numDevices

//routines---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//uhf block display 0 ----------------------------------------------------------------------------------
void onUhfFrequencyChange(char* newValue) {
    // setChar(chip addr,digit,value.dp)
    LeftRadio.setChar(0, 0, newValue[0], false);
    LeftRadio.setChar(0, 1, newValue[1], false);
    LeftRadio.setChar(0, 2, newValue[2], true);
    LeftRadio.setChar(0, 3, newValue[4], false);
    LeftRadio.setChar(0, 4, newValue[5], false);
    LeftRadio.setChar(0, 5, newValue[6], false);
    delay(50);
}

void onUhfPresetChange(char* newValue) {
    LeftRadio.setChar(0, 6, newValue[0], false);
    LeftRadio.setChar(0, 7, newValue[1], false);
    delay(50);
}

//vhf am display 1 ----------------------------------------------------------------------------------
void onVhfamFreq1Change(char* newValue) {
    LeftRadio.setChar(1, 0, newValue[0], false);
    LeftRadio.setChar(1, 1, newValue[1], false);
    delay(50);
}

void onVhfamFreq2Change(unsigned int newValue) {
    LeftRadio.setDigit(1, 2, newValue, true);
    delay(50);
}

void onVhfamFreq3Change(unsigned int newValue) {
    LeftRadio.setDigit(1, 3, newValue, false);
    delay(50);
}

void onVhfamFreq4Change(char* newValue) {
    LeftRadio.setChar(1, 4, newValue[0], false);
    LeftRadio.setChar(1, 5, newValue[1], false);
    delay(50);
}

void onVhfamPresetChange(char* newValue) {
    LeftRadio.setChar(1, 6, newValue[0], false);
    LeftRadio.setChar(1, 7, newValue[1], false);
    delay(50);
}

//vhf fm display 2 ---------------------------------------------------------
void onVhffmFreq1Change(char* newValue) {
    LeftRadio.setChar(2, 0, newValue[0], false);
    LeftRadio.setChar(2, 1, newValue[1], false);
    delay(50);
}

void onVhffmFreq2Change(unsigned int newValue) {
    LeftRadio.setDigit(2, 2, newValue, true);
    delay(50);
}

void onVhffmFreq3Change(unsigned int newValue) {
    LeftRadio.setDigit(2, 3, newValue, false);
    delay(50);
}

void onVhffmFreq4Change(char* newValue) {
    LeftRadio.setChar(2, 4, newValue[0], false);
    LeftRadio.setChar(2, 5, newValue[1], false);
    delay(50);
}

void onVhffmPresetChange(char* newValue) {
    LeftRadio.setChar(2, 6, newValue[0], false);
    LeftRadio.setChar(2, 7, newValue[1], false);
    delay(50);
}

//definitions -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//uhf radio ---------------------------------------------------------------------
DcsBios::StringBuffer<7> uhfFrequencyBuffer(0x1180, onUhfFrequencyChange); 
DcsBios::StringBuffer<2> uhfPresetBuffer(0x1188, onUhfPresetChange);

//vhf am radio ----------------------------------------------------------------------------------
DcsBios::StringBuffer<2> vhfamFreq1StrBuffer(0x1190, onVhfamFreq1Change);
DcsBios::IntegerBuffer vhfamFreq2Buffer(0x118e, 0x00f0, 4, onVhfamFreq2Change);
DcsBios::IntegerBuffer vhfamFreq3Buffer(0x118e, 0x0f00, 8, onVhfamFreq3Change);
DcsBios::StringBuffer<2> vhfamFreq4StrBuffer(0x1192, onVhfamFreq4Change);
DcsBios::StringBuffer<2> vhfamPresetStrBuffer(0x118a, onVhfamPresetChange);

//vhf fm radio ----------------------------------------------------------------------------------
DcsBios::StringBuffer<2> vhffmFreq1StrBuffer(0x119a, onVhffmFreq1Change);
DcsBios::IntegerBuffer vhffmFreq2Buffer(0x119c, 0x000f, 0, onVhffmFreq2Change);
DcsBios::IntegerBuffer vhffmFreq3Buffer(0x119c, 0x00f0, 4, onVhffmFreq3Change);
DcsBios::StringBuffer<2> vhffmFreq4StrBuffer(0x119e, onVhffmFreq4Change);
DcsBios::StringBuffer<2> vhffmPresetStrBuffer(0x1196, onVhffmPresetChange);

//setup and loop ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void setup() {
  // put your setup code here, to run once:
  DcsBios::setup();

  LeftRadio.shutdown(0,false); //wake display chain 1, set brightness to med, clear display
  LeftRadio.setIntensity(0,8);
  LeftRadio.clearDisplay(0);

  //LeftRadio.shutdown(1,false); //wake display chain 2, set brightness to med, clear display
  //LeftRadio.setIntensity(1,8);
  //LeftRadio.clearDisplay(1);

  //LeftRadio.shutdown(2,false); //wake display chain 3, set brightness to med, clear display
  //LeftRadio.setIntensity(2,8);
  //LeftRadio.clearDisplay(2);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  DcsBios::loop();
}
