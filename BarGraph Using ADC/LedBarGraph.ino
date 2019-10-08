/*
Author : Stechiez Solution
*/

#define NUM_OF_LED  8

const int analogInPin = A1;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the pot
void mapValToBarGraph(uint16_t val,uint16_t max_adc_val,uint8_t led_count);
void ledBarGraph(uint8_t val);

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  sensorValue = analogRead(analogInPin);
  mapValToBarGraph(sensorValue,256,NUM_OF_LED);
  delay(100);
}

void mapValToBarGraph(uint16_t val,uint16_t max_adc_val,uint8_t led_count)
{
	uint16_t valueForEachLed=0;
	uint16_t valToDisplay;
	uint16_t graphVal,i;
	valueForEachLed = max_adc_val / led_count;
	
	valToDisplay = ((val+1) / valueForEachLed);
	graphVal = 0;
	for(i=0;i<valToDisplay;i++)
	{
	  graphVal |=  1 <<i;
	}

	ledBarGraph(graphVal);
}

void ledBarGraph(uint8_t val)
{
  digitalWrite(13, (val & 0x800)?HIGH:LOW);
  digitalWrite(12, (val & 0x400)?HIGH:LOW);
  digitalWrite(11, (val & 0x200)?HIGH:LOW);
  digitalWrite(10, (val & 0x100)?HIGH:LOW);
  digitalWrite(9, (val & 0x080)?HIGH:LOW);
  digitalWrite(8, (val & 0x040)?HIGH:LOW);
  digitalWrite(7, (val & 0x020)?HIGH:LOW);
  digitalWrite(6, (val & 0x010)?HIGH:LOW);
  digitalWrite(5, (val & 0x008)?HIGH:LOW);
  digitalWrite(4, (val & 0x004)?HIGH:LOW);
  digitalWrite(3, (val & 0x002)?HIGH:LOW);
  digitalWrite(2, (val & 0x001)?HIGH:LOW);
  
}