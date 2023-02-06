#define encoder_a 2    //encoder a = arduino pin 2 
#define encoder_b 3    //encoder b = arduino pin 3 
#define motor_step 4    //motor step = arduino pin 4 
#define motor_direction 5    //motor direction = arduino pin 5

volatile long motor_position, encoder; 

void setup () { 
    Serial.begin(9600);
    pinMode(motor_step, OUTPUT); 
    pinMode(motor_direction, OUTPUT); 
    pinMode(encoder_a, INPUT); 
    pinMode(encoder_b, INPUT); 
    digitalWrite(encoder_a, HIGH); 
    digitalWrite(encoder_b, HIGH);
    attachInterrupt(0, encoderPinChangeA, CHANGE); 
    attachInterrupt(1, encoderPinChangeB, CHANGE); 
    encoder = 0; 
}

void encoderPinChangeA() 

{
    if (digitalRead(encoder_a) == digitalRead(encoder_b)) {
        encoder--;
    } else{
        encoder++;
    } 
} 

void encoderPinChangeB() {
   if (digitalRead(encoder_a) != digitalRead(encoder_b)) 
    { 
        encoder--; 
    }else{ 
        encoder++;
    } 
}
 
void loop() { 
    if (encoder > 0) { 
        digitalWrite(motor_direction, HIGH); 
        digitalWrite(motor_step, HIGH); 
        digitalWrite(motor_step, LOW); 
        _delay_us(200); 
        motor_position++; 
        encoder = 0; 
        Serial.println(motor_position);
    }
 else if (encoder < 0){
        digitalWrite(motor_direction, LOW); 
        digitalWrite(motor_step, HIGH); 
        digitalWrite(motor_step, LOW); 
        _delay_us(200); 
        motor_position--; 
        encoder = 0; 
        Serial.println(motor_position);
    }
}
