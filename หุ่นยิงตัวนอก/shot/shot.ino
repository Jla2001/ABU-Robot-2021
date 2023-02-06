#include <PS2X_lib.h> 
//ชุดยิงมอเตอร์
#define ry1 8
#define ry2 9
#define ry3 10

#define shot1 3
#define shot2 4
#define PWN   5
#define PS2_DAT 13
#define PS2_CMD 12
#define PS2_SEL 11
#define PS2_CLK 10

int csw; // เช็ค SW

int set = 0;
int c = 0;

//ชุดลม
#define wn1 23
#define wn2 24
#define wn3 25 

PS2X ps2x;

float SPEED = 40;

void setup(){
  pinMode(ry1,OUTPUT);
  pinMode(ry2,OUTPUT);
  pinMode(ry3,OUTPUT);
  pinMode(shot1,OUTPUT);
  pinMode(shot2,OUTPUT);
  pinMode(wn1,OUTPUT);
  pinMode(wn2,OUTPUT);
  pinMode(wn3,OUTPUT);

    digitalWrite(ry1,HIGH);
    digitalWrite(ry2,HIGH);
    digitalWrite(ry3,HIGH);
  
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
void loop(){
  ps2x.read_gamepad(false, false);

  digitalWrite(shot1,HIGH);
  digitalWrite(shot2,LOW);
      PWM
      ();
      cal();
      shot();
  
  delay(10);
}

void cal(){
  bool ReadSW = ps2x.Button(PSB_L1);
  if(csw != ReadSW){
    if(ReadSW == 1){ 
     set ++ ;
    }
    csw = ReadSW;
  }
  switch(set){
    case 1 :
        digitalWrite (ry1,LOW);
        digitalWrite(ry2,HIGH);
        digitalWrite(ry3,HIGH);
        analogWrite(PWN,SPEED);
        c = 1;
        break;
    case 3 :
        digitalWrite (ry1,HIGH);
        digitalWrite(ry2,LOW);
        digitalWrite(ry3,HIGH);
        analogWrite(PWN,255);
        c = 2;
        break;
    case 5 :
        digitalWrite (ry1,HIGH);
        digitalWrite(ry2,HIGH);
        digitalWrite(ry3,LOW);
        analogWrite(PWN,SPEED);
        c = 3;
        break;
    case 6 :
        digitalWrite(ry1,HIGH);
        digitalWrite(ry2,HIGH);
        digitalWrite(ry3,HIGH);
        set = 0;
        c = 0;
        break;
  }
}

void shot(){
    if(ps2x.Button(PSB_TRIANGLE) && c == 1){
    digitalWrite(wn1,LOW);
    Serial.println("1");
    delay(1000);
    set = 2;
    digitalWrite(ry1,HIGH);  
  }else if(ps2x.Button(PSB_TRIANGLE) && c == 2){
    digitalWrite(wn2,LOW);
    Serial.println("2");
    delay(1000);
    set = 4;
    digitalWrite(ry2,HIGH);
  }else if(ps2x.Button(PSB_TRIANGLE)&& c == 3){
    digitalWrite(wn3,LOW);
    Serial.println("3");
    delay(1000);
    set = 0;
    digitalWrite(ry3,HIGH);
  }else{
     digitalWrite(wn1,HIGH);
     digitalWrite(wn2,HIGH);
     digitalWrite(wn3,HIGH);
    
  }
}

void PWM(){
  if(ps2x.Button(PSB_PAD_UP)){
    SPEED +=0.5;
    Serial.println(SPEED);
    delay(500);
  }else if(ps2x.Button(PSB_PAD_DOWN)){
    SPEED -=0.5;
    Serial.println(SPEED);
    delay(500);
  }
}
