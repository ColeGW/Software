#include <Arduino.h>
#include <PCint.h>
#include <MaxBotix.h>

MaxBotixSerial mbSer; // no pin given because it uses Serial1 -- see the pinout diagram

void setup() 
{
  Serial.begin(115200);
  Serial.print("Welcome!\n");
  
  mbSer.init();
}

void loop()
{
  float distance = 0;
  if(mbSer.getDistance(distance))
  {
    Serial.print(millis());
    Serial.print('\t');
    Serial.print(distance);
    Serial.print('\n');
  }
}
