byte leds[5]={0xF0,0x78,0x3C,0x1E,0x0F};
void setup() 
  {
    DDRD=0xFF;
  }

void loop() 
  {
    int sec=map(analogRead(2),0,1023,0,4);
    PORTD=leds[sec];
  }
