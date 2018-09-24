void setup() {
  // put your setup code here, to run once:
  //int x=10;
Serial.begin(9600);
//Serial.print(x);
  
}

void loop() {
  // put your main code here, to run repeatedly:
int val;
val= analogRead(0);
Serial.println(val);
delay (100);

}
