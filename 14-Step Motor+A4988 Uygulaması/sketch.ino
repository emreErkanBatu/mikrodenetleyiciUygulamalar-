#define sag 2
#define sol 3
#define DIR 8
#define STEP 9

void setup() 
  {
    pinMode(sag, INPUT_PULLUP);
    pinMode(sol, INPUT_PULLUP);
    DDRB=0xFF;
  }

void loop() 
  {
     if(digitalRead(sag)==0)
      {
        while(digitalRead(sag)==0);
        stepHareket(DIR,STEP,1, 50,5);        
      }
    
    if(digitalRead(sol)==0)
      {
        while(digitalRead(sol)==0);
        stepHareket(DIR,STEP,0, 50,5);
      }   
  }

void stepHareket(int dirPin,int stepPin,bool yon, int step,int t)
  {
    digitalWrite(dirPin, yon);
    for(int i=0;i<step;++i)
      {
        digitalWrite(stepPin, HIGH);
        delay(t);
        digitalWrite(stepPin, LOW);
        delay(t);
      }
  }