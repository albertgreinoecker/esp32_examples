#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

// WLAN-Zugangsdaten
const char* ssid = "...";
const char* password = "...";

// Ziel-URL
const char* url = "https://www.dummyjson.com/users/1";

void setup() {
  Serial.begin(115200);
  delay(1000);

  // WLAN verbinden
  WiFi.begin(ssid, password);
  Serial.print("Verbinde mit WLAN");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWLAN verbunden!");
  Serial.print("IP-Adresse: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClientSecure client;
    client.setInsecure();  // Zertifikatsprüfung abschalten (unsicher, nur zu Testzwecken)

    HTTPClient https;

    Serial.println("[HTTPS] Anfrage senden...");
    https.begin(client, url);  // HTTPS-Verbindung mit unsicherem Client
    int httpCode = https.GET();

    if (httpCode > 0) {
      Serial.printf("[HTTPS] Antwortcode: %d\n", httpCode);
      String payload = https.getString();
      Serial.println("Antwort:");
      Serial.println(payload);
    } else {
      Serial.printf("[HTTPS] Fehler bei GET: %d\n", httpCode);
    }

    https.end();
  } else {
    Serial.println("Keine WLAN-Verbindung.");
  }

  delay(10000);  // Alle 10 Sekunden neue Anfrage
}
