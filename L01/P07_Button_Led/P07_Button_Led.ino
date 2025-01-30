void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  int bt = digitalRead(2);
  if (bt == HIGH) {
    digitalWrite(10, HIGH);
    Serial.println("BT!");
    delay(300);
  } else {
    digitalWrite(10, LOW);
  }
}
