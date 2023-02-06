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
