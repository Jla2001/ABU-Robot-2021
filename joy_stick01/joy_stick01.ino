#include <PS2X_lib.h> 

#define PS2_DAT 14
#define PS2_CMD 15
#define PS2_SEL 16
#define PS2_CLK 17
PS2X ps2x;
void setup() {
  delay(1000);
  Serial.begin(9600);
  Serial.println("กำลังเชื่อมต่อ...");
 while(true) { 
  int error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);
    if(error == 0){
      Serial.println("เชื่อมต่อแล้ว");
      delay(1000);
      break;
      }
   delay(500);
  }
}

void loop() {
ps2x.read_gamepad(false, false);
if(ps2x.Button(PSB_CIRCLE))
Serial.println("Circle");
else if(ps2x.Button(PSB_CROSS))
Serial.println("Cross");
else if(ps2x.Button(PSB_SQUARE))
Serial.println("Square");
else if(ps2x.Button(PSB_TRIANGLE))
Serial.println("Triangle");
else if(ps2x.Button(PSB_L1))
Serial.println("L1");
else if(ps2x.Button(PSB_L2))
Serial.println("L2");
else if(ps2x.Button(PSB_L3))
Serial.println("L3");
else if(ps2x.Button(PSB_R1))
Serial.println("R1");
else if(ps2x.Button(PSB_R2))
Serial.println("R2");
else if(ps2x.Button(PSB_R3))
Serial.println("R3");
else if(ps2x.Button(PSB_START))
Serial.println("Start");
else if(ps2x.Button(PSB_SELECT))
Serial.println("Select");
else if(ps2x.Button(PSB_PAD_UP))
Serial.println("Up");
else if(ps2x.Button(PSB_PAD_DOWN))
Serial.println("Down");
else if(ps2x.Button(PSB_PAD_LEFT))
Serial.println("Left");
else if(ps2x.Button(PSB_PAD_RIGHT))
Serial.println("Right");
 delay(50);

}
