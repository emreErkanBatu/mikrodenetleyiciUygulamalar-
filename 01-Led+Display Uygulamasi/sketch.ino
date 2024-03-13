byte rakamlar[6]={0x3F,0x06,0x5B,0x4F,0x66,0x6D};
byte ledler[6]={0x00,0x01,0x03,0x07,0x0F,0x1F};

void setup() 
  {
    DDRD=0xFF;
    DDRB=0xFF;
  }

void loop() 
  {
    for (int i=0; i<6;++i)goster(i);
  }

void goster(byte i)
  {
  PORTD=rakamlar[i];
  PORTB=ledler[i];
  delay(1000);
  }
