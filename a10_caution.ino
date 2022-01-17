/*
  Tell DCS-BIOS to use a serial connection and use interrupt-driven
  communication. The main program will be interrupted to prioritize
  processing incoming data.
  
  This should work on any Arduino that has an ATMega328 controller
  (Uno, Pro Mini, many others).
 */
#define DCSBIOS_IRQ_SERIAL

#include "DcsBios.h"

/* paste code snippets from the reference documentation here */

DcsBios::LED clA1(0x10d4, 0x0001, 53);
DcsBios::LED clA2(0x10d4, 0x0002, 52);
DcsBios::LED clA3(0x10d4, 0x0004, 51);
DcsBios::LED clA4(0x10d4, 0x0008, 50);

DcsBios::LED clB1(0x10d4, 0x0010, 49);
DcsBios::LED clB2(0x10d4, 0x0020, 48);
DcsBios::LED clB3(0x10d4, 0x0040, 47);
DcsBios::LED clB4(0x10d4, 0x0080, 46);

DcsBios::LED clC1(0x10d4, 0x0100, 45);
DcsBios::LED clC2(0x10d4, 0x0200, 44);
DcsBios::LED clC3(0x10d4, 0x0400, 43);
DcsBios::LED clC4(0x10d4, 0x0800, 42);

DcsBios::LED clD1(0x10d4, 0x1000, 41);
DcsBios::LED clD2(0x10d4, 0x2000, 40);
DcsBios::LED clD3(0x10d4, 0x4000, 39);
DcsBios::LED clD4(0x10d4, 0x8000, 38);

DcsBios::LED clE1(0x10d6, 0x0001, 37);
DcsBios::LED clE2(0x10d6, 0x0002, 36);
DcsBios::LED clE3(0x10d6, 0x0004, 35);
DcsBios::LED clE4(0x10d6, 0x0008, 34);

DcsBios::LED clF1(0x10d6, 0x0010, 33);
DcsBios::LED clF2(0x10d6, 0x0020, 32);
DcsBios::LED clF3(0x10d6, 0x0040, 31);
DcsBios::LED clF4(0x10d6, 0x0080, 30);

DcsBios::LED clG1(0x10d6, 0x0100, 29);
DcsBios::LED clG2(0x10d6, 0x0200, 28);  //l-main pump inop
DcsBios::LED clG3(0x10d6, 0x0400, 27);
DcsBios::LED clG4(0x10d6, 0x0800, 26);

DcsBios::LED clH1(0x10d6, 0x1000, 25);
DcsBios::LED clH2(0x10d6, 0x2000, 24);  
DcsBios::LED clH3(0x10d6, 0x4000, 23);
DcsBios::LED clH4(0x10d6, 0x8000, 22); 

DcsBios::LED clI1(0x10d8, 0x0001, 17);
DcsBios::LED clI2(0x10d8, 0x0002, 16);
DcsBios::LED clI3(0x10d8, 0x0004, 15);
DcsBios::LED clI4(0x10d8, 0x0008, 14);

DcsBios::LED clJ1(0x10d8, 0x0010, 13);
DcsBios::LED clJ2(0x10d8, 0x0020, 12);
DcsBios::LED clJ3(0x10d8, 0x0040, 11);
DcsBios::LED clJ4(0x10d8, 0x0080, 10);

DcsBios::LED clK1(0x10d8, 0x0100, 9);
DcsBios::LED clK2(0x10d8, 0x0200, 8);
DcsBios::LED clK3(0x10d8, 0x0400, 7);
DcsBios::LED clK4(0x10d8, 0x0800, 6);

DcsBios::LED clL1(0x10d8, 0x1000, 5);
DcsBios::LED clL2(0x10d8, 0x2000, 4);
DcsBios::LED clL3(0x10d8, 0x4000, 3);
DcsBios::LED clL4(0x10d8, 0x8000, 2);

void setup() {
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
}

