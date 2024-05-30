
//int value = 0;
//const int voltageSensor = A0;
//float voltage1;
//float R1 = 47000.0;
//float R2 = 33000.0;
//
//
//void setup() {
//  // put your setup code here, to run once:
//pinMode(voltageSensor, INPUT);
//  Serial.begin(9600);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
// int voltageValue1 = analogRead(voltageSensor1); //read voltage form voltageSensor
//
//if (voltageSensor => 0.01){
//  Serial.print("Voltage1 = ");
//    Serial.println(voltage1);
//}
//}


int sensorPin = A2; // Analog input pin
int sensorValue;    // Raw ADC value
float voltage;      // Calculated voltage

void setup() {
    Serial.begin(9600);  // Initialize serial communication
}

void loop() {
    sensorValue = analogRead(sensorPin); // Read analog value
    voltage = sensorValue * (5.0 / 1023.0); // Convert to voltage
    Serial.print("Raw Value: ");
    Serial.print(sensorValue);
    Serial.print("\tVoltage: ");
    Serial.println(voltage); // Display voltage with 3 decimal places
    delay(1000); // Wait for 1 second
}
