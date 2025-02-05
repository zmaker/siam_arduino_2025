void setup() {
  Serial.begin(9600);

}

void loop() {
  int val = analogRead(A0);
  Serial.println(val);

  int pwm = map( val, 0,1023, 0,255 );
  analogWrite(9, pwm);

  delay(100);
}
