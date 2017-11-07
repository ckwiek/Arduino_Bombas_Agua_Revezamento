
byte b     = 8;
byte led1  = 9;
byte led2  = 10;
 
 
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(b, INPUT);
}
 
void loop() {
  static boolean lastValue = false;
  static unsigned long lastDebounceTime = 0;
  static byte lastButtonState = LOW;
  
  static byte iLed = 0;
  byte r = digitalRead(b);
  
  
  if (r != lastButtonState) { lastDebounceTime = millis(); }
  
  if ((millis() - lastDebounceTime) > 80) {  //80ms time debouncing
  
    if (r && r != lastValue){    //borda de subida
      lastValue = true;
 
      iLed++;
      if (iLed > 1) {iLed = 0;}
 
      if (iLed == 0){
        digitalWrite(led1, HIGH);
      } else {
        digitalWrite(led2, HIGH);
      }
 
    }
 
    if (!r && r != lastValue){    //borda de descida
      lastValue = false;
 
      if (iLed == 0){
        digitalWrite(led1, LOW);
      } else {
        digitalWrite(led2, LOW);
      }
    }
  }
  lastButtonState = r;
  
  delay(20);
}

