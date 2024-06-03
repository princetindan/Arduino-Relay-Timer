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
  if (voltage1 >= 05.0){ //2 is always on 
    digitalWrite(relay2,LOW );
    delay(500);
    //digitalWrite(relay2,HIGH);
//    //delay();
//    digitalWrite(relay3,HIGH);
//    delay(50000); //delay(50000)
    digitalWrite(relay1,HIGH);
   // delay(50000);
    digitalWrite(relay2,HIGH);
    delay(50000);
    digitalWrite(relay2,LOW);
    digitalWrite(relay1,HIGH);
    digitalWrite(relay3,HIGH );
    //delay(10000); //delay(3600000)
    delay(3650000);
    Serial.print("Voltage= ");
    Serial.println(voltage1);
  }
  else{
    digitalWrite(relay2,HIGH);
    //delay();
    digitalWrite(relay3,LOW);
    digitalWrite(relay1, LOW);
    delay(2000);
    digitalWrite(relay1,LOW );
    digitalWrite(relay3,LOW);
    //delay(500);
     Serial.print("Voltage= ");
    Serial.println(voltage1);
    
  }
  delay(500);
  
  }
