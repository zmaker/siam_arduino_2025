void setup() {
  pinMode(15, OUTPUT);
}

void loop() {
  digitalWrite(15, !digitalRead(15));
  delay(300);
}
