int led[3]={6,5,3};
byte sec;
void setup() 
  {    

  }

void loop() 
  {
    sec=map(analogRead(A1),0,1023,0,2);
    analogWrite(led[sec],map(analogRead(A0),0,1023,0,255));
  }
