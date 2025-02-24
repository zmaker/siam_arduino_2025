#include <WiFi.h>
#include <WebServer.h>
#include "secret.h"

WebServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(15, OUTPUT);
  delay(1000);
  Serial.println("Server con LED");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" ");
  Serial.println("Connesso");

  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", pageIndex);
  server.on("/led", pageLed);
  server.onNotFound(pageError);
  server.begin();
}

void loop() {
  server.handleClient();
}
