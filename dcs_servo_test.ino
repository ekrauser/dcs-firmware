/* use '#define DCSBIOS_DEFAULT_SERIAL' instead if your Arduino board
 *  does not feature an ATMega328 or ATMega2650 controller.
 */
#include <Servo.h>
#define DCSBIOS_DEFAULT_SERIAL
#include "DcsBios.h"

Servo airSpd;
int asn;

void onAirspeedNeedleChange(unsigned int newValue) {
    /* your code here */
    asn = newValue;
    asn = map(asn, 0, 65535, 15, 150);
    airSpd.write(asn);
}

DcsBios::IntegerBuffer airspeedNeedleBuffer(0x107a, 0xffff, 0, onAirspeedNeedleChange);

void setup() {
  airSpd.attach(4);
  airSpd.write(15);
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
}
