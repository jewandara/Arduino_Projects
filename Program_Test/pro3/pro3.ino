 int currentstate=0;
 int state=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(3,INPUT);
  pinMode(2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
/* int x;
 int y;*/
 
 
state=digitalRead(3);
   
   if(state==1){
     
       if(currentstate==0){
         currentstate=1;
         digitalWrite(2,HIGH);
         delay(300);
       }
       else{
          currentstate=0;
         digitalWrite(2,LOW);
         delay(300);
       }
       }
     
    
     
     
    }
    

