int led[3]={11,10,9};
unsigned long eZ=millis();
unsigned long yZ=millis();
byte ledSec=0;

void setup() 
  {
    DDRB=0xFF;
    pinMode(4, INPUT_PULLUP);
    PORTB=0x80;
  }

void loop() 
  {
    yZ=millis();

    if (yZ-eZ>1000)
      {
        eZ=millis();
        yZ=millis();
        if (ledSec==0)ledDegis(led[0],led[1],led[2]);
        if (ledSec==1)ledDegis(led[1],led[0],led[2]);
        if (ledSec==2)ledDegis(led[2],led[0],led[1]);
      }

    if (digitalRead(4)==0)
      {
        while(digitalRead(4)==0);
        ledSec=ledSec+1;
        if (ledSec==3)ledSec=0;
      }    
  }

void ledDegis(int a,int b,int c)
  {
    digitalWrite(a, !digitalRead(a));
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
  }
