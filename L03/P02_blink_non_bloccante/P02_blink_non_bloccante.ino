unsigned long t1, t2 = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  unsigned long intervallo = millis() - t1;
  if (intervallo >= 1000) {
    digitalWrite(13, !digitalRead(13));
    t1 = millis();
  }

  intervallo = millis() - t2;
  if (intervallo >= 300) {
    digitalWrite(8, !digitalRead(8));
    t2 = millis();
  }
  
  int bt = digitalRead(2);
  digitalWrite(10, bt);
}
