//#define DCSBIOS_IRQ_SERIAL
//#include "DcsBios.h"
#include "Adafruit_Keypad.h"

const byte ROWS = 9; // rows
const byte COLS = 8; // columns
//define the symbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'a','i','1','4','7','.','[',']'},
  {'b','j','2','5','8','0','o','s'},
  {'c','k','3','6','9','/','p',' '},
  {'d','l','A','G','M','S','q','t'},
  {'e','m','B','H','N','T','r','u'},
  {'f','n','C','I','O','U','Y','v'},
  {'g','-','D','J','P','V','Z','w'},
  {'h','+','E','K','Q','W','{','}'},
  {' ',' ','F','L','R','X',' ',' '}
};
byte rowPins[ROWS] = {47, 45, 43, 41, 39, 37, 35, 33, 31}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {44, 42, 40, 38, 36, 34, 32, 30}; //connect to the column pinouts of the keypad
/*
NOTES ON PCB:
D22 VIA TOO CLOSE TO PAD (CAUSED A SHORT CIRCUIT BETWEEN COLUMN 1 AND 2), REDO ALL WIRING
THE SILKSCCREEN COMPONENT TYPES ARE STILL printlnED EVEN WHEN HIDDEN IN THE EDITOR
LED LIGHTS FOR THE LINES ARE INCOMPATABLE AND CANT BE SOLDERED (NOT NEEDED ANYWAY)
BIGGER COMPONENTS?
CHECK DIODE POLARITIES
REMOVE REDUNDANT WIRING
CHANGE TO WHITE PCB

JP1
col 1 - 1
col 2 - 2
col 3 - 3
col 4 - 4
col 5 - 5
col 6 - 6
col 7 - 7
col 8 - 8
col 9 - 9
row 1 - 10
row 2 - 11
row 3 - 12
row 4 - 13
row 5 - 14
row 6 - 15
row 7 - 16
row 8 - 17

19 - vcc ~1.8v?
18,20 - gnd

Special Characters:
LSK 1 -   a   |SYS   -   i    |PGUP   - [    |MK        -  s
LSK 2 -   b   |NAV   -   j    |PGDN   - ]    |BLAROCK_L -  t
LSK 3 -   c   |WP    -   k    |BLANK1 - o    |BLAROCK_R -  u
LSK 4 -   d   |OSET  -   l    |BLANK2 - p    |CLR       -  v
LSK 5 -   e   |FPM   -   m    |BCK    - q    |FA        -  w
LSK 6 -   f   |PREV  -   n    |SPC    - r    |
LSK 7 -   g   |DIM   -   -    |PLUS   - {    |
LSK 8 -   h   |BRT   -   +    |MINUS  - }    |
*/

//initialize an instance of class NewKeypad
Adafruit_Keypad kpd = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//DcsBios::Switch2Pos aapCdupwr("AAP_CDUPWR", 2);

//DcsBios::Switch2Pos aapEgipwr("AAP_EGIPWR", 3);

//const byte aapPagePins[7] = {4, 5, 6, 7};
//DcsBios::SwitchMultiPos aapPage("AAP_PAGE", aapPagePins, 7);

//DcsBios::Switch3Pos aapSteerpt("AAP_STEERPT", 8, 10);

//DcsBios::Switch3Pos aapSteer("AAP_STEER", 11, 12);

void setup() {
//  DcsBios::setup();
  Serial.begin(9600);
  kpd.begin();

}

