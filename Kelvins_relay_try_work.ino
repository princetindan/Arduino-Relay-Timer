//int value = 0;
//
//const int currentSensor = A1;
//cont byte voltageSensor = A2;
//const byte relay = 6;
//const byte relay2 = 7;
//float voltage;
//float R1 = 47000.0;
//float R2 = 33000.0;
//const float maxCurrent = 20.0; // Amps
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(relay, OUTPUT);
//  pinMode(relay2, OUTPUT);
//  pinMode(currentSensor,INPUT);
//  pinMode(voltageSensor, INPUT);
//}
//
//void loop() {
//  value = analogRead(A0);
//  value = analogRead(A2);
//  voltage = value * (5.0 / 1024) * ((R1 + R2) / R2);
//
// // Read the voltage from the ACS712 current sensor module
//  //float voltage = analogRead(currentSensor);
//
//  // Convert the voltage to current
//  float current = (voltage / 1024.0) * MAX_CURRENT;
//
//  if (voltage > 0.01) {
//    digitalWrite(relay, LOW);
//    digitalWrite(relay2,HIGH);
//    Serial.print("Voltage = ");
//    Serial.println(voltage);
//    delay(500);   
//  }
//  
//
//  else if(current > 00.01) {
//   digitalWrite(relay2,HIGH);
//   Serial.print("Current: ");
//  Serial.println(current);
//  
//}
////when baterry is 12/13V the voltage A2, relay2 should 
////should switch back ot relay1.
//
////when current sensor recieves less current also should 
////make the relay2 stopand switch to relay1
//  
//  else {
//    digitalWrite(relay, HIGH);
//    delay(1800000);
//    Serial.print("Voltage = ");
//    Serial.println(voltage);
//    digitalWrite(relay2,LOW);
//    Serial.print("Voltage = ");
//    Serial.println(voltage);
//    delay(500);
//    
//  }
//}


int value = 0;

const int currentSensor = A1;
const byte voltageSensor1 = A2;
const byte voltageSensor2 = A0;
const byte relay1 = 6;
const byte relay2 = 7;
float voltage1;
float voltage2;
float R1 = 47000.0;
float R2 = 33000.0;
const float maxCurrent = 60.0; // Amps

void setup() {
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(currentSensor,INPUT);
  pinMode(voltageSensor2, INPUT);
  pinMode(voltageSensor1, INPUT);
}

void loop() {
  int voltageValue2 = analogRead(voltageSensor2); //read voltage form voltageSensor
  int currentValue = analogRead(currentSensor); // read current from currentSensor
  int voltageValue1 = analogRead(voltageSensor1); //to read voltage from voltageSensor1 

  // to calculate voltage based on voltage sensor reads
  voltage2 = voltageValue2 * (5.0 / 1024) * ((R1 + R2) / R2);
  voltage1 = voltageValue1 * (5.0 / 1024) * ((R1 + R2) / R2);

  // Convert the voltage to current
  float current = (currentValue / 1024.0) * maxCurrent;

  if (voltage1 > 12.0 && voltage1 < 13.0) {
    // Switch to relay1
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    Serial.print("Voltage1 = ");
    Serial.println(voltage1);
  } 
  else if (voltage2 > 0.01) {
    // Switch to relay1
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, HIGH);
    Serial.print("Voltage2 = ");
    Serial.println(voltage2);
    //delay(1800000);
    delay(6000);
  } 
  else if (current < 2) {
    // Switch to relay1
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    Serial.print("Current: ");
    Serial.println(current);
  } 
  else if (voltage2 > 0.05) {
    // Switch to relay2
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, HIGH);
    Serial.print("Voltage2 = ");
    Serial.println(voltage2);
  }
  else {
    // put off switch to relay1 and delay 
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);
    Serial.print("Voltage1 = ");
    Serial.println(voltage1);
    //delay(1800000);
    delay(6000);
  }

  delay(500); // delay for stability
}

