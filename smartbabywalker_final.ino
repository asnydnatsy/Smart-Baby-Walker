#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  myServo.attach(servoPin);
  myServo.write(0); /
  
  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);


  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2; // distance in cm

  Serial.print("Distance: ");
  Serial.println(distance);


  if (distance > 5) {
    myServo.write(0);   // rotate to 0°
  } else {
    myServo.write(90);  // rotate to 90°
  }

  delay(500); 
}