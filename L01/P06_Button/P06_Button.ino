// lettura button su pin 2 - res 10k pull down
void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  //leggo il pulsante
  int bt = digitalRead(2);
  //stampo il valore sul serial monitor
  Serial.print("bt: "); Serial.println(bt);
  //attendo qualche istante 
  delay(200);
}
