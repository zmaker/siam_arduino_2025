#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

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
  
  server.on("/", pageIndex);
  server.onNotFound(pageError);
  server.begin();
}

void loop() {
  server.handleClient();
}

void pageIndex() {
  int val = analogRead(1);
  
  String str = "<html><head><meta http-equiv='refresh' content='3'></head><body><h1>Hello Web Server</h1>";
  str += String("val=") + String(val) + String("</body></html>\n");
  server.send(200, "text/html", str);
}
void pageError() {
  String str = "<html><body><h1>Non Trovata!</h1></body></html>\n";
  server.send(404, "text/html", str);
}
