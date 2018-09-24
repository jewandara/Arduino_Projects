void setup() {
  // put your setup code here, to run once:
 attachInterrupt(1,detect,RISING);
 
  pinMode(4,OUTPUT);
  pinMode(3,INPUT);
  pinMode(2,OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(2,HIGH);
delay(1000);
digitalWrite(2,LOW);
delay(1000);
}
void detect(){
  
  digitalWrite(4,HIGH);
}
