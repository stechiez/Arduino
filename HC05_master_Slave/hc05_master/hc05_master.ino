#include <SoftwareSerial.h>

#define BT_NAME   "BT_Master"

#define SLAVE_ADDRESS "98d3,31,8095c3"  //98d3:31:8095c3

SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
  Serial.begin(38400);

  mySerial.begin(38400);
  Serial.println("Arduino Sender");

  mySerial.print("AT\r\n");
  updateSerial();
  delay(200);
  mySerial.print("AT+RMAAD\r\n");
  updateSerial();
  delay(200);
  mySerial.print("AT+ROLE=1\r\n");
  updateSerial();
  delay(200);  
  mySerial.print("AT+NAME="+String(BT_NAME)+"\r\n");
  updateSerial();
  delay(200);
  mySerial.print("AT+PSWD=\"1234\"\r\n");
  updateSerial();
  delay(200);
  mySerial.print("AT+BIND="+String(SLAVE_ADDRESS)+"\r\n");
  updateSerial();
  delay(200);
  mySerial.print("AT+UART=38400,0,0\r\n");
  updateSerial();
  delay(500);
  mySerial.print("AT+UART?\r\n");
  updateSerial();
  delay(200);
}

void updateSerial(void)
{
}

void loop()
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}
