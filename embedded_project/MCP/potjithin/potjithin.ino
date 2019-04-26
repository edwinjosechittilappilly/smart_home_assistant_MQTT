#include "DigiPot.h"

const int numReadings = 200;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
int inputPin = A0;
DigiPot mcp4261(D2, D7, D5); //Start a new instance called "mcp4251"
//format: DigiPot <instance>(CS, SCK, SDI)

void setup()
{
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;
  //Set the Digital pot to 0 Ohms
  mcp4261.clear(0); //clear both pots; they default to 127
  mcp4261.clear(1); //format: <instance>.clear(pot)....pot is either 0 or 1
}

void loop() {
  // subtract the last reading:
  total = total - readings[index];
  // read from the sensor:
  readings[index] = analogRead(inputPin);
  // add the reading to the total:
  total = total + readings[index];
  // advance to the next position in the array:
  index = index + 1;

  // if we're at the end of the array...
  if (index >= numReadings)
    // ...wrap around to the beginning:
    index = 0;

  // calculate the average:
  average = total / numReadings;
  // send it to the computer (as ASCII digits)
  float distance = 12343.85 * pow(analogRead(average), -1.15);

  int range = map(distance, 8, 70, 0, 10);
  //Need to increase the amount of switches to be maped or use Else If statements

  // do something different depending on the
  // range value:
  switch (range) {
    case 0:    // your hand is on the sensor
      Serial.println("Full Volume");
      mcp4261.write(0, 255);
      delay(1000);
      break;
    case 1:    // your hand is close to the sensor
      Serial.println("Loud");
      mcp4261.write(0, 0);
      break;
    case 2:    // your hand is a few inches from the sensor
      Serial.println("3/4 Volume");
      mcp4261.write(0, 0);
      break;
    case 3:    // your hand is nowhere near the sensor
      Serial.println("Half Volume");
      mcp4261.write(0, 0);
      break;
    case 4:    // your hand is nowhere near the sensor
      Serial.println("Half Volume");
      mcp4261.write(0, 0);
      break;
    case 5:    // your hand is nowhere near the sensor
      Serial.println("Half Volume");
      mcp4261.write(0, 0);
      break;
    case 6:    // your hand is nowhere near the sensor
      Serial.println("Quiet");
      mcp4261.write(0, 0);
      break;
    case 7:    // your hand is nowhere near the sensor
      Serial.println("Silent");
      mcp4261.write(0, 0);
      break;
    case 8:    // your hand is nowhere near the sensor
      Serial.println("Silent");
      mcp4261.write(0, 0);
      break;
    case 9:    // your hand is nowhere near the sensor
      Serial.println("Silent");
      mcp4261.write(0, 0);
      break;
  }
}
