#include <PS2X_lib.h>
#include <Wire.h>

#define PS2_DAT 47
#define PS2_CMD 46
#define PS2_SEL 45
#define PS2_CLK 44

int set = 0;
boolean mode = false;

int Address2 = 10;

PS2X ps2x;
void setup() {
  
  delay(1000);
  Wire.begin();
  Serial.begin(9600);
  Serial.println("กำลังเชื่อมต่อ...");
  while (true) {
    int error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);
    if (error == 0) {
      Serial.println("เชื่อมต่อแล้ว");
      delay(1000);
      break;
    }
    delay(500);
  }
}

void loop() {
  ps2x.read_gamepad(false, false);
  if(ps2x.Button(PSB_SELECT)){
    set += 1;
  }
  if(set == 0){
    mode == false;
  }else if(set == 1){
    mode == true;
  }else if(set > 1){
    set = 0;
  }
  manual();
  gear();
  delay(10);
}
void manual(){
  if(mode == false){
    int RX = map(ps2x.Analog(PSS_RX),0,255,-1,1);
    int LX = map(ps2x.Analog(PSS_RY),0,255,-1,1);
    int LY = map(ps2x.Analog(PSS_LY),0,255,-1,1);
    if(RX == 1){
      Wire.beginTransmission(Address2);
      Wire.write("RX1");
      delay(5);
    }else if(RX == -1){
      Wire.beginTransmission(Address2);
      Wire.write("RX-1");
      delay(5);
    }else if(LX == 1){
      Wire.beginTransmission(Address2);
      Wire.write("LX1");
      delay(5);
    }else if(LX == -1){
      Wire.beginTransmission(Address2);
      Wire.write("LX-1");
      delay(5);
    }else if(LY == 1){
      Wire.beginTransmission(Address2);
      Wire.write("LY-1");
      delay(5);
    }else if(LY == -1){
      Wire.beginTransmission(Address2);
      Wire.write("LY-1");
      delay(5);
    }else{
       Wire.endTransmission();
    }
  }
  delay(5);
}

void gear(){
  if(mode == false){
if(ps2x.Button(PSB_R1)){
      Wire.beginTransmission(Address2);
      Wire.write("50");
      delay(5);
  }else if(ps2x.Button(PSB_R2)){
      Wire.beginTransmission(Address2);
      Wire.write("255");
      delay(5);
  }else{
      Wire.beginTransmission(Address2);
      Wire.write("100");
      delay(5);
      Wire.endTransmission();    
    }
  delay(5);
  }
}

void playAuto(){
  if(mode == true){
    
  }
}
