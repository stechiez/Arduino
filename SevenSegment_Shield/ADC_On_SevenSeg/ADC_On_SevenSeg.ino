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
    adcVal = analogRead(A1);
    sevseg.setNumber(adcVal, 4);
    sevseg.refreshDisplay(); 
}
