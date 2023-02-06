#define shot1 3
#define shot2 4
#define PWN   5

void setup() {
  pinMode(shot1,OUTPUT);
  pinMode(shot2,OUTPUT);
  pinMode(PWN,OUTPUT);

}

void loop() {
  digitalWrite(shot1,HIGH);
  digitalWrite(shot2,LOW);
  analogWrite(PWN,10);
  delay(2000);
  digitalWrite(shot1,LOW);
  digitalWrite(shot2,LOW);
  analogWrite(PWN,0);
  delay(2000);
  digitalWrite(shot1,LOW);
  digitalWrite(shot2,HIGH);
  analogWrite(PWN,10);
  delay(2000);
  digitalWrite(shot1,LOW);
  digitalWrite(shot2,LOW);
  analogWrite(PWN,0);
}
