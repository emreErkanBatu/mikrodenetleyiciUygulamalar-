void setup() 
  {
    DDRD=0xFF;   
    stepHareket(3,0,1,49,5);
    stepHareket(4,1,1,52,5);
    stepHareket(5,2,1,52,5);
  }

void loop() 
  {
    for(int i=0;i<3;++i)stepHareket(i+3,i,0,100,5); 
    for(int i=0;i<3;++i)stepHareket(i+3,i,1,100,5);
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
