#include <Servo.h>

Servo myServo;
const int lr = 7; //declaration of red led
const int lg = 8; //declaration of green led.
const int echo = 5; //for echo pin on ultrasonic
const int trig = 6; //for trig pin on ultrasonic
float distance, duration;


void setup()
{
    myServo.attach(9); //pin for servo.
    Serial.begin(9600);
    pinMode(lr,OUTPUT);
    pinMode(lg, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(trig,OUTPUT);
}

void loop()
{
    //to trigger ultra-sonic
    digitalWrite(trig,LOW);
    delay(10);
    digitalWrite(trig,HIGH);
    delay(2);
    digitalWrite(trig,LOW);

    //to measure duration in pulseIn
    duration = pulseIn(echo, HIGH);

    //to calculate distance
    distance = 0.017 * duration;

    if(distance <= 15 )
    {
        myServo.write(180);
        delay(100);
        digitalWrite(lr, HIGH);
        delay(10);
        digitalWrite(lg, LOW);
        delay(10)

    }
    else
    {
        myServo.wirte(0);
        delay(50);
        digitalWrite(lr, LOW);
        delay(50);
        digitalWrite(lg, HIGH);
        delay(10);

    }
    // myServo.attach(95); //to make servo move 95 degree. 
    // delay(1000); //delay added for stability. 

}