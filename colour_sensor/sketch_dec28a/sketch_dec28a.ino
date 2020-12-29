const int GREEN_LED_PIN = 9;
const int RED_LED_PIN = 10;
const int BLUE_LED_PIN = 11;

const int RED_SENSOR_PIN = A0;
const int GREEN_SENSOR_PIN = A1;
const int BLUE_SENSOR_PIN = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  redSensorValue = analogRead(RED_SENSOR_PIN);
  delay(5);
  greenSensorValue = analogRead(GREEN_SENSOR_PIN);
  delay(5);
  blueSensorValue = analogRead(BLUE_SENSOR_PIN);
  delay(5);

  
  Serial.print("Raw sensor values \t red: ");
  Serial.print(redSensorValue);
  
  Serial.print("\t green: ");
  Serial.print(greenSensorValue);
  
  Serial.print("\t blue: ");
  Serial.println(blueSensorValue);
  

  analogWrite(GREEN_LED_PIN, greenSensorValue/4);
  analogWrite(BLUE_LED_PIN, blueSensorValue/4);
  analogWrite(RED_LED_PIN, redSensorValue/4);
  
}
