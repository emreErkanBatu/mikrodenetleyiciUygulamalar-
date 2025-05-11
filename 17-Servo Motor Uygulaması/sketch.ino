#include <LiquidCrystal.h>
#include <Servo.h>

Servo Servo1;
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
int aci=0;

void setup() 
  {
    pinMode(A0, INPUT_PULLUP);
    pinMode(A1, INPUT_PULLUP);
    lcd.begin(16, 2);
    Servo1.attach(A2);
    Servo1.write(aci);
    lcd.clear();
    lcd.print("Konum:"+String(aci)+" Derece"); 
  }

void loop() 
  {
    if(digitalRead(A0)==0)
      {      
        while(digitalRead(A0)==0);
        if (aci>0)aci=aci-10;
        Servo1.write(aci);
        lcd.clear();
        lcd.print("Konum:"+String(aci)+" Derece"); 
      }    
    if(digitalRead(A1)==0)
      {
        while(digitalRead(A1)==0);
        if (aci<180)aci=aci+10;
        Servo1.write(aci);
        lcd.clear();
        lcd.print("Konum:"+String(aci)+" Derece"); 
      }
  }