
const int SENSOR_PIN = A0;
const int BASELINE_TEMP = 20.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(SENSOR_PIN);

  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.print(", degrees C: ");

  float temperature = (voltage - 0.5) * 100;
  Serial.println(temperature);

  if (temperature < BASELINE_TEMP + 2) {

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }

  delay(1000);
}
