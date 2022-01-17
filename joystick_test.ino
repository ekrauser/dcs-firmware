/* @file MultiKey.ino
|| @version 1.0
|| @author Mark Stanley
|| @contact mstanley@technologist.com
||
|| @description
|| | The latest version, 3.0, of the keypad library supports up to 10
|| | active keys all being pressed at the same time. This sketch is an
|| | example of how you can get multiple key presses from a keypad or
|| | keyboard.
|| #
*/

#include <Keypad.h>

const byte ROWS = 4; //4 rows
const byte COLS = 5; //5 columns
char keys[ROWS][COLS] = {
  {'a','b','c','d','e'},
  {'f','g','h','i','j'},
  {'k','l','m','n','o'},
  {'p','q','r','s','t'}
};
byte rowPins[ROWS] = {21, 20, 19, 18}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {26, 25, 24, 23, 22}; //connect to the column pinouts of the keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );



void setup() {
  Serial.begin(9600);
  kpd.setDebounceTime(1);

  for (int i=18; i<22; i++){
    pinMode(i, INPUT_PULLUP);
  }
  
}

unsigned long loopCount = 0;
unsigned long startTime = millis();
String msg = "";


void loop() {

  Joystick.Y(analogRead(0));
  Joystick.X(analogRead(1));
  Joystick.Z(analogRead(2));


  loopCount++;
  if ( (millis()-startTime)>1000 ) {
      Serial.println(loopCount);
      startTime = millis();
      loopCount = 0;
  }

  // Fills kpd.key[ ] array with up-to 10 active keys.
  // Returns true if there are ANY active keys.
  if (kpd.getKeys())
  {
    for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
    {
      if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
      {
        switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
            case PRESSED:
                msg = "1";
                break;
            case RELEASED:
                msg = "0";
                break;
        }
        //Joystick.button((kpd.key[i].kchar), state);
        Serial.print(kpd.key[i].kchar);
        Serial.println(msg);
        //switch (btn)
          //case 
      }
    }
  }
}  // End loop
