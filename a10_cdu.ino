#define DCSBIOS_IRQ_SERIAL
#include "DcsBios.h"
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
THE SILKSCCREEN COMPONENT TYPES ARE STILL PRINTED EVEN WHEN HIDDEN IN THE EDITOR
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
  DcsBios::setup();
//  Serial.begin(9600);
  kpd.begin();

}

void loop() {
  DcsBios::loop();
  kpd.tick();
  keypadEvent e = kpd.read();
  char key = (char)e.bit.KEY;
if (e.bit.EVENT == KEY_JUST_PRESSED) {
      switch (key) 
      {
        case 'A': sendDcsBiosMessage("CDU_A", "1"); break;
        case 'B': sendDcsBiosMessage("CDU_B", "1"); break;
        case 'C': sendDcsBiosMessage("CDU_C", "1"); break;
        case 'D': sendDcsBiosMessage("CDU_D", "1"); break; 
        case 'E': sendDcsBiosMessage("CDU_E", "1"); break; 
        case 'F': sendDcsBiosMessage("CDU_F", "1"); break; 
        case 'G': sendDcsBiosMessage("CDU_G", "1"); break; 
        case 'H': sendDcsBiosMessage("CDU_H", "1"); break; 
        case 'I': sendDcsBiosMessage("CDU_I", "1"); break; 
        case 'J': sendDcsBiosMessage("CDU_J", "1"); break; 
        case 'K': sendDcsBiosMessage("CDU_K", "1"); break; 
        case 'L': sendDcsBiosMessage("CDU_L", "1"); break; 
        case 'M': sendDcsBiosMessage("CDU_M", "1"); break; 
        case 'N': sendDcsBiosMessage("CDU_N", "1"); break; 
        case 'O': sendDcsBiosMessage("CDU_O", "1"); break;
        case 'P': sendDcsBiosMessage("CDU_P", "1"); break;
        case 'Q': sendDcsBiosMessage("CDU_Q", "1"); break; 
        case 'R': sendDcsBiosMessage("CDU_R", "1"); break;   
        case 'S': sendDcsBiosMessage("CDU_S", "1"); break;     
        case 'T': sendDcsBiosMessage("CDU_T", "1"); break; 
        case 'U': sendDcsBiosMessage("CDU_U", "1"); break;        
        case 'V': sendDcsBiosMessage("CDU_V", "1"); break; 
        case 'W': sendDcsBiosMessage("CDU_W", "1"); break; 
        case 'X': sendDcsBiosMessage("CDU_X", "1"); break; 
        case 'Y': sendDcsBiosMessage("CDU_Y", "1"); break; 
        case 'Z': sendDcsBiosMessage("CDU_Z", "1"); break;

        case '0': sendDcsBiosMessage("CDU_0", "1"); break; 
        case '1': sendDcsBiosMessage("CDU_1", "1"); break; 
        case '2': sendDcsBiosMessage("CDU_2", "1"); break; 
        case '3': sendDcsBiosMessage("CDU_3", "1"); break; 
        case '4': sendDcsBiosMessage("CDU_4", "1"); break; 
        case '5': sendDcsBiosMessage("CDU_5", "1"); break; 
        case '6': sendDcsBiosMessage("CDU_6", "1"); break; 
        case '7': sendDcsBiosMessage("CDU_7", "1"); break; 
        case '8': sendDcsBiosMessage("CDU_8", "1"); break; 
        case '9': sendDcsBiosMessage("CDU_9", "1"); break;  
        case '.': sendDcsBiosMessage("CDU_POINT", "1"); break; 
        case '/': sendDcsBiosMessage("CDU_SLASH", "1"); break;

        case 'e': sendDcsBiosMessage("CDU_LSK_3R", "1"); break; 
        case 'f': sendDcsBiosMessage("CDU_LSK_5R", "1"); break;
        case 'g': sendDcsBiosMessage("CDU_LSK_7R", "1"); break;
        case 'h': sendDcsBiosMessage("CDU_LSK_9R", "1"); break;
    
        case 'a': sendDcsBiosMessage("CDU_LSK_3L", "1"); break; 
        case 'b': sendDcsBiosMessage("CDU_LSK_5L", "1"); break;
        case 'c': sendDcsBiosMessage("CDU_LSK_7L", "1"); break;
        case 'd': sendDcsBiosMessage("CDU_LSK_9L", "1"); break;
        
        case '[': sendDcsBiosMessage("CDU_PG", "2"); break; 
        case ']': sendDcsBiosMessage("CDU_PG", "0"); break; 
    
        case '>': sendDcsBiosMessage("CDU_DATA", "2"); break; 
        case '<': sendDcsBiosMessage("CDU_DATA", "0"); break;
        
        case 'i': sendDcsBiosMessage("CDU_SYS", "1"); break; 
        case 'j': sendDcsBiosMessage("CDU_NAV", "1"); break; 
        case 'k': sendDcsBiosMessage("CDU_WP", "1"); break; 
        case 'l': sendDcsBiosMessage("CDU_OSET", "1"); break; 
        case 'm': sendDcsBiosMessage("CDU_FPM", "1"); break; 
        case 'n': sendDcsBiosMessage("CDU_PREV", "1"); break;  
    
        case 's': sendDcsBiosMessage("CDU_MK", "1"); break; 
        case 'v': sendDcsBiosMessage("CDU_CLR", "1"); break; 
        case 'q': sendDcsBiosMessage("CDU_BCK", "1"); break; 
        case 'r': sendDcsBiosMessage("CDU_SPC", "1"); break; 
        case 'w': sendDcsBiosMessage("CDU_FA", "1"); break;
      }
  }
else if (e.bit.EVENT == KEY_JUST_RELEASED) {
      switch (key) 
      {
        case 'A': sendDcsBiosMessage("CDU_A", "0"); break;
        case 'B': sendDcsBiosMessage("CDU_B", "0"); break; 
        case 'C': sendDcsBiosMessage("CDU_C", "0"); break;     
        case 'D': sendDcsBiosMessage("CDU_D", "0"); break; 
        case 'E': sendDcsBiosMessage("CDU_E", "0"); break; 
        case 'F': sendDcsBiosMessage("CDU_F", "0"); break; 
        case 'G': sendDcsBiosMessage("CDU_G", "0"); break; 
        case 'H': sendDcsBiosMessage("CDU_H", "0"); break; 
        case 'I': sendDcsBiosMessage("CDU_I", "0"); break; 
        case 'J': sendDcsBiosMessage("CDU_J", "0"); break; 
        case 'K': sendDcsBiosMessage("CDU_K", "0"); break; 
        case 'L': sendDcsBiosMessage("CDU_L", "0"); break; 
        case 'M': sendDcsBiosMessage("CDU_M", "0"); break; 
        case 'N': sendDcsBiosMessage("CDU_N", "0"); break; 
        case 'O': sendDcsBiosMessage("CDU_O", "0"); break;
        case 'P': sendDcsBiosMessage("CDU_P", "0"); break;
        case 'Q': sendDcsBiosMessage("CDU_Q", "0"); break; 
        case 'R': sendDcsBiosMessage("CDU_R", "0"); break;   
        case 'S': sendDcsBiosMessage("CDU_S", "0"); break;     
        case 'T': sendDcsBiosMessage("CDU_T", "0"); break; 
        case 'U': sendDcsBiosMessage("CDU_U", "0"); break;        
        case 'V': sendDcsBiosMessage("CDU_V", "0"); break; 
        case 'W': sendDcsBiosMessage("CDU_W", "0"); break; 
        case 'X': sendDcsBiosMessage("CDU_X", "0"); break; 
        case 'Y': sendDcsBiosMessage("CDU_Y", "0"); break; 
        case 'Z': sendDcsBiosMessage("CDU_Z", "0"); break;

        case '0': sendDcsBiosMessage("CDU_0", "0"); break; 
        case '1': sendDcsBiosMessage("CDU_1", "0"); break; 
        case '2': sendDcsBiosMessage("CDU_2", "0"); break; 
        case '3': sendDcsBiosMessage("CDU_3", "0"); break; 
        case '4': sendDcsBiosMessage("CDU_4", "0"); break; 
        case '5': sendDcsBiosMessage("CDU_5", "0"); break; 
        case '6': sendDcsBiosMessage("CDU_6", "0"); break; 
        case '7': sendDcsBiosMessage("CDU_7", "0"); break; 
        case '8': sendDcsBiosMessage("CDU_8", "0"); break; 
        case '9': sendDcsBiosMessage("CDU_9", "0"); break;  
        case '.': sendDcsBiosMessage("CDU_POINT", "0"); break; 
        case '/': sendDcsBiosMessage("CDU_SLASH", "0"); break; 
            
        case 'e': sendDcsBiosMessage("CDU_LSK_3R", "0"); break; 
        case 'f': sendDcsBiosMessage("CDU_LSK_5R", "0"); break;
        case 'g': sendDcsBiosMessage("CDU_LSK_7R", "0"); break;
        case 'h': sendDcsBiosMessage("CDU_LSK_9R", "0"); break;
    
        case 'a': sendDcsBiosMessage("CDU_LSK_3L", "0"); break; 
        case 'b': sendDcsBiosMessage("CDU_LSK_5L", "0"); break;
        case 'c': sendDcsBiosMessage("CDU_LSK_7L", "0"); break;
        case 'd': sendDcsBiosMessage("CDU_LSK_9L", "0"); break;
        
        case '[': sendDcsBiosMessage("CDU_PG", "1"); break; 
        case ']': sendDcsBiosMessage("CDU_PG", "1"); break; 
    
        case '>': sendDcsBiosMessage("CDU_DATA", "1"); break; 
        case '<': sendDcsBiosMessage("CDU_DATA", "1"); break; 
        
        case 'i': sendDcsBiosMessage("CDU_SYS", "0"); break; 
        case 'j': sendDcsBiosMessage("CDU_NAV", "0"); break; 
        case 'k': sendDcsBiosMessage("CDU_WP", "0"); break; 
        case 'l': sendDcsBiosMessage("CDU_OSET", "0"); break; 
        case 'm': sendDcsBiosMessage("CDU_FPM", "0"); break; 
        case 'n': sendDcsBiosMessage("CDU_PREV", "0"); break;  
    
        case 's': sendDcsBiosMessage("CDU_MK", "0"); break; 
        case 'v': sendDcsBiosMessage("CDU_CLR", "0"); break; 
        case 'q': sendDcsBiosMessage("CDU_BCK", "0"); break; 
        case 'r': sendDcsBiosMessage("CDU_SPC", "0"); break; 
        case 'w': sendDcsBiosMessage("CDU_FA", "0"); break; 
      }
  }
  delay(10);
};
