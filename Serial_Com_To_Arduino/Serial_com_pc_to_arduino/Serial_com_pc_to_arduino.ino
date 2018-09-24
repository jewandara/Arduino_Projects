void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
char text;
int state;

state= Serial.available();
if(state>0){
  
  text=Serial.read();
  Serial1.println(text);
 
  
}


}
