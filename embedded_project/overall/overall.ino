//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;
int incomingByte = 0;
int state = 0;
int cntrlbit = 0;
int ln;
byte leds = 0;    // Variable to hold the pattern of which LEDs are currently turned on or off

/*
   setup() - this function runs once when you turn your Arduino on
   We initialize the serial connection with the computer
*/
void setup()
{
  Serial.begin(9600);
  // Set all the pins of 74HC595 as OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

/*
   loop() - this function runs over and over again
*/
void loop()
{
  // send data only when you receive data:
  while (Serial.available()) {
    // read the incoming byte:
    incomingByte = Serial.parseInt();

    // say what you got:
    Serial.println("I received: ");
    Serial.println(incomingByte);
    Serial.flush();
    //delay(500);
    control(incomingByte);
  }
}

void control(int incomingByte)
{
  cntrlbit = incomingByte;
  state = cntrlbit % 10;
  Serial.println("state");
  Serial.println(state);
  cntrlbit = cntrlbit / 10;
  ln = cntrlbit % 10;
  Serial.println("led");
  Serial.println(ln);
  if (state == 0) {
    bitClear(leds, ln);
  }
  else if (state == 1)
    bitSet(leds, ln);
  updateShiftRegister();
  delay(250);
}
/*
   updateShiftRegister() - This function sets the latchPin to low, then calls the Arduino function 'shiftOut' to shift out contents of variable 'leds' in the shift register before putting the 'latchPin' high again.
*/

void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}
