/*
  Tell DCS-BIOS to use a serial connection and use the default Arduino Serial
  library. This will work on the vast majority of Arduino-compatible boards,
  but you can get corrupted data if you have too many or too slow outputs
  (e.g. when you have multiple character displays), because the receive
  buffer can fill up if the sketch spends too much time updating them.
  
  If you can, use the IRQ Serial connection instead.
*/
#define DCSBIOS_DEFAULT_SERIAL

#include "DcsBios.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();

//custom shit has to go first
void onTacanChannelChange(char* newValue) {
    /* your code here */

    alpha4.clear();  //clear the display 
    alpha4.writeDisplay();  
      
    // set every digit to the buffer
    alpha4.writeDigitAscii(0, newValue[0]);
    alpha4.writeDigitAscii(1, newValue[1]);
    alpha4.writeDigitAscii(2, newValue[2]);
    alpha4.writeDigitAscii(3, newValue[3]);
    
    // write it out
    alpha4.writeDisplay();
    delay(100);
}


//then all the io definitions
/* paste code snippets from the reference documentation here */
DcsBios::Switch2Pos masterCautionBtn("UFC_MASTER_CAUTION", 10);
DcsBios::LED mcLed(0x1012, 0x0800, 6);
DcsBios::StringBuffer<4> tacanChannelBuffer(0x1162, onTacanChannelChange);

//then the setup and loop
void setup() {
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
}
