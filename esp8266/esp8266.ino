#include <ESP8266WiFi.h>
//#include <ESPAsyncWebServer.h>
//#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "damn";
const char* password = "fuckoffthere";

#define RELAY_PIN D2
#define WATER_SENSOR_PIN A0
#define THRESHOLD 50

void setup() {
    Serial.begin(115200);
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW); // Initialize relay as OFF

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}

void loop() {
    int waterLevel = analogRead(WATER_SENSOR_PIN);
    if (waterLevel > THRESHOLD) {
        digitalWrite(RELAY_PIN, HIGH); // Turn ON relay
         Serial.println("waterLevel: ");
          Serial.println(waterLevel);
    } else {
        digitalWrite(RELAY_PIN, LOW); // Turn OFF relay
        Serial.println("waterLevel: ");
          Serial.println(waterLevel);
    }
    delay(1000);
}
