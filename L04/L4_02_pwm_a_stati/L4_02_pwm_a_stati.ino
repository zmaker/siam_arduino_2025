int stato = 0;
int pwm = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(3, OUTPUT);
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
  }
}

void stato_0(){
  analogWrite(3, pwm);
  if (digitalRead(2)){
    stato = 1;  
  }
  if (digitalRead(4)){
    stato = 2;  
  }
}

void stato_1(){
  pwm++;
  if (pwm > 255) {
    pwm = 255;
  }
  delay(20);
  stato = 0;
}

void stato_2(){
  pwm--;
  if (pwm < 0) {
    pwm = 0;
  }
  delay(20);
  stato = 0;
}
