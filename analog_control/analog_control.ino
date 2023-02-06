#include <PS2X_lib.h>
//#include <avr/wdt.h>

#define PS2_DAT 47
#define PS2_CMD 46
#define PS2_SEL 45
#define PS2_CLK 44

//ความไวมอเตอร
int SPEED = 100;

//Moter A
int R1G     = 10;
int R1B     = 11;
int SPEEDR1 = 2;

//Moter B
int R2G     = 15;
int R2B     = 16;
int SPEEDR2 = 3;

//Motor C
int R3G     = 19;
int R3B     = 18;
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
  gear();
  if(ps2x.Analog(PSS_RX) > 190){
    analogWrite(SPEEDR1, SPEED);
    digitalWrite(R1G, HIGH);
    digitalWrite(R1B, LOW);
    analogWrite(SPEEDR2, SPEED);
    digitalWrite(R2G, LOW);
    digitalWrite(R2B, HIGH);
    analogWrite(SPEEDR3, SPEED);
    digitalWrite(R3G, HIGH);
    digitalWrite(R3B, LOW);
    analogWrite(SPEEDR4, SPEED);
    digitalWrite(R4G, LOW);
    digitalWrite(R4B, HIGH);
    Serial.println("หมุนขวา");
}else if(ps2x.Analog(PSS_RX) < 70){
    analogWrite(SPEEDR1, SPEED);
    digitalWrite(R1G, LOW);
    digitalWrite(R1B, HIGH);
    analogWrite(SPEEDR2, SPEED);
    digitalWrite(R2G, HIGH);
    digitalWrite(R2B, LOW);
    analogWrite(SPEEDR3, SPEED);
    digitalWrite(R3G, LOW);
    digitalWrite(R3B, HIGH);
    analogWrite(SPEEDR4, SPEED);
    digitalWrite(R4G, HIGH);
    digitalWrite(R4B, LOW);
    Serial.println("หมุนซ้าย");
}else if (ps2x.Analog(PSS_LY) < 70) {
    analogWrite(SPEEDR1, SPEED);
    digitalWrite(R1G, HIGH); 
    digitalWrite(R1B, LOW);
    analogWrite(SPEEDR2, SPEED);
    digitalWrite(R2G, HIGH);
    digitalWrite(R2B, LOW);
    analogWrite(SPEEDR3, SPEED);
    digitalWrite(R3G, HIGH);
    digitalWrite(R3B, LOW);
    analogWrite(SPEEDR4, SPEED);
    digitalWrite(R4G, HIGH);
    digitalWrite(R4B, LOW);
    Serial.println("Up");
     //wdt_reset();
  }else if (ps2x.Analog(PSS_LY) > 190) {
    analogWrite(SPEEDR1, SPEED);
    digitalWrite(R1G, LOW);
    digitalWrite(R1B, HIGH);
    analogWrite(SPEEDR2, SPEED);
    digitalWrite(R2G, LOW);
    digitalWrite(R2B, HIGH);
    analogWrite(SPEEDR3, SPEED);
    digitalWrite(R3G, LOW);
    digitalWrite(R3B, HIGH);
    analogWrite(SPEEDR4, SPEED);
    digitalWrite(R4G, LOW);
    digitalWrite(R4B, HIGH);
    Serial.println("Down");
    //wdt_reset();
  }else if (ps2x.Analog(PSS_LX) < 70) {
    analogWrite(SPEEDR1, SPEED);
    digitalWrite(R1G, LOW);
    digitalWrite(R1B, HIGH);
    analogWrite(SPEEDR2, SPEED);
    digitalWrite(R2G, HIGH);
    digitalWrite(R2B, LOW);
    analogWrite(SPEEDR3, SPEED);
    digitalWrite(R3G, HIGH);
    digitalWrite(R3B, LOW);
    analogWrite(SPEEDR4, SPEED);
    digitalWrite(R4G, LOW);
    digitalWrite(R4B, HIGH);
    Serial.println("Left");
    //wdt_reset();
  }else if (ps2x.Analog(PSS_LX) > 190) {
    analogWrite(SPEEDR1, SPEED);
    digitalWrite(R1G, HIGH);
    digitalWrite(R1B, LOW);
    analogWrite(SPEEDR2, SPEED);
    digitalWrite(R2G, LOW);
    digitalWrite(R2B, HIGH);
    analogWrite(SPEEDR3, SPEED);
    digitalWrite(R3G, LOW);
    digitalWrite(R3B, HIGH);
    analogWrite(SPEEDR4, SPEED);
    digitalWrite(R4G, HIGH);
    digitalWrite(R4B, LOW);
    Serial.println("Right");
    //wdt_reset();
   }else{
    analogWrite(SPEEDR1,0);
    digitalWrite(R1G, LOW);
    digitalWrite(R1B, LOW);
    analogWrite(SPEEDR2,0);
    digitalWrite(R2G, LOW);
    digitalWrite(R2B, LOW);
    analogWrite(SPEEDR3,0);
    digitalWrite(R3G, LOW);
    digitalWrite(R3B, LOW);
    analogWrite(SPEEDR4,0);
    digitalWrite(R4G, LOW);
    digitalWrite(R4B, LOW);
    Serial.println("Stop");
}
  delay(20);

}
void gear(){
  if(ps2x.Button(PSB_R1)){
    SPEED = 50;
  }else if(ps2x.Button(PSB_R2)){
    SPEED = 255;  
  }else{
    SPEED = 100;
    
    }
  Serial.print(SPEED);
  delay(20);
}
