#define BLYNK_TEMPLATE_ID "TMPL2FyI7-FGk"
#define BLYNK_TEMPLATE_NAME "Smart Farm"
#define BLYNK_AUTH_TOKEN "WjHBXbV0BPKq99vSnqE488gUPBtiqHaC"

#include <WiFi.h>
//#include <BlynkSimpleEsp8266.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "WjHBXbV0BPKq99vSnqE488gUPBtiqHaC"; // Blynk authentication token
char ssid[] = "Teacher Aboagye";    // Your WiFi Name
char pass[] = "daniel@1"; // Your Wifi Password

const int soilPumpPin = 31; // Pin connected to the soil moisture sensor pump relay
const int moisturePumpPin = 34; // Pin connected to  capacitive soil moisture sensor pump relay
const int soilSensorPin = 21; // Pin connected to the soil moisture sensor
const int moistureSensorPin = 32; // Pin connected to the capacitive soil moisture sensor

bool autoMode = true; // Flag for automatic mode

void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(soilPumpPin, OUTPUT);
  pinMode(moisturePumpPin, OUTPUT);
  
  Blynk.begin(auth, ssid, pass);

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("Blynk connected");
}

void loop() {
  Blynk.run();
  
  if (autoMode) {
    // Automatic mode: Turn on pumps based on sensor readings
    int soilMoisture = analogRead(soilSensorPin);
    int moistureMoisture = analogRead(moistureSensorPin);
    
    if (soilMoisture < 500) {
      digitalWrite(soilPumpPin, HIGH);
    } else {
      digitalWrite(soilPumpPin, LOW);
    }
    
    if (moistureMoisture < 500) {
      digitalWrite(moisturePumpPin, HIGH);
    } else {
      digitalWrite(moisturePumpPin, LOW);
    }
  }
}

BLYNK_WRITE(V1) { // Virtual pin for controlling soil moisture sensor pump manually
  int pumpState = param.asInt();
  digitalWrite(soilPumpPin, pumpState);
}

BLYNK_WRITE(V2) { // Virtual pin for controlling capacitive soil moisture sensor pump manually
  int pumpState = param.asInt();
  digitalWrite(moisturePumpPin, pumpState);
}

BLYNK_WRITE(V3) { // Virtual pin for toggling between automatic and manual mode
  autoMode = param.asInt();
}
