#include <PS2X_lib.h>
//#include <avr/wdt.h>

#define PS2_DAT 43
#define PS2_CMD 42
#define PS2_SEL 41
#define PS2_CLK 40

//ความไวมอเตอร์
int SPEED = 50;

//Moter A
int R1G     = 12;
int R1B     = 13;
int SPEEDR1 = 2;

//Moter B
int R2G     = 15;
int R2B     = 16;
int SPEEDR2 = 3;

//Motor C
int R3G     = 18;
int R3B     = 19;
int SPEEDR3  = 4;

//Motor D
int R4G     = 21;
int R4B     = 22;
int SPEEDR4  = 5;

PS2X ps2x;
void setup() {
 // wdt_enable(WDTO_1S);
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

  //เซ็ตค่าOUTPUT-INPUT
  //moter A
  pinMode(R1G, OUTPUT);
  pinMode(R1B, OUTPUT);
  pinMode(SPEEDR1, OUTPUT);
  //moter B
  pinMode(R2G, OUTPUT);
  pinMode(R2B, OUTPUT);
  pinMode(SPEEDR2, OUTPUT);
  //moter C
  pinMode(R3G, OUTPUT);
  pinMode(R3B, OUTPUT);
  pinMode(SPEEDR3, OUTPUT);
  //moter D
  pinMode(R4G, OUTPUT);
  pinMode(R4B, OUTPUT);
  pinMode(SPEEDR4, OUTPUT);
}

void loop() {
  ps2x.read_gamepad(false, false);
  if (ps2x.Button(PSB_PAD_UP)) {
    Serial.print("UP");
      Serial.println(ps2x.Button(PSB_PAD_UP));
  }else if (ps2x.Button(PSB_PAD_DOWN)) {
    Serial.print("down");
      Serial.println(ps2x.Button(PSB_PAD_DOWN));
  }else if (ps2x.Button(PSB_PAD_LEFT)) {
    Serial.print("left");
      Serial.println(ps2x.Button(PSB_PAD_LEFT));
  }else if (ps2x.Button(PSB_PAD_RIGHT)) {
    Serial.print("right");
      Serial.println(ps2x.Button(PSB_PAD_RIGHT));
  }
}
