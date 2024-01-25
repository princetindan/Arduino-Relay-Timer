#include <Wire.h>
#include <WiFi.h>

const int batteryPin = 34;  // GPIO pin connected to the battery voltage divider
const int ledPin = 2;  // GPIO pin connected to the LED
const float voltageDividerRatio = 5.6 / (5.6 + 10.0);  // Voltage divider ratio for 15V maximum input
const float calibrationFactor = 2.0;  // Calibration factor to adjust reported voltage
const float voltageThreshold = 12.0;  // Voltage threshold for turning on the LED

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  // Connect to Wi-Fi (Replace "your-ssid" and "your-password" with your actual Wi-Fi credentials)
WiFi.begin("damn", "qwertyqwerty1");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    float voltage = getVoltage();
    String response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    response += "<html><head><title>KELSUS ENERGY PROJECT</title>";
    response += "<meta http-equiv='refresh' content='10'>";  // Refresh the page every 5 seconds
    response += "</head><body>";

    // Bold and green company name
    response += "<h1 style='color:green; font-weight:bold;'>KELSUS ENERGY PROJECT</h1>";

    if (voltage < voltageThreshold) {
      response += "<h2 style='color:red;'>LIGHT ON BECAUSE VOLTAGE HAS GONE BELOW 12V</h2>";
      digitalWrite(ledPin, HIGH);  // Turn on the LED
    } else {
      response += "<h2>VOLTAGE STABLE</h2>";
      digitalWrite(ledPin, LOW);  // Turn off the LED
    }

    response += "</body></html>";
    client.print(response);
    delay(1);
    client.stop();
  }
}

float getVoltage() {
  int sensorValue = analogRead(batteryPin);
  float voltage = (sensorValue * (3.3 / 4095.0) / voltageDividerRatio) * calibrationFactor;
  return voltage;
}
