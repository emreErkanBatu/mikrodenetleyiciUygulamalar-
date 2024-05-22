#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
int gE=1;
int aE=1;
int yE=0;

void setup() {
  lcd.begin(16, 2);
  lcdYaz();  
}

void loop() {
  byte gY=map(analogRead(A5),0,1023,1,31);
  byte aY=map(analogRead(A4),0,1023,1,12);
  byte yY=map(analogRead(A3),0,1023,0,99);
  if (gE!=gY || aE!=aY || yE!=yY)
    {
      gE=gY;
      aE=aY;
      yE=yY;
      lcdYaz();      
    } 
}

void lcdYaz()
  {
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("Tarih");
    lcd.setCursor(3,1);
    lcd.print(hane(gE)+".");   
    lcd.print(hane(aE)+".");  
    lcd.print("20"+hane(yE));   
  }

String hane(int sayi)
  {
    String sonuc=String(sayi);
    if (sayi<10) sonuc="0"+sonuc;
    return sonuc;
  }