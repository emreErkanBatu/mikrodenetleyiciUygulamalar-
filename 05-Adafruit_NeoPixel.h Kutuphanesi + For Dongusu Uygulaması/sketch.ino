#include <Adafruit_NeoPixel.h> 
int ledSayisi = 16; 
int ledPin = 8;        
int parlaklik = 255;
Adafruit_NeoPixel neoLed(ledSayisi, ledPin, NEO_GRB + NEO_KHZ800); 
void setup() 
  {
    neoLed.begin();
    neoLed.clear();
    neoLed.setBrightness(parlaklik);    
  }

void loop() 
  {
    for(int i=0;i<16;++i) ledShow(i,255,0,0);
    for(int i=0;i<16;++i) ledShow(i,0,255,0);
    for(int i=0;i<16;++i) ledShow(i,0,0,255);       
  }

void ledShow(int i,byte r,byte g, byte b)
  {
    neoLed.setPixelColor(i, neoLed.Color(r, g, b));
    neoLed.show();
    delay(50);    
  }
