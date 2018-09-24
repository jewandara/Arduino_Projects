void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
float temp;
temp=analogRead(0);
temp=temp*0.48828125;
Serial.println(temp);
delay(200);
}
