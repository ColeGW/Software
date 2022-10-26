#include <Arduino.h>
#include <MaxBotix.h>
#include <Romi32U4Buttons.h>

MaxBotixPulse mbPulse(2);

/**
 * ISR for managing pulses. Putting the ISR in the main file is an alternative to using 
 * extern. It is up to the developer to attach the interrupt.
*/
void MB_ISR(void)
{
  mbPulse.mbISR();
}

void setup() 
{
  Serial.begin(115200);
  Serial.print("Welcome!\n");
  
  mbPulse.init();

  // and attach the interrupt here
  attachInterrupt(digitalPinToInterrupt(1), MB_ISR, CHANGE);
}

void loop()
{
  float distance = 0;
  if(mbPulse.getDistance(distance))
  {
    Serial.print(millis());
    Serial.print('\t');
    Serial.print(distance);
    Serial.print('\n');
  }
}
