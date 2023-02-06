#include <PS2X_lib.h> 

#define PS2_DAT 47
#define PS2_CMD 46
#define PS2_SEL 45
#define PS2_CLK 44
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
    int RX = ps2x.Analog(PSS_LX);
    int RY = ps2x.Analog(PSS_LY);
Serial.print("      LX  ");
Serial.print(RX);
Serial.print("      LY  ");
Serial.println(RY);
delay(400);
}
