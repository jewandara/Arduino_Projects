void setup() {
  // put your setup code here, to run once:
  pinMode(3,INPUT);
  pinMode(2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 int x;
 
x=digitalRead(3);
   
   if(x==1){
     digitalWrite(2,HIGH);
     
     
}
else{
  digitalWrite(2,LOW);
}
}
