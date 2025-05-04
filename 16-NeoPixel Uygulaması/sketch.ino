#include <Adafruit_NeoPixel.h> 
#define secBTN 5
#define rBTN 4
#define gBTN 3
#define bBTN 2
byte sec=0;

int rDeg=0;
int gDeg=0;
int bDeg=0;

int ledSayisi = 5; 
int ledPin = 8;        
int parlaklik = 255;
Adafruit_NeoPixel neoLed(ledSayisi, ledPin, NEO_GRB + NEO_KHZ800); 
void setup() 
  {
    pinMode(secBTN, INPUT_PULLUP);
    pinMode(rBTN, INPUT_PULLUP);
    pinMode(gBTN, INPUT_PULLUP);
    pinMode(bBTN, INPUT_PULLUP);
    neoLed.begin();
    neoLed.clear();
    neoLed.setBrightness(parlaklik);    
  }

void loop() 
  {
    if (digitalRead(secBTN)==0)
      {
        sec=sec+1;
        if(sec==5)sec=0;
        ledShow(sec,255,255, 255);
        delay(250);
        rDeg=0;
        gDeg=0;
        bDeg=0;
        ledShow(sec,rDeg,gDeg, bDeg);
      }

    if (digitalRead(rBTN)==0)
      {
       while(digitalRead(rBTN)==0);
       rDeg=rDeg+50;
       if(rDeg==300)rDeg=0;
       ledShow(sec,rDeg,gDeg, bDeg);
      }
    
    if (digitalRead(gBTN)==0)
      {
       while(digitalRead(gBTN)==0);
       gDeg=gDeg+50;
       if(gDeg==300)gDeg=0;
       ledShow(sec,rDeg,gDeg, bDeg);
      }

    if (digitalRead(bBTN)==0)
          {
          while(digitalRead(bBTN)==0);
          bDeg=bDeg+50;
          if(bDeg==300)bDeg=0;
          ledShow(sec,rDeg,gDeg, bDeg);
          }        
  }

void ledShow(int i,byte r,byte g, byte b)
  {
    neoLed.setPixelColor(i, neoLed.Color(r, g, b));
    neoLed.show();
    delay(50);    
  }