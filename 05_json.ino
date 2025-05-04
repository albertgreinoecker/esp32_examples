#include <ArduinoJson.h>

void setup() {
  Serial.begin(115200);

  // Beispiel-JSON (normalerweise aus HTTP-Antwort)
  String json = "{\"id\":1,\"name\":\"Max Mustermann\",\"email\":\"max@example.com\"}";

  // Speicher reservieren
  StaticJsonDocument<200> doc; // Wenn die groesse schwer vorauszusagen ist, dann DynamicJsonDocument doc(1024); 

  // JSON parsen
  DeserializationError error = deserializeJson(doc, json);
  if (error) {
    Serial.print("Fehler beim Parsen: ");
    Serial.println(error.f_str());
    return;
  }

  // Felder auslesen
  int id = doc["id"];
  const char* name = doc["name"];
  const char* email = doc["email"];

  Serial.println("Auslesen aus dem JSON-String");
  Serial.println(id);
  Serial.println(name);
  Serial.println(email);


  /*
  Schreiben von JSON: 
  Es geht auch dass man den JSON String direkt schreibt - ohne Bibliothek
  */

  StaticJsonDocument<512> doc2;

  doc2["name"] = "Max";
  doc2["age"] = 30;
  doc2["is_active"] = true;

  JsonObject address = doc2.createNestedObject("address");
  address["city"] = "Berlin";
  address["zip"] = "10115";

  // In String schreiben
  String jsonOutput;
  serializeJson(doc2 , jsonOutput);
  Serial.println("Ausgabe als JSON:");
  Serial.println(jsonOutput);

}


void loop() {
  // put your main code here, to run repeatedly:
}
