//7seg test

#include <LedControl.h>

LedControl uhfD=LedControl(4,5,6,1); //dataPin, clockPin, csPin, numDevices

void setup() {
  // put your setup code here, to run once:
  uhfD.shutdown(0,false); //wake display chain 1, set brightness to med, clear display
  uhfD.setIntensity(0,8);
  uhfD.clearDisplay(0);

  
  uhfD.clearDisplay(0);

  //void setChar(int addr, int digit, char value, boolean dp);
  
  uhfD.setChar(0, 0, '8', false);
  uhfD.setChar(0, 1, '8', false);
  uhfD.setChar(0, 2, '8', true);
  uhfD.setChar(0, 3, '8', false);
  uhfD.setChar(0, 4, '8', false);
  uhfD.setChar(0, 5, '8', false);
  
  uhfD.setChar(0, 6, '8', false);
  uhfD.setChar(0, 7, '8', false);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
