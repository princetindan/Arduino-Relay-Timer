#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "damn";     // Your WiFi SSID
const char* password = "fuckoffthere"; // Your WiFi password

int led1Pin = D1;   // Pin connected to LED1
int led2Pin = D2;   // Pin connected to LED2
int waterLevelPin = A0; // Analog pin connected to water level sensor
int waterLevelThreshold = 11; // Adjust this threshold according to your sensor

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200); // Start serial communication
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(waterLevelPin, INPUT);
  
  digitalWrite(led1Pin, LOW); // Ensure LED1 is initially off
  digitalWrite(led2Pin, LOW); // Ensure LED2 is initially off
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("WiFi connected.");

  // Print IP address
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Start the server
  server.on("/", handleRoot);
  server.on("/led1on", handleLed1On);
  server.on("/led1off", handleLed1Off);
  server.on("/waterpumpon", handleWaterPumpOn);
  server.on("/waterpumpoff", handleWaterPumpOff);
  server.begin();
  Serial.println("HTTP server started.");
}

void loop() {
  server.handleClient();

  // Read water level sensor
  int waterLevel = analogRead(waterLevelPin);
  Serial.print("Water level: ");
  Serial.println(waterLevel);
  
  // Control water pump based on water level
  if (waterLevel < waterLevelThreshold) {
    digitalWrite(led1Pin, HIGH); // Turn on water pump
  } else {
    digitalWrite(led1Pin, LOW); // Turn off water pump
  }
  delay(1000);
}

void handleRoot() {
  // Read water level sensor
  int waterLevel = analogRead(waterLevelPin);
  
  // Prepare HTML content with LED control buttons and water level information
  String htmlContent = "<h1>Arduino Web Control</h1>";
  htmlContent += "<p>LED1: <a href=\"/led1on\"><button>ON</button></a> <a href=\"/led1off\"><button>OFF</button></a></p>";
  htmlContent += "<p>Water Pump: <a href=\"/waterpumpon\"><button>ON</button></a> <a href=\"/waterpumpoff\"><button>OFF</button></a></p>";
  htmlContent += "<p>Water Level: " + String(waterLevel) + "</p>";
  
  // Add JavaScript to refresh the page every 5 seconds
  htmlContent += "<script>setTimeout(function(){window.location.reload(true);}, 5000);</script>";
  
  // Send the HTML content to the client
  server.send(200, "text/html", htmlContent);
}

void handleLed1On() {
  digitalWrite(led1Pin, HIGH);
  server.send(200, "text/plain", "LED1 turned on");
}

void handleLed1Off() {
  digitalWrite(led1Pin, LOW);
  server.send(200, "text/plain", "LED1 turned off");
}

void handleWaterPumpOn() {
  digitalWrite(led2Pin, HIGH);
  server.send(200, "text/plain", "Water Pump turned on");
}

void handleWaterPumpOff() {
  digitalWrite(led2Pin, LOW);
  server.send(200, "text/plain", "Water Pump turned off");
}
