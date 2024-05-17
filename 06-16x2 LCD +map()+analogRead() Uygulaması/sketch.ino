#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
int kE=0;

void setup() {
  lcd.begin(16, 2);
  lcdYaz(0);  
}

void loop() {
  byte kY=map(analogRead(A5),0,1023,0,4);
  if (kE!=kY)
    {
      lcdYaz(kY);
      kE=kY;
    } 
}

void lcdYaz(int k)
  {
    lcd.clear();
    lcd.setCursor(3+k,0);
    lcd.print("Batman");
    lcd.setCursor(0+k,1);
    lcd.print("Universitesi");    
  }