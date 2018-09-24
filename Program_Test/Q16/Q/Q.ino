#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

int i = 0;
char user_pw[8];
char stored_pw[] = {'#','9','1','2','3','4','5','*'};
char turn_off_pw[] = {'#','8','1','2','3','4','5','*'};
char turn_on_light[] = {'#','7','0','1','1','*'};
int system_state = 0;//off

void setup()
{
  pinMode(10,OUTPUT);//red
  pinMode(7,OUTPUT);//green
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  lcd.begin(16,2);
  Serial.begin(9600);
  digitalWrite(10,HIGH);
  digitalWrite(7,LOW);
}
int j = 0;
int k = 0;
int l = 0;
int count_pw = 0;
int count_off_pw = 0;
void loop()
{
  int state;
  state = Serial.available();

  if(state > 0)
  {
    user_pw[i] = Serial.read();
    i = i+1;
  }

  if(i == 8)
  {
    if(user_pw[1] == '9')
    {
      j = 0;
      while(j<8)
      {

        if(user_pw[j] == stored_pw[j])
        {
          count_pw = count_pw + 1;
        }
        else
        {
          system_state = 0;
          digitalWrite(10,system_state);
          digitalWrite(8,HIGH);
          Serial.println("Invalid PassWord");
          //lcd.clear();
          lcd.print("Invalid PassWord");
          delay(700);        
        }
        j = j+1;
      }
    }
    else if(user_pw[1] == '8')
    {
      k = 0;
      while(k<8)
      {

        if(user_pw[k] == turn_off_pw[k])
        {
          count_off_pw = count_off_pw + 1;
        }
        else
        {
          Serial.println("Invalid System ShutDown password"); 
        lcd.print("Invalid System ShutDown password");   
        }
        k = k+1;
      }
    }
  }

  if(count_off_pw == 8)
  {
    system_state = 0;
    count_off_pw = 0;
    i = 0;
    Serial.println("System ShutDown");
    lcd.clear();
    lcd.print("System ShutDown");
    digitalWrite(10,HIGH);
    digitalWrite(7,LOW);
  //  delay(700);
  }


  if(count_pw == 8)
  {
    system_state = 1;
    i = 0;
    Serial.println("System Initiated");
    lcd.println("System Initiated");
    count_pw = 0;
   // delay(700);
  }

  //when the system is turned on
  if(system_state == 1)
  {
    digitalWrite(10,LOW);
    digitalWrite(7,system_state);
    
    
  }

 
}

