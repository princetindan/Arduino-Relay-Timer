/////*New blynk app project
////   Home Page
////*/
////
//////Include the library files
////#define BLYNK_PRINT Serial
////#include <ESP8266WiFi.h>
////#include <BlynkSimpleEsp8266.h>
////
////#define BLYNK_AUTH_TOKEN "" //Enter your blynk auth token
////
////char auth[] = BLYNK_AUTH_TOKEN;
////char ssid[] = "";//Enter your WIFI name
////char pass[] = "";//Enter your WIFI password
////
//////Get the button value
////BLYNK_WRITE(V0) {
////  digitalWrite(D0, param.asInt());
////}
////
////void setup() {
////  //Set the LED pin as an output pin
////  pinMode(D0, OUTPUT);
////  //Initialize the Blynk library
////  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
////}
////
////void loop() {
////  //Run the Blynk library
////  Blynk.run();
////}
//
//#define BLYNK_TEMPLATE_ID "TMPL24VNPtpUe"
//#define BLYNK_TEMPLATE_NAME "led blynk"
//
//#define BLYNK_TEMPLATE_NAME "led blynk"
//#define BLYNK_AUTH_TOKEN "w37TdOZU1rnsIJA4YhZI0679t6aS7q2A"
//
//#define BLYNK_PRINT Serial
//#include <WiFi.h>
//#include <BlynkSimpleEsp32.h>
//
//char auth[] = "syReWK-vbw8olZtxhcUN-aYiC_GKkon1"; // Blynk authentication token
//char ssid[] = "damn";    // Your WiFi Name
//char pass[] = "kissmenoww"; // Your Wifi Password
//
//BLYNK_WRITE(V2) {
//  digitalWrite(D2, param.asInt());
//}
//
//void setup() {
//  //Set the LED pin as an output pin
//  pinMode(D2, OUTPUT);
//  //Initialize the Blynk library
//  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
//}
//
//void loop() {
//  //Run the Blynk library
//  Blynk.run();
//}
//
////void setup() {
////  Serial.begin(9600);
////  pinMode(ledPin, OUTPUT);
////  
////  Blynk.begin(auth, ssid, pass, IPAddress(139, 59, 206, 133), 8080); // Replace with your Blynk server IP and port
////
////  Serial.println("");
////  Serial.println("WiFi connected");
////  Serial.println("Blynk connected");
////}
////
////void loop() {
////  Blynk.run();
////  timer.run();
////}
////
////BLYNK_WRITE(V2) { // Virtual pin to control the LED manually
////  digitalWrite(ledPin, param.asInt());
////}
////
////BLYNK_WRITE(V2) { // Virtual pin for periodic updates
////  if (param.asInt() == 1) {
////    timer.setInterval(1000L, blinkLED); // Set interval to 1000 milliseconds (1 second)
////  } else {
////    timer.disableAll();
////    digitalWrite(ledPin, LOW); // Turn off LED when periodic updates are disabled
////  }
////}
////
////void blinkLED() {
////  digitalWrite(ledPin, !digitalRead(ledPin)); // Toggle LED state
////}




/*New blynk app project
   Home Page
*/


//#define BLYNK_PRINT Serial
//#include <WiFi.h>
//#include <BlynkSimpleEsp32.h>



//Include the library files
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define BLYNK_AUTH_TOKEN "syReWK-vbw8olZtxhcUN-aYiC_GKkon1" //Enter your blynk auth token

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "damn";//Enter your WIFI name
char pass[] = "kissmenoww";//Enter your WIFI password

//Get the button value
BLYNK_WRITE(V2) {
  digitalWrite(D2, param.asInt());
}

void setup() {
  //Set the LED pin as an output pin
  pinMode(D2, OUTPUT);
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
}
