
void push();
void setup() {
  // put your setup code here, to run once:
  pinMode(4,OUTPUT);
  pinMode(3,INPUT);
  pinMode(2,OUTPUT);
  

}
void loop() {
  // put your main code here, to run repeatedly:
 push();
digitalWrite(2,HIGH);
delay(1000);
digitalWrite(2,LOW);
delay(1000);

}

void detect() {
  // put your main code here, to run repeatedly:
  if(digitalRead(3)==1){
    
    digitalWrite(4,HIGH);
    
  }
}

