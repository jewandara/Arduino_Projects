void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int val;
int dutycycal;
val=analogRead(0);

dutycycal=map(val,0,1023,0,255);
analogWrite(2,dutycycal);
Serial.println(dutycycal);
delay(200);
}
