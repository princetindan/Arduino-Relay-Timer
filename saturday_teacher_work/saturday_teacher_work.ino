#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

IPAddress staticIP(192, 168, 137, 54); // Define the static IP address  http: //192.168.137.54
IPAddress gateway(10, 57, 124, 1);    // Define the gateway IP address
IPAddress subnet(255, 255, 255, 192);   // Define the subnet mask

const char* ssid = "damn";        // Your WiFi SSID
const char* password = "fuckoffthere"; // Your WiFi password

int led1Pin = D1;   // Pin connected to LED1
int led2Pin = D2;   // Pin connected to LED2
int waterLevelPin = A0; // Analog pin connected to water level sensor
int waterLevelThreshold = 500; // Adjust this threshold according to your sensor

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200); // Start serial communication
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(waterLevelPin, INPUT);
  
  digitalWrite(led1Pin, LOW); // Ensure LED1 is initially off
  digitalWrite(led2Pin, LOW); // Ensure LED2 is initially off

  // Set static IP configuration
  WiFi.config(staticIP, gateway, subnet);
  
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
  server.on("/", HTTP_GET, handleRoot);
  server.on("/led1on", HTTP_GET, handleLed1On);
  server.on("/led1off", HTTP_GET, handleLed1Off);
  server.on("/led2on", HTTP_GET, handleLed2On);
  server.on("/led2off", HTTP_GET, handleLed2Off);
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
//  if (waterLevel < waterLevelThreshold) {
//    digitalWrite(led2Pin, HIGH); // Turn on water pump
//  } else {
//    digitalWrite(led2Pin, LOW); // Turn off water pump
//  }
  delay(1000);
}

void handleRoot() {
  // Read water level sensor
  int waterLevel = analogRead(waterLevelPin);
  
  // Prepare HTML content with LED control buttons and water level information
  String htmlContent = "<html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'><style>body { background-color: blue; font-size: 20px; } h1, h2 { color: white; } button { padding: 15px 30px; font-size: 24px; border-radius: 20px; background-color: transparent; border: 2px solid white; color: white; margin: 5px; }</style></head><body>";
  htmlContent += "<h1 style='text-align:center;'>WORAWORA Smart Farm</h1>";
  htmlContent += "<h2 style='text-align:center; color: white;'>Water Level: " + String(waterLevel) + "</h2>";
  htmlContent += "<div style='display:flex; justify-content: space-between; padding: 20px;'>";
  htmlContent += "<div style='margin-right: 20px;'>";
  htmlContent += "<p style='color: white;'>Water Level: <button onclick=\"fetch('/led1on')\" style='margin-right: 10px; background-color: green; '>ON</button> <button onclick=\"fetch('/led1off')\" style='margin-right: 10px; background-color: red; '>OFF</button></p>";
  htmlContent += "</div>";
  htmlContent += "<div>";
  htmlContent += "<p style='color: white;'>Water Pump: <button onclick=\"fetch('/led2on')\" style='margin-right: 10px; background-color: green; '>ON</button> <button onclick=\"fetch('/led2off')\" style='margin-right: 10px; background-color: red; '>OFF</button></p>";
  htmlContent += "</div>";
  htmlContent += "</div>";
  htmlContent += "<script>setTimeout(function(){window.location.reload(true);}, 5000);</script>";
  htmlContent += "</body></html>";
  
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

void handleLed2On() {
  digitalWrite(led2Pin, HIGH);
  server.send(200, "text/plain", "Water Pump turned on");
}

void handleLed2Off() {
  digitalWrite(led2Pin, LOW);
  server.send(200, "text/plain", "Water Pump turned off");
}
