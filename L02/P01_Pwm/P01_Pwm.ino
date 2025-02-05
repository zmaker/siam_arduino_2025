// variabile costante: non può essere cambbiato il valore
//const int pin = 9;
// costante definita con una direttiva 
//#define PIN_LEN 9
int pin = 9;
int lum = 0;

void setup() {
  //con analogWrite non serve pinMode
  pinMode(pin, OUTPUT);
}

void loop() {
  for (int i = 0 ; i <= 255 ; i++ ) {
    analogWrite(pin, i);
    delay(10);
  }
  for (int i = 255 ; i >= 0 ; i-- ) {
    analogWrite(pin, i);
    delay(10);
  }
}
