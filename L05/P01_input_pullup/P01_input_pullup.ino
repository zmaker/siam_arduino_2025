void setup() {
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int bt = !digitalRead(2);
  Serial.print("valore pulsante: ");
  Serial.println(bt);
  delay(100);
}
