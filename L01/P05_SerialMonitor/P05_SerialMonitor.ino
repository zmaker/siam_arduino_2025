int count = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("hello!");
}

void loop() {
  Serial.println("ok");
  Serial.print("count vale: "); Serial.println(count);
  //count = count + 1;
  count++;
  delay(1000);
}
