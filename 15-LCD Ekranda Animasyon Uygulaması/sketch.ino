#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
String sat1="Batman";
String sat2="Universitesi";
byte s1=5;
byte s2=12;

void setup() {
  lcd.begin(16, 2);
}

void loop() 
  {
    for (int i = 0; i <= 6; i++) {
        lcd.setCursor(s1, 0);
        lcd.print(sat1[s1-5]);
        s1=s1+1;
        lcd.setCursor(s2, 1);
        lcd.print(char(sat2[s2-2]));
        lcd.print(char(sat2[s2-1]));
        s2=s2-2;
        delay(250);
      }

    for (int i = 0; i <= 7; i++) {
        lcd.setCursor(s1, 0);
        lcd.print(" ");
        s1=s1-1;
        lcd.setCursor(s2, 1);
        lcd.print("  ");
        s2=s2+2;
        delay(250);
      }
    delay(500);   
    s1=5;
    s2=12;     
  }