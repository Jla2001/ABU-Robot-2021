enum PinAssignments {
  encoderPinA = 2, // ขา S1
  encoderPinB = 3, // ขา S2
  clearButton = 8  // ขา Key
                // จ่ายไฟที่ขา +5v และ gnd
                // Example For Arduino Uno By www.ArduinoAll.com
};

volatile unsigned int encoderPos = 0;  // สำหรับนับจำนวน
unsigned int lastReportedPos = 1;   // change management
static boolean rotating = false;    // debounce management

boolean A_set = false;
boolean B_set = false;

void setup() {

  pinMode(encoderPinA, INPUT_PULLUP); // กำหนดโหมดเป็นแบบ Input pullup
  pinMode(encoderPinB, INPUT_PULLUP);
  pinMode(clearButton, INPUT_PULLUP);
  attachInterrupt(0, doEncoderA, CHANGE); //ทำงานแบบ interrupt เบอร์ 0 ในนี้คือขา pin 2
  attachInterrupt(1, doEncoderB, CHANGE); //ทำงานแบบ interrupt เบอร์ 1 ในนี้คือขา pin 3
  Serial.begin(9600);
}

void loop() {
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
}


// คำสั่งทำงานแบบ interrupt เมื่อมีการหมุน
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
