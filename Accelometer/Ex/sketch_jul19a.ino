int x=2;

void setup() {
  // put your setup code here, to run once:
while(x<=11){
  pinMode(x,OUTPUT);
  x=x+1;

}



}

void loop() {
  // put your main code here, to run repeatedly:
 while(x<=11){
   digitalWrite(x,HIGH);
   delay(200);
   digitalWrite(x,LOW);
   x=x+1;
 } 


}
