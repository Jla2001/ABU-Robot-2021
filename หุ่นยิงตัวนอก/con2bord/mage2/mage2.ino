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

// encoder
#define encoder_a 2
#define encoder_b 3
volatile long motor_encoder;
volatile long encoder;


//รับค่า จาก บอร์ด แม่
String ps2;
  
void setup(){
  Wire.begin(10);

    //encoder
    pinMode(encoder_a, INPUT); 
    pinMode(encoder_b, INPUT); 
    digitalWrite(encoder_a, HIGH); 
    digitalWrite(encoder_b, HIGH);
    attachInterrupt(0, encoderPinChangeA, CHANGE); 
    attachInterrupt(1, encoderPinChangeB, CHANGE); 
    encoder = 0;
  
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
  Auto();
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

void encoderPinChangeA() {
    if (digitalRead(encoder_a) == digitalRead(encoder_b)) {
        motor_encoder--;
    }else{
        motor_encoder++;
    } 
    en_cal(); 
}

void encoderPinChangeB() {
   if (digitalRead(encoder_a) != digitalRead(encoder_b)) { 
        motor_encoder--; 
    }else{ 
        motor_encoder++;
    }
    en_cal();
}
 
void en_cal() { 
    if (motor_encoder > 0) { 
        _delay_us(200); 
        encoder++; 
        motor_encoder = 0; 
        Serial.println(encoder);
    }
 else if (motor_encoder < 0){
        _delay_us(200); 
        encoder--; 
        motor_encoder = 0; 
        Serial.println(encoder);
    }
}
