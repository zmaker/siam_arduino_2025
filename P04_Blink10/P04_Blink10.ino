int pin;  //dichiaro la variabile

int led = 10;  //dichiaro e assegno

void setup() {
  pinMode(led, OUTPUT);
  pin = 0;  //assegno un valore
}

void loop() {
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
}
