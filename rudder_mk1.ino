int RudderL;
int RudderR;
int val1;
int val2;
int val3;

void setup() {
  // put your setup code here, to run once:
val3 = 128;
}

void loop() {
  // put your main code here, to run repeatedly:

  RudderL = analogRead(A0);
  RudderR = analogRead(A1);

  //remove after getting values from pots
  //Serial.println("RudderL: ");
  Serial.println(RudderR);
  //Serial.print("\r");

  //Serial.print("RudderR: ");
  //Serial.print(RudderR);
  //Serial.print("\r");

  //val1 = map(RudderL, num1, num2, -128, 0);
  //val2 = map(RudderR, num3, num4, 0, 128);
  val3 = val1 + val2;

  Joystick.Z(val3);

}
