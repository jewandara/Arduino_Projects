#include<TimerOne.h>
boolean state=false;// 
void setup() {
  // put your setup code here, to run once:
Timer1.initialize(1000000);
Timer1.attachInterrupt(TimerISR);
pinMode(2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}
void TimerISR(){
 // digitalWrite(2,~state);
 state=!state;
 digitalWrite(2,state);
 
}
