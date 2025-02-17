#include <WiFi.h>

void setup() {
  pinMode(15, OUTPUT);

  Serial.begin(115200);
  delay(1000);

  WiFi.begin("Siam-ReteAule", "Khimeya2018");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnesso!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  delay(1000);
  
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.disconnect();
    delay(1000);
    WiFi.reconnect();
  }
  digitalWrite(15, !digitalRead(15));
  delay(2000);
}
