#include <PS2X_lib.h>

//ขาข้อมูล จอย PS2X
#define PS2_DAT 3
#define PS2_CMD 4
#define PS2_SEL 5
#define PS2_CLK 6

// ตัวแปรยิง
#define shot 8

PS2X ps2x;

void setup() {
  delay(1000);
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
  pinMode(shot, OUTPUT);
}

void loop() {
    ps2x.read_gamepad(false, false);
    if (ps2x.Button(PSB_TRIANGLE) || ps2x.Button(PSB_SQUARE) || ps2x.Button(PSB_CROSS) || ps2x.Button(PSB_CIRCLE)) {
        digitalWrite(shot,LOW);
        Serial.println("shot");
        delay(500);
  }else{
        digitalWrite(shot,HIGH);
  }
}
