#include <Servo.h>
#define trigPin 8
#define echoPin 9
long duration;
int distance;
Servo myservo;

int calculateDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0344/2;
  return distance;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(11);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for (i = 15 ; i <= 165 ; i++)
  {
    myservo.write(i);
    delay(15);
    calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
  for (i = 165 ; i >= 15 ; i--)
  {
    myservo.write(i);
    delay(15);
    calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}