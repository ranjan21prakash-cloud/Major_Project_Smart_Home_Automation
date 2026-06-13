#include <Servo.h>
const int trigPin = 9;
const int echoPin = 6;
const int servoPin = 11;
const int detectionDistance = 15; 
const int openAngle = 0;         
const int closeAngle = 60;         
const int holdDelay = 15000;       
const int filterSteps = 5;         

Servo doorServo;
// Filter counter variable
int detectionCount = 0;           

void setup() {
  doorServo.attach(servoPin); doorServo.write(closeAngle);  pinMode(trigPin, OUTPUT);  pinMode(echoPin, INPUT);  Serial.begin(9600);
}

void loop() {
  if (ObjectPresent()) {
    Serial.println("Object confirmed! Opening door...");
    doorServo.write(openAngle);  
    delay(holdDelay);            
    detectionCount = 0; 
  } 
  
  else {
    doorServo.write(closeAngle); 
  }
}

bool ObjectPresent() {
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0343 / 2;
  
  Serial.print("Current Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Consecutive Count: ");
  
  if (distance > 0 && distance <= detectionDistance) {
    detectionCount++;
  } else {
    detectionCount = 0; 
  }
  
  Serial.println(detectionCount);

  if (detectionCount >= filterSteps) {
    return true;
  }
  
  return false;
}
