#include <PS2X_lib.h>
//#include <avr/wdt.h>

#define PS2_DAT 47
#define PS2_CMD 46
#define PS2_SEL 45
#define PS2_CLK 44

//ตัวแปร encoder
enum PinAssignments {
  encoderPinA = 2, // ขา S1
  encoderPinB = 3, // ขา S2
  clearButton = 8  // ขา Key
                   // จ่ายไฟที่ขา +5v และ gnd
};
volatile unsigned int encoderPos = 0;  // สำหรับนับจำนวน
unsigned int lastReportedPos = 1;   // change management
static boolean rotating = false;    // debounce management
boolean A_set = false;
boolean B_set = false;

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

// automode
boolean m = false; // เปลี่ยนโหมด
boolean s = false; 

PS2X ps2x;
void setup() {
 // wdt_enable(WDTO_1S);
 
 //setup encoder
  pinMode(encoderPinA, INPUT_PULLUP); // กำหนดโหมดเป็นแบบ Input pullup
  pinMode(encoderPinB, INPUT_PULLUP);
  pinMode(clearButton, INPUT_PULLUP);
  attachInterrupt(0, doEncoderA, CHANGE); //ทำงานแบบ interrupt เบอร์ 0 ในนี้คือขา pin 2
  attachInterrupt(1, doEncoderB, CHANGE); //ทำงานแบบ interrupt เบอร์ 1 ในนี้คือขา pin 3
  
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

void doEncoderA() {
  // debounce
  if ( rotating ) delay (1);  // หน่วงเวลาป้องกันสัญญาณบกวน debounce

  // เช็คว่ามีบิดสวิตช์
  if ( digitalRead(encoderPinA) != A_set ) { // debounce once more
    A_set = !A_set;
    // adjust counter + if A leads B
    if ( A_set && !B_set )
      encoderPos += 1;
    rotating = false;  // no more debouncing until loop() hits again
  }
}

// Interrupt on B changing state, same as A above
void doEncoderB() {
  if ( rotating ) delay (1);
  if ( digitalRead(encoderPinB) != B_set ) {
    B_set = !B_set;
    //  adjust counter - 1 if B leads A
    if ( B_set && !A_set )
      encoderPos -= 1;
    rotating = false;
  }
}

void SmartAuto(){
  if(s == true && m == true){
    
  }
}

void analog(){
 if(s == false){
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
}

void loop() {
  ps2x.read_gamepad(false, false);
    if(ps2x.Button(PSB_R3)){
      s = true;
    }
    if(ps2x.Button(PSB_SELECT)){
    m = true;
  }else if(ps2x.Button(PSB_SELECT) && m == true){
    m = false;
    s = false;
  }
    rotating = true;  // reset the debouncer

  if (lastReportedPos != encoderPos) {
    Serial.print("Index:");
    Serial.println(encoderPos, DEC);
    lastReportedPos = encoderPos;
  }
  if (digitalRead(clearButton) == LOW )  {
    encoderPos = 0;
    Serial.println("Click:Reset Index");
    delay(200);
  }
  gear();
  analog();
  SmartAuto();
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
