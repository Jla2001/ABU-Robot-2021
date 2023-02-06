#include <Wire.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

int p = 9;
int m1 = 10;
int m2 = 11;
int SPEED;
 
void setup() {
  
  pinMode(A0,INPUT);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(p,OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
    SPEED = map(analogRead(A0),0,1023,0,255);
    lcd.setCursor(5,0);
    lcd.println(SPEED);
    Serial.print("speed motor = ");
    Serial.println(SPEED);
    digitalWrite(m1,HIGH);
    digitalWrite(m2,LOW);
    analogWrite(p,SPEED);
    delay(20);
}
