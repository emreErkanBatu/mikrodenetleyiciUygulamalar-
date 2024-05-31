#include <LiquidCrystal.h>
#include <RTClib.h>
#include <Servo.h>
RTC_DS1307 zaman;
Servo Servo1;
Servo Servo2;
byte saat,dk,sn;
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  lcd.begin(16, 2);
  zaman.begin();
  Servo1.attach(6);
  Servo2.attach(5);
  lcd.print("Hello World!");
}

void loop() {
  saat=zaman.now().hour();
  dk=zaman.now().minute();
  sn=zaman.now().second();
  byte konum;
  LCDyaz();
  konum=sn/10;
  Servo1.write(konum*18);
  Servo2.write(180-konum*18);
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