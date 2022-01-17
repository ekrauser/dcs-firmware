/*
  Tell DCS-BIOS to use a serial connection and use the default Arduino Serial
  library. This will work on the vast majority of Arduino-compatible boards,
  but you can get corrupted data if you have too many or too slow outputs
  (e.g. when you have multiple character displays), because the receive
  buffer can fill up if the sketch spends too much time updating them.
  
  If you can, use the IRQ Serial connection instead.
*/
#define DCSBIOS_IRQ_SERIAL

#include "DcsBios.h"
#include <Adafruit_GFX.h>
#include <UTFTGLUE.h>
int i = 0; // just for testing/debugging
int j = 0; // just for testing/debugging

UTFTGLUE myGLCD(0x9341,A2,A1,A3,A4,A0);

// set different brightness
// bright1 = 0x01E0; // darkest
// bright2 = 0x02E0; // values just for reference
// bright3 = 0x03E0; // so you know what my intention is
// bright4 = 0x04E0;
// bright5 = 0x05E0;
// bright6 = 0x06E0;
// bright7 = 0x07E0; //brightest
int cduBrt = 0x04E0; // start value
void onCduBrtChange(unsigned int newValue) { // newValue range 0 (left/down),1 (neutral),2 (right/up)
    if (newValue == 0){ // DIM/BRT-Rocker left
    cduBrt = cduBrt - 0x0100;
  };
  if (newValue == 2){ // DIM/BRT-Rocker right
    cduBrt = cduBrt + 0x0100;
  };
  if (cduBrt > 0x07E0){
    cduBrt = 0x07E0;    
  };
  if (cduBrt < 0x01E0){
    cduBrt = 0x01E0;    
  };
};
DcsBios::IntegerBuffer cduBrtBuffer(0x10fa, 0x0003, 0, onCduBrtChange);
// problem: just altered lines are drawn with new brightness

void printChar(int row, int col, unsigned char c) {
  int16_t x = 13 + col * 19;
  int16_t y = row * 32 + 6;
  myGLCD.drawChar(x, y, c, cduBrt, 0x0, 3); //0x07E0
} 

/* paste code snippets from the reference documentation here */
void onCduLine0Change(char* newValue) {
  for(int i = 0; i < 24; i++){
    printChar(0, i, newValue[i]);
  }
}
DcsBios::StringBuffer<24> cduLine0Buffer(0x11c0, onCduLine0Change);

void onCduLine1Change(char* newValue) {
  for(int i = 0; i < 24; i++){
    printChar(1, i, newValue[i]);
  }
}
DcsBios::StringBuffer<24> cduLine1Buffer(0x11d8, onCduLine1Change);

void onCduLine2Change(char* newValue) {
  for(int i = 0; i < 24; i++){
    printChar(2, i, newValue[i]);
  }
}
DcsBios::StringBuffer<24> cduLine2Buffer(0x11f0, onCduLine2Change);

void onCduLine3Change(char* newValue) {
  for(int i = 0; i < 24; i++){
    printChar(3, i, newValue[i]);
  }
}
DcsBios::StringBuffer<24> cduLine3Buffer(0x1208, onCduLine3Change);

void onCduLine4Change(char* newValue) {
  for(int i = 0; i < 24; i++){
    printChar(4, i, newValue[i]);
  }
}
DcsBios::StringBuffer<24> cduLine4Buffer(0x1220, onCduLine4Change);

void onCduLine5Change(char* newValue) {
  for(int i = 0; i < 24; i++){
    printChar(5, i, newValue[i]);
  }
}
DcsBios::StringBuffer<24> cduLine5Buffer(0x1238, onCduLine5Change);

void onCduLine6Change(char* newValue) {
  for(int i = 0; i < 24; i++){
    printChar(6, i, newValue[i]);
  }
}
DcsBios::StringBuffer<24> cduLine6Buffer(0x1250, onCduLine6Change);

void onCduLine7Change(char* newValue) {
  for(int i = 0; i < 24; i++){
    printChar(7, i, newValue[i]);
  }
}
DcsBios::StringBuffer<24> cduLine7Buffer(0x1268, onCduLine7Change);

void onCduLine8Change(char* newValue) {
  for(int i = 0; i < 24; i++){
    printChar(8, i, newValue[i]);
  }
}
DcsBios::StringBuffer<24> cduLine8Buffer(0x1280, onCduLine8Change);

void onCduLine9Change(char* newValue) {
  for(int i = 0; i < 24; i++){
    printChar(9, i, newValue[i]);
  }
}
DcsBios::StringBuffer<24> cduLine9Buffer(0x1298, onCduLine9Change);
 
void setup() {
  DcsBios::setup();

  // Setup the LCD
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myGLCD.setTextSize(3);
  myGLCD.setColor(55, 0, 0); // seems to have no effect
}

void loop() {
  DcsBios::loop();
}