void loop() {
//  DcsBios::loop();
  kpd.tick();
  keypadEvent e = kpd.read();
  char key = (char)e.bit.KEY;
if (e.bit.EVENT == KEY_JUST_PRESSED) {
      switch (key) 
      {
        case 'A': Serial.println(" CDU_A 1 "); break;
        case 'B': Serial.println(" CDU_B 1 "); break;
        case 'C': Serial.println(" CDU_C 1 "); break;
        case 'D': Serial.println(" CDU_D 1 "); break; 
        case 'E': Serial.println(" CDU_E 1 "); break; 
        case 'F': Serial.println(" CDU_F 1 "); break; 
        case 'G': Serial.println(" CDU_G 1 "); break; 
        case 'H': Serial.println(" CDU_H 1 "); break; 
        case 'I': Serial.println(" CDU_I 1 "); break; 
        case 'J': Serial.println(" CDU_J 1 "); break; 
        case 'K': Serial.println(" CDU_K 1 "); break; 
        case 'L': Serial.println(" CDU_L 1 "); break; 
        case 'M': Serial.println(" CDU_M 1 "); break; 
        case 'N': Serial.println(" CDU_N 1 "); break; 
        case 'O': Serial.println(" CDU_O 1 "); break;
        case 'P': Serial.println(" CDU_P 1 "); break;
        case 'Q': Serial.println(" CDU_Q 1 "); break; 
        case 'R': Serial.println(" CDU_R 1 "); break;   
        case 'S': Serial.println(" CDU_S 1 "); break;     
        case 'T': Serial.println(" CDU_T 1 "); break; 
        case 'U': Serial.println(" CDU_U 1 "); break;        
        case 'V': Serial.println(" CDU_V 1 "); break; 
        case 'W': Serial.println(" CDU_W 1 "); break; 
        case 'X': Serial.println(" CDU_X 1 "); break; 
        case 'Y': Serial.println(" CDU_Y 1 "); break; 
        case 'Z': Serial.println(" CDU_Z 1 "); break;

        case '0': Serial.println(" CDU_0 1 "); break; 
        case '1': Serial.println(" CDU_1 1 "); break; 
        case '2': Serial.println(" CDU_2 1 "); break; 
        case '3': Serial.println(" CDU_3 1 "); break; 
        case '4': Serial.println(" CDU_4 1 "); break; 
        case '5': Serial.println(" CDU_5 1 "); break; 
        case '6': Serial.println(" CDU_6 1 "); break; 
        case '7': Serial.println(" CDU_7 1 "); break; 
        case '8': Serial.println(" CDU_8 1 "); break; 
        case '9': Serial.println(" CDU_9 1 "); break;  
        case '.': Serial.println(" CDU_POINT 1 "); break; 
        case '/': Serial.println(" CDU_SLASH 1 "); break;

        case 'e': Serial.println(" CDU_LSK_3R 1 "); break; 
        case 'f': Serial.println(" CDU_LSK_5R 1 "); break;
        case 'g': Serial.println(" CDU_LSK_7R 1 "); break;
        case 'h': Serial.println(" CDU_LSK_9R 1 "); break;
    
        case 'a': Serial.println(" CDU_LSK_3L 1 "); break; 
        case 'b': Serial.println(" CDU_LSK_5L 1 "); break;
        case 'c': Serial.println(" CDU_LSK_7L 1 "); break;
        case 'd': Serial.println(" CDU_LSK_9L 1 "); break;
        
        case '[': Serial.println(" CDU_PG 2 "); break; 
        case ']': Serial.println(" CDU_PG 0 "); break; 
    
        case '>': Serial.println(" CDU_DATA 2 "); break; 
        case '<': Serial.println(" CDU_DATA 0 "); break;
        
        case 'i': Serial.println(" CDU_SYS 1 "); break; 
        case 'j': Serial.println(" CDU_NAV 1 "); break; 
        case 'k': Serial.println(" CDU_WP 1 "); break; 
        case 'l': Serial.println(" CDU_OSET 1 "); break; 
        case 'm': Serial.println(" CDU_FPM 1 "); break; 
        case 'n': Serial.println(" CDU_PREV 1 "); break;  
    
        case 's': Serial.println(" CDU_MK 1 "); break; 
        case 'v': Serial.println(" CDU_CLR 1 "); break; 
        case 'q': Serial.println(" CDU_BCK 1 "); break; 
        case 'r': Serial.println(" CDU_SPC 1 "); break; 
        case 'w': Serial.println(" CDU_FA 1 "); break;
      }
  }
else if (e.bit.EVENT == KEY_JUST_RELEASED) {
      switch (key) 
      {
        case 'A': Serial.println(" CDU_A 0 "); break;
        case 'B': Serial.println(" CDU_B 0 "); break; 
        case 'C': Serial.println(" CDU_C 0 "); break;     
        case 'D': Serial.println(" CDU_D 0 "); break; 
        case 'E': Serial.println(" CDU_E 0 "); break; 
        case 'F': Serial.println(" CDU_F 0 "); break; 
        case 'G': Serial.println(" CDU_G 0 "); break; 
        case 'H': Serial.println(" CDU_H 0 "); break; 
        case 'I': Serial.println(" CDU_I 0 "); break; 
        case 'J': Serial.println(" CDU_J 0 "); break; 
        case 'K': Serial.println(" CDU_K 0 "); break; 
        case 'L': Serial.println(" CDU_L 0 "); break; 
        case 'M': Serial.println(" CDU_M 0 "); break; 
        case 'N': Serial.println(" CDU_N 0 "); break; 
        case 'O': Serial.println(" CDU_O 0 "); break;
        case 'P': Serial.println(" CDU_P 0 "); break;
        case 'Q': Serial.println(" CDU_Q 0 "); break; 
        case 'R': Serial.println(" CDU_R 0 "); break;   
        case 'S': Serial.println(" CDU_S 0 "); break;     
        case 'T': Serial.println(" CDU_T 0 "); break; 
        case 'U': Serial.println(" CDU_U 0 "); break;        
        case 'V': Serial.println(" CDU_V 0 "); break; 
        case 'W': Serial.println(" CDU_W 0 "); break; 
        case 'X': Serial.println(" CDU_X 0 "); break; 
        case 'Y': Serial.println(" CDU_Y 0 "); break; 
        case 'Z': Serial.println(" CDU_Z 0 "); break;

        case '0': Serial.println(" CDU_0 0 "); break; 
        case '1': Serial.println(" CDU_1 0 "); break; 
        case '2': Serial.println(" CDU_2 0 "); break; 
        case '3': Serial.println(" CDU_3 0 "); break; 
        case '4': Serial.println(" CDU_4 0 "); break; 
        case '5': Serial.println(" CDU_5 0 "); break; 
        case '6': Serial.println(" CDU_6 0 "); break; 
        case '7': Serial.println(" CDU_7 0 "); break; 
        case '8': Serial.println(" CDU_8 0 "); break; 
        case '9': Serial.println(" CDU_9 0 "); break;  
        case '.': Serial.println(" CDU_POINT 0 "); break; 
        case '/': Serial.println(" CDU_SLASH 0 "); break; 
            
        case 'e': Serial.println(" CDU_LSK_3R 0 "); break; 
        case 'f': Serial.println(" CDU_LSK_5R 0 "); break;
        case 'g': Serial.println(" CDU_LSK_7R 0 "); break;
        case 'h': Serial.println(" CDU_LSK_9R 0 "); break;
    
        case 'a': Serial.println(" CDU_LSK_3L 0 "); break; 
        case 'b': Serial.println(" CDU_LSK_5L 0 "); break;
        case 'c': Serial.println(" CDU_LSK_7L 0 "); break;
        case 'd': Serial.println(" CDU_LSK_9L 0 "); break;
        
        case '[': Serial.println(" CDU_PG 1 "); break; 
        case ']': Serial.println(" CDU_PG 1 "); break; 
    
        case '>': Serial.println(" CDU_DATA 1 "); break; 
        case '<': Serial.println(" CDU_DATA 1 "); break; 
        
        case 'i': Serial.println(" CDU_SYS 0 "); break; 
        case 'j': Serial.println(" CDU_NAV 0 "); break; 
        case 'k': Serial.println(" CDU_WP 0 "); break; 
        case 'l': Serial.println(" CDU_OSET 0 "); break; 
        case 'm': Serial.println(" CDU_FPM 0 "); break; 
        case 'n': Serial.println(" CDU_PREV 0 "); break;  
    
        case 's': Serial.println(" CDU_MK 0 "); break; 
        case 'v': Serial.println(" CDU_CLR 0 "); break; 
        case 'q': Serial.println(" CDU_BCK 0 "); break; 
        case 'r': Serial.println(" CDU_SPC 0 "); break; 
        case 'w': Serial.println(" CDU_FA 0 "); break; 
      }
  }
  delay(10);
};
