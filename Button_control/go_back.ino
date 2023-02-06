//bord 1 in1
void go1(){
    analogWrite(SPEEDR1, SPEED);
    digitalWrite(R1G, HIGH);
    digitalWrite(R1B, LOW);
}
//bord 2 in1
void go2(){
    analogWrite(SPEEDR2, SPEED);
    digitalWrite(R2G, HIGH);
    digitalWrite(R2B, LOW);
}
//bord 1 in2
void back1(){
    analogWrite(SPEEDR1, SPEED);
    digitalWrite(R1G, LOW);
    digitalWrite(R1B, HIGH);
}
//bord 2 in2
void back2(){
    analogWrite(SPEEDR2, SPEED);
    digitalWrite(R2G, LOW);
    digitalWrite(R2B, HIGH);
}
