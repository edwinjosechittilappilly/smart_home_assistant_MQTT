/*
this program taken from arduino Example .
  modified by By Mohannad Rawashdeh
  http://www.genotronex.com
https://www.instructables.com/

  This code used to control the digital potentiometer
  MCP41100 connected to  arduino Board
  CS >>> D10
  SCLK >> D13
  DI  >>> D11
  PA0 TO VCC
  PBO TO GND
  PW0 TO led with resistor 100ohm .
*/
#include <SPI.h>
byte address = 0x11;
int CS= D2;
int i=0;

void setup()
{
  pinMode (CS, OUTPUT);
  pinMode(D5,OUTPUT);
  SPI.begin();
  // adjust high and low resistance of potentiometer
  // adjust Highest Resistance .
   digitalPotWrite(0x00);
   delay(1000);
 
      // adjust  wiper in the  Mid point  .
   digitalPotWrite(0x80);
   delay(1000);

   // adjust Lowest Resistance .
   digitalPotWrite(0xFF);
   delay(1000);
}

void loop()
{
  digitalWrite(D5,HIGH);
  digitalPotWrite(255);
  delay(1000);
}

int digitalPotWrite(int value)
{
  digitalWrite(CS, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(CS, HIGH);
}
