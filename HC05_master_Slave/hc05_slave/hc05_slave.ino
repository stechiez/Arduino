#include <SoftwareSerial.h>

#define BT_NAME   "BT_Slave"

SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
  Serial.begin(38400);

  mySerial.begin(38400);
  Serial.println("Arduino receiver");

  mySerial.print("AT\r\n");
  delay(200);
  mySerial.print("AT+RMAAD\r\n");
  delay(200);
  mySerial.print("AT+ADDR?\r\n");
  delay(200);

  mySerial.print("AT+NAME="+String(BT_NAME)+"\r\n");
  delay(200);
  mySerial.print("AT+PSWD=\"1234\"\r\n");
  delay(200);
  mySerial.print("AT+ROLE?\r\n");
  delay(200);
  mySerial.print("AT+UART=38400,0,0\r\n");
  delay(500);
}

void loop()
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}
