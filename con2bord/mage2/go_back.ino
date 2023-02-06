void go1(){
    analogWrite(SPEEDR1, SPEED);
    digitalWrite(R1G, HIGH);
    digitalWrite(R1B, LOW);
}
void go2(){
    analogWrite(SPEEDR2, SPEED);
    digitalWrite(R2G, HIGH);
    digitalWrite(R2B, LOW);
}
void go3(){
    analogWrite(SPEEDR3, SPEED);
    digitalWrite(R3G, HIGH);
    digitalWrite(R3B, LOW);
}
void go4(){
    analogWrite(SPEEDR4, SPEED);
    digitalWrite(R4G, HIGH);
    digitalWrite(R4B, LOW);
}
void back1(){
    analogWrite(SPEEDR1, SPEED);
    digitalWrite(R1G, LOW);
    digitalWrite(R1B, HIGH);
}
void back2(){
    analogWrite(SPEEDR2, SPEED);
    digitalWrite(R2G, LOW);
    digitalWrite(R2B, HIGH);
}
void back3(){
    analogWrite(SPEEDR3, SPEED);
    digitalWrite(R3G, LOW);
    digitalWrite(R3B, HIGH);
}
void back4(){
    analogWrite(SPEEDR4, SPEED);
    digitalWrite(R4G, LOW);
    digitalWrite(R4B, HIGH);
}
