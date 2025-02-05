void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {
  int val = analogRead(A0);
  Serial.println(val);
  if (val > 500) {
    //accendo il led
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }
}
