void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
char text;
int state;


state= Serial.available();
if(state>0){
  
  text=Serial.read();
  Serial.println(text);
  if(text=='R'){
  
    digitalWrite(2,HIGH);
  
  }else if(text=='r'){
  
  digitalWrite(2,LOW);
  
    }else if(text=='G'){

      digitalWrite(3,HIGH);
  
    }else if(text=='g'){

      digitalWrite(3,LOW);
  
}

  
}
 
}
