unsigned long yeni=millis();
unsigned long eski=millis();
byte pin[3]={6,5,3};
byte sec=0;
void setup() 
  {  

  }

void loop() 
  {
    yeni=millis();
    if (yeni-eski>=2000)
      {
        eski=millis();
        for(int i=0;i<3;++i)analogWrite(pin[i],0);
        analogWrite(pin[sec],map(analogRead(A5),0,1023,0,255));
        sec=sec+1;
        if(sec==3)sec=0;
      }    

  }
