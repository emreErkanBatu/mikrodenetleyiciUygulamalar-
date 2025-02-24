#define sag A3
#define sol A0

byte durum=1;

void setup() 
  {
    DDRD=0xFF;
    pinMode(sag, INPUT);
    pinMode(sol, INPUT);
  }

void loop() 
  {
    if(digitalRead(sag)==0)
      {
        while(digitalRead(sag)==0);
        durum=durum-1;
        if(durum==0)durum=1;
      }
    
    if(digitalRead(sol)==0)
      {
        while(digitalRead(sol)==0);
        durum=durum+1;
        if(durum==6)durum=5;
      }
    
    if(durum==1)PORTD=0x0F;
    if(durum==2)PORTD=0x1E;
    if(durum==3)PORTD=0x3C;
    if(durum==4)PORTD=0x78;
    if(durum==5)PORTD=0xF0;

  }
