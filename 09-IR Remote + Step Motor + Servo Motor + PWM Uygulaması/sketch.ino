#include <IRremote.h>
#include <Servo.h>
IRrecv receiver(2);
Servo Servo;
byte sec=1;
byte sinyal;
byte servoPos=0;
byte ledPWM=0;
void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Servo.attach(5);
  Servo.write(servoPos);
  receiver.enableIRIn();
}

void loop() {
  if(receiver.decode())
    {
      sinyal=receiver.decodedIRData.command;
      if (sinyal==48)sec=1;
      if (sinyal==24)sec=2;
      if (sinyal==122)sec=3;

      if (sinyal==2)
        {
          if(sec==1)stepHareket(3,4,1,10,5);
          if(sec==2 && servoPos<=170) {servoPos=servoPos+10; Servo.write(servoPos);}
          if(sec==3 && ledPWM<=200){ledPWM=ledPWM+50;analogWrite(6,ledPWM);}

        }

      if (sinyal==152)
        {
          if(sec==1)stepHareket(3,4,0,10,5);
          if(sec==2 && servoPos>=10) {servoPos=servoPos-10; Servo.write(servoPos);}
          if(sec==3 && ledPWM>=50){ledPWM=ledPWM-50;analogWrite(6,ledPWM);}
        }
      receiver.resume();
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
