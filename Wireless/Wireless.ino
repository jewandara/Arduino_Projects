#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

char activationPassword[8] = {
  '#', '9', '1', '2', '3', '4', '5', '*'};

char deactivationPassword[8] = {
  '#', '8', '5', '4', '3', '2', '1', '*'};

boolean systemActive = false;
char userData[8];
int i = 0;

void setup() {
  pinMode(7, OUTPUT);  // Green
  pinMode(6, OUTPUT);  // Red
  pinMode(8, OUTPUT);  // L1
  pinMode(9, OUTPUT);  // L2
  lcd.begin(16,2);
  Serial.begin(9600);
  Serial1.begin(9600);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  lcd.print("System INACTIVE");  
  lcd.setCursor(0,1);
  lcd.print("L1=OFF , L2=OFF");  
}

void loop() {
  if(Serial1.available() > 0) {
    userData[i] = Serial1.read();
    Serial.print(userData[i]);
    i++;
  }

  if(i == 8) {
    if(userData[0] == '#' && userData[7] == '*') {
      if(userData[1] == '9') {
        // Check activation pass
        systemActive = true;
        i = 0;
        while(i < 8) {
          if(userData[i] == activationPassword[i]) {
            i++;
          }
          else{
            systemActive = false;
            i = 8;
          }
        }
        i = 0;
        if(systemActive) {
          digitalWrite(7, HIGH);
          digitalWrite(6, LOW);
          lcd.clear();
          lcd.print("System ACTIVE");
          lcd.setCursor(0,1);
          lcd.print("L1=OFF , L2=OFF"); 
        }
      }
      else if(userData[1] == '8') {
        // Check deactivation pass
        systemActive = false;
        i = 0;
        while(i < 8) {
          if(userData[i] == deactivationPassword[i]) {
            i++;
          }
          else{
            systemActive = true;
            i = 8;
          }
        }
        i = 0;
        if(!systemActive) {
          digitalWrite(7, LOW);
          digitalWrite(6, HIGH);
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          lcd.clear();
          lcd.print("System INACTIVE");
          lcd.setCursor(0,1);
          lcd.print("L1=OFF , L2=OFF"); 
        }
      }
      else if(userData[1] == '6' && systemActive) {
        int delayTime = 0;
        if((userData[2] == '0') && (userData[3] == '1')) {
          // L1
          if(userData[4] == '0') {
            // Sec
            delayTime = ((userData[5] - 48) * 10 + (userData[6] - 48)) * 1000;
          }
          else if(userData[4] == '1') {
            // Min
            delayTime = ((userData[5] - 48) * 10 + (userData[6] - 48)) * 60 * 1000;
          }
          digitalWrite(8, HIGH);
          lcd.setCursor(0,1);
          lcd.print("L1=ON ");
          
          delay(delayTime);
          
          digitalWrite(8, LOW);
          lcd.setCursor(0,1);
          lcd.print("L1=OFF");
        }
        else if((userData[2] == '0') && (userData[3] == '2')) {
          // L2
          if(userData[4] == '0') {
            // Sec
            delayTime = ((userData[5] - 48) * 10 + (userData[6] - 48)) * 1000;
          }
          else if(userData[4] == '1') {
            // Min
            delayTime = ((userData[5] - 48) * 10 + (userData[6] - 48)) * 60 * 1000;
          }
          digitalWrite(9, HIGH);
          lcd.setCursor(9,1);
          lcd.print("L2=ON ");
          
          delay(delayTime);
          
          digitalWrite(9, LOW);
          lcd.setCursor(9,1);
          lcd.print("L2=OFF");
        }
        i = 0;
      }
    }
  }
  else if(i == 6) {
    if(userData[0] == '#' && userData[5] == '*') {
      i = 0;
      if(userData[1] == '7' && systemActive) {
        if((userData[2] == '0') && (userData[3] == '1')) {
          // L1
          if(userData[4] == '0') {
            digitalWrite(8, LOW);
            lcd.setCursor(0,1);
            lcd.print("L1=OFF");
          }
          else if(userData[4] == '1') {
            digitalWrite(8, HIGH);
            lcd.setCursor(0,1);
            lcd.print("L1=ON ");
          }
        }
        else if((userData[2] == '0') && (userData[3] == '2')) {
          // L2
          if(userData[4] == '0') {
            digitalWrite(9, LOW);
            lcd.setCursor(9,1);
            lcd.print("L2=OFF");
          }
          else if(userData[4] == '1') {
            digitalWrite(9, HIGH);
            lcd.setCursor(9,1);
            lcd.print("L2=ON ");
          }
        }       
      }
    }
  }
}














