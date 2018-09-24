    
void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
 /* int state;
  int a;*/
    

}

void loop() {
    int state;
    int a;
  // put your main code here, to run repeatedly:
   int state;
  state=digitalRead(2) ;
  
    if(state==0){
      digitalWrite(3,LOW);
      
    }
    if(state==1){
      digitalWrite(3,HIGH);
    }

  /*state=digitalRead(2) ;
  
    if(state==1){
      a=a+1;
      
    }
    if(a==1){
      digitalWrite(3,LOW);
    }
    if(a==2){
       digitalWrite(3,HIGH);
        a=0;
        
    }
}
