#include <WiFi.h>
#include <HTTPClient.h>

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
  HTTPClient http;
  //http.begin("http://www.google.com");
  http.begin("http://jsonplaceholder.typicode.com/todos/1");
  
  int httpCode = http.GET();
  if (httpCode > 0) {
    Serial.print("HTTP CODE: ");
    Serial.println(httpCode);
    String page = http.getString();
    Serial.println(page);
  }
  http.end();
  WiFi.disconnect();
}

void loop() {
  digitalWrite(15, !digitalRead(15));
  delay(300);
}
