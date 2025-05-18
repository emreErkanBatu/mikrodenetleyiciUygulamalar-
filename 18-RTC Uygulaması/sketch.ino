#include <LiquidCrystal.h>
#include <RTClib.h>
#include <Servo.h>
RTC_DS1307 zaman;
Servo Servo1;
byte saat,dk,sn;
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  pinMode(6, OUTPUT);
  lcd.begin(16, 2);
  zaman.begin();
  Servo1.attach(5);
}

void loop() {
  saat=zaman.now().hour();
  dk=zaman.now().minute();
  sn=zaman.now().second();
  byte konum;
  LCDyaz();
  if(sn>9 and sn<31) digitalWrite(6, HIGH); else digitalWrite(6, LOW);
  if(sn>14 and sn<26) Servo1.write(90); else Servo1.write(0);
  delay(500);  
}

void LCDyaz()
  {
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("Saat");
    lcd.setCursor(4,1);
    lcd.print(hane(saat)+":"+hane(dk)+":"+hane(sn));
  }

String hane(int sayi)
  {
    String sonuc=String(sayi);
    if (sayi<10) sonuc="0"+sonuc;
    return sonuc;
  }