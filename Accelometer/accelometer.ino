float x,y,z;
void setup() {

  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,HIGH);
x=analogRead(0);
y=analogRead(1);
z=analogRead(2);

 Serial.print(x);
  Serial.print(" ");
   Serial.print(y);
   Serial.print(" ");
    Serial.print(z);
    Serial.print(" ");
     Serial.println(" ");
  delay(500);
}
