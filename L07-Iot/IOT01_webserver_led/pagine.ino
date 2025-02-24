void pageIndex() {
  String str = "<html><body>Index Page</body></html>";
  server.send(200, "text/html", str); //codice http, MIME TYPE, contenuto
}

void pageLed() {
  // http://192.168.0.23/led?stato=1&colore=red&int=56
  String button = "";
  if (server.hasArg("stato")) {
    int stato = server.arg("stato").toInt();
    Serial.print("st:");
    Serial.println(stato);
    if (stato == 1) {
      digitalWrite(15, HIGH);
      button = "<a href='http://172.16.0.27/led?stato=0'><button>OFF</button></a>";
    } else {
      digitalWrite(15, LOW);
      button = "<a href='http://172.16.0.27/led?stato=1'><button>ON</button></a>";
    }
  }
  String str1 = "<html><body><h1>Led Page</h1>";
  String str2 = "</body></html>";
  String page = str1 + button + str2;
  server.send(200, "text/html", page); 
}

void pageError() {
  String str = "<html><body>Pagina non trovata</body></html>";
  server.send(404, "text/html", str); //codice http, MIME TYPE, contenuto
}