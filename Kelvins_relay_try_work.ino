int value = 0;
const byte relay = 6;
float voltage;
float R1 = 47000.0;
float R2 = 33000.0;

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
}

void loop() {
  value = analogRead(A0);
  voltage = value * (5.0 / 1024) * ((R1 + R2) / R2);

  if (voltage > 0.01) {
    digitalWrite(relay, HIGH);
    Serial.print("Voltage = ");
    Serial.println(voltage);
    delay(500);
  } else {
    digitalWrite(relay, LOW);
    Serial.print("Voltage = ");
    Serial.println(voltage);
    delay(500);
  }
}
