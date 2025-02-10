int led = 3;
int stato = 0;
unsigned long t1 = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  switch(stato){
    case 0:
      stato_0();
      break;
    case 1:
      stato_1();
      break;
    case 2:
      stato_2();
      break;
    case 3:
      stato_3();
      break;
  }
}

void stato_0(){
  digitalWrite(led, LOW);
  if (digitalRead(2)) {
    delay(300);
    stato = 1;
  }
  if (digitalRead(4)) {
    delay(300);
    stato = 3;
  }
}

void stato_1(){
  analogWrite(led, 100);
  if (digitalRead(2)) {
    delay(300);
    stato = 2;
  }
  if (digitalRead(4)) {
    delay(300);
    stato = 0;
  }
}

void stato_2(){
  digitalWrite(led, HIGH);
  if (digitalRead(2)) {
    delay(300);
    stato = 3;
  }
  if (digitalRead(4)) {
    delay(300);
    stato = 1;
  }
}

void stato_3(){
  if ((millis()-t1) > 500) {
    digitalWrite(led, !digitalRead(led));
    t1 = millis();
  }
  if (digitalRead(2)) {
    delay(300);
    stato = 0;
  }
  if (digitalRead(4)) {
    delay(300);
    stato = 2;
  }
}
