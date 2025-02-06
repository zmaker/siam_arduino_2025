int statoled = LOW;

void setup() {
  pinMode(2, INPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  int bt = digitalRead(2);
  if (bt) {
    statoled = !statoled;
    digitalWrite(10, statoled);
    delay(300);
  }
}
