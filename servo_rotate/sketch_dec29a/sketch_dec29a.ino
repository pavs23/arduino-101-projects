#include <Servo.h>

Servo myServo;

// Potentiometer PIN value
int const potPin = A0;

// Value being read in by the potentiometer
int potVal;

// Servo rotation angle
int angle;


void setup() {
  // put your setup code here, to run once:

  myServo.attach(9);
  // We want to read things from the potentiometer and print them out
  // on the console.
  // We want to see how the value fluctuates as the servo rotates.
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);


  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);

}
