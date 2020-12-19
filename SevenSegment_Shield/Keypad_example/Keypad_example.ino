#include "SevSeg.h"
SevSeg sevseg; 
int adcVal;

void setup(){
  byte numDigits = 4;
  byte digitPins[] = {13, 12, 11, 10};
  byte segmentPins[] = {7, 6, 5, 4, 3, 2, 9, 8};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = N_TRANSISTORS; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setNumber(0000, 4);
}

void loop(){
    adcVal = analogRead(A0);
    if(adcVal>=150&&adcVal<=190)
    {
      sevseg.setNumber(0001, 4);
    }
    else if(adcVal>=350&&adcVal<=380)
    {
      sevseg.setNumber(0002, 4);      
    }
    else if(adcVal>=540&&adcVal<=560)
    {
      sevseg.setNumber(0003, 4);      
    }
    else if(adcVal>=750&&adcVal<=760)
    {
      sevseg.setNumber(0004, 4);     
    }
    else if(adcVal>=900)
    {
      sevseg.setNumber(0005, 4);      
    }
    sevseg.refreshDisplay(); 
}
