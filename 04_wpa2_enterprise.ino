#include <WiFi.h>

const char* ssid = "DeinWLANName";
const char* username = "dein_username";
const char* password = "dein_passwort";

void setup() {
  Serial.begin(115200);

  WiFi.disconnect(true); // sicherstellen, dass alles sauber ist
  WiFi.mode(WIFI_STA);
  
  esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)username, strlen(username));
  esp_wifi_sta_wpa2_ent_set_username((uint8_t *)username, strlen(username));
  esp_wifi_sta_wpa2_ent_set_password((uint8_t *)password, strlen(password));
  esp_wifi_sta_wpa2_ent_enable(); // WPA2-Enterprise aktivieren
  
  WiFi.begin(ssid);

  Serial.println("Verbinde...");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("Verbunden!");
}

void loop() {
  // Dein Code
}
