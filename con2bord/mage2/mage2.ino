#include <Wire.h>

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

//รับค่า จาก บอร์ด แม่
String ps2;
  
void setup(){
  Wire.begin(10);
  
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

void loop(){
  manual();
  gear();
  delay(10);
}

void gear(){
  if(ps2 == "50"){
       SPEED = 50;
  }else if(ps2 == "255"){
       SPEED = 255;
  }else{
       SPEED = 100;
  }
}

void manual(){
  ps2 = Wire.read();
  if(ps2 == "RX1"){
      go1();
      back2();
      go3();
      back4();
  }else if(ps2 == "Rx-1"){
    back1();
    go2();
    back3();
    go4();
  }else if(ps2 == "LY1"){
    back1();
    back2();
    back3();
    back4();
  }else if (ps2 == "LY-1"){
    go1();
    go2();
    go3();
    go4();
  }else if(ps2 == "LX1"){
    go1();
    back2();
    back3();
    go4();
  }else if(ps2 == "LX-1"){
    back1();
    go2();
    go3();
    back4();
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
}
