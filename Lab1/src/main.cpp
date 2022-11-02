// #include <Arduino.h>
// #include "Timer.h"
// #include <Romi32U4.h>
// #include <Chassis.h>

// int AOpin = 18;
// int result = 13;
// long now = 0;
// long sampleTime = 39;
// long timeToPrint;
// long lastTime = 0;

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   pinMode(AOpin, INPUT);
//   pinMode(result, OUTPUT);
//   //chassis.init();
//   delay(5000); 
// }

// double ADCValue = 0;
// int count = 0;
// double Voltage = 0;
// double Distance = 0;
// double Vref = 5;
// double bits = 1023;
// void loop() {
  
  // put your main code here, to run repeatedly:
  // int holder = analogRead(AOpin);
  // if(holder > 409) //ADC 
  // digitalWrite(result, LOW);
  // if(holder < 205)
  // digitalWrite(result, HIGH);
// timeToPrint = millis() + sampleTime;
// if ((now = millis()) > timeToPrint)
// {
  
// //   timeToPrint = now + sampleTime;
// // }

// uint32_t currentTime = millis();
if(currentTime - lastTime >= sampleTime  && count < 200)
{
  count++;
ADCValue = analogRead(AOpin);
Voltage = ADCValue / bits * Vref;
Distance = 15.849/(Voltage - 0.5071);  //from equation
Serial.print(ADCValue);
Serial.print("\t");
Serial.print(Voltage);
Serial.print("\t");
Serial.print(Distance);
Serial.println();

 lastTime = currentTime;
}
  

// }


#include <Arduino.h>
#include <MaxBotix.h>
#include <Romi32U4Buttons.h>
#include <PCint.h>


MaxBotixAnalog mbAnalog(A0);
MaxBotixSerial mbSer; 
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
  //Serial.print("Welcome!\n");
  
  mbPulse.init();
  mbAnalog.init();
  mbSer.init();
  // and attach the interrupt here
  attachInterrupt(digitalPinToInterrupt(1), MB_ISR, CHANGE);
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
