#include<Servo.h>
int distancia = 0;

long readUltrasonicDistance(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT);
    digitalWrite(triggerPin,LOW);
    delayMicroseconds(2);

    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    pinMode(echoPin, INPUT);

    return pulseIn(echoPin, HIGH);
}

Servo motor; 


void setup() {
    pinMode(9, OUTPUT);
    motor.attach(9, 500, 2500);


}

void loop(){
  distancia = 0.01723 * readUltrasonicDistance(7, 6);
    motor.write(0);
    delay(300);

  while (distancia <= 20){
    motor.write(180);
    digitalWrite(8, HIGH);
    delay(300);

    digitalWrite(8, LOW);
    delay(1000);
    distancia = 0.01723 * readUltrasonicDistance(7,6);
  }
}