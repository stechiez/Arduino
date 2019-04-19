#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


Adafruit_MLX90614 mlx = Adafruit_MLX90614();


const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance=0;


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  mlx.begin();  
  
  lcd.setCursor(3, 0);
  lcd.print("STechiez");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Remote Object");  
  lcd.setCursor(0, 1);
  lcd.print("Distance/Temp. Sensor");  
  delay(2000);
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  //read the raw timer value 
  distance= duration*0.034/2;   //Calculate the distance

  
  lcd.clear();
  lcd.print("Distance:");
  lcd.println(distance);
  lcd.setCursor(0, 1);
  lcd.print("Temp.   :");
  lcd.print(mlx.readObjectTempC());
  lcd.println("*C");
  
  delay(500);
}
