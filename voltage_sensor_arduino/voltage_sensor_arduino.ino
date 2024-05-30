//// Define pin connections
//const int voltageSensorPin = A2; 
//const int relay1Pin = 8; 
//const int relay2Pin = 9; 
//const int relay3Pin = 10; 
//// Define voltage thresholds
//const float voltageThresholdOn = 0.01; 
//const float voltageThresholdOff = 0.00; 
//void setup() {
//  Serial.begin(9600);
//  pinMode(relay1Pin, OUTPUT);
//  pinMode(relay2Pin, OUTPUT);
//  pinMode(relay3Pin, OUTPUT);
//
//  // Initialize relays to their initial states
//  digitalWrite(relay1Pin, LOW); 
//  digitalWrite(relay2Pin, LOW); 
//  digitalWrite(relay3Pin, HIGH); 
//}
//
//void loop() {
//  // Read the voltage value from the sensor
//  int sensorValue = analogRead(voltageSensorPin);
//  float voltage = sensorValue * (5.0 / 1023.0); 
//  
//  Serial.print("Voltage: ");
//  Serial.print(voltage);
//  Serial.println(" V");
//
//  // Check if the voltage exceeds the threshold to trigger relay 2
//  if (voltage > voltageThresholdOn) {
//    digitalWrite(relay1Pin, LOW); 
//    delay(180000);
//    digitalWrite(relay2Pin, HIGH); 
//    digitalWrite(relay3Pin, HIGH); 
//    delay(60000);
//    Serial.println("Voltage exceeded threshold. Turning on relay 2.");
//  }
//  // Check if the voltage drops below the threshold to switch back to relay 1
//  else if(voltage <= voltageThresholdOff) {
//    digitalWrite(relay1Pin, LOW); 
//    digitalWrite(relay2Pin, LOW); 
//    digitalWrite(relay3Pin, LOW); 
//    Serial.println("Voltage dropped below threshold. Turning on relay 1.");
//    delay(500);
//  }
//
//  delay(1000); // Delay for stability
//}





const byte voltageSensor1 = A2;
const byte relay1 = 8;
const byte relay2 = 9;
const byte relay3 = 10;
float voltage1;
float R1 = 47000.0;
float R2 = 33000.0;

void setup() {
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(voltageSensor1, INPUT);
}

void loop() {
  int voltageValue1 = analogRead(voltageSensor1); // Read voltage from voltageSensor1
  voltage1 = voltageValue1 * (5.0 / 1024.0) * ((R1 + R2) / R2); // Convert voltage value to voltage
  
  if (voltage1 == 0.00) {
    digitalWrite(relay1, LOW);
    delay(500);
    digitalWrite(relay3, LOW);
    delay(500);
    digitalWrite(relay2, LOW);
    delay(500);
    Serial.print("Voltage1 = ");
    Serial.println(voltage1);
    delay(50);
  } 
  else if (voltage1 > 0.02)
  {
    digitalWrite(relay3, HIGH);
    delay(500); //30000
    digitalWrite(relay2, HIGH);
    digitalWrite(relay1, LOW);
    delay(500); //3600000
//    digitalWrite(relay1, LOW);
//    delay(500);
//    digitalWrite(relay3, LOW);
//    delay(500);
//    digitalWrite(relay2, LOW);
//    delay(500);
    Serial.print("voltage1= ");
    Serial.println(voltage1);
    delay(50);
  }

  delay(50); // Delay for stability
}
