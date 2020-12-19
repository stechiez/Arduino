#include <LiquidCrystal.h>

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int adcVal;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("STechiezDIY Sol.");
}

void loop() {
    adcVal = analogRead(A0);
    
    if(adcVal>=150&&adcVal<=190)
    {
      lcd.setCursor(0, 1);  
      lcd.print("UP key is Pressed");
    }
    else if(adcVal>=350&&adcVal<=380)
    {
      lcd.setCursor(0, 1);  
      lcd.print("Down key is Pressed");
    }
    else if(adcVal>=540&&adcVal<=560)
    {
      lcd.setCursor(0, 1);  
      lcd.print("LEFT key is Pressed");
    }
    else if(adcVal>=750&&adcVal<=760)
    {
      lcd.setCursor(0, 1);  
      lcd.print("RIGHT key is Pressed");
    }
    else if(adcVal>=900)
    {
      lcd.setCursor(0, 1);  
      lcd.print("OK key is Pressed");
    }
}
