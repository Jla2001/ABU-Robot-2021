#include <PS2X_lib.h>
//#include <avr/wdt.h>

#define PS2_DAT 13
#define PS2_CMD 12
#define PS2_SEL 11
#define PS2_CLK 10

//ความไวมอเตอร
int SPEED = 100;
int CS = 150;

//Moter A
int R1G     = 4;
int R1B     = 5;
int SPEEDR1 = 6;

//Moter B
int R2G     = 22;
int R2B     = 24;
int SPEEDR2 = 9;

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
}

void loop() {
  ps2x.read_gamepad(false, false);
  gear();
  if (ps2x.Button(PSB_PAD_UP)) {
      //SPEED = CS;
      go1(); //bord 1 in1 
      Serial.println("Up");
  }else if (ps2x.Button(PSB_PAD_DOWN)) {
     // SPEED = CS;
      back1(); //bord1 in 2
      Serial.println("Down");
  }else if (ps2x.Button(PSB_PAD_LEFT)) {
      //SPEED = CS;
      go2(); //bord 2 in 1
      Serial.println("Left");
  }else if (ps2x.Button(PSB_PAD_RIGHT)) {
      //SPEED = CS;
      back2(); //bord 2 in 2
      Serial.println("Right");
   }else{
      analogWrite(SPEEDR1,0);
      analogWrite(SPEEDR2,0);
      digitalWrite(R1G, LOW);
      digitalWrite(R1B, LOW);
      digitalWrite(R2G, LOW);
      digitalWrite(R2B, LOW);
    Serial.println("STOP");
}
  delay(10);

}
void gear(){
  if(ps2x.Button(PSB_R1)){
    SPEED = 50;
  }else if(ps2x.Button(PSB_R2)){
    SPEED = 200;  
  }else{
    SPEED = 100;
    
    }
  Serial.print(SPEED);
  delay(20);
}
