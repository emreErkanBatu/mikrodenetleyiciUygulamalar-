int a=3;
int b=5;
int c=7;

void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);  
}

void loop() {  
  hesapla(8,3,5,1);
  hesapla(9,5,8,-3);
  hesapla(10,11,-5,12);
}

void hesapla(byte butonNo,int k1,int k2, int k3)
  {
    long sonuc;
  	if(digitalRead(butonNo)==0)
    	{
         while(digitalRead(butonNo)==0);
         if(butonNo==8)sonuc=k1*a*a+k2*b+k3*c;
      	 if(butonNo==9)sonuc=k1*a*a*a+k2*b*b+k3*c;
         if(butonNo==10)sonuc=k1*a*a*a*a+k2*b*b*b+k3*c*c;
      	 Serial.print("Sonuc:");
    	 Serial.println(sonuc);
    	}
  }
