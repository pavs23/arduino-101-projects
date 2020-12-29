const int GREEN_LED_PIN = 9;
const int RED_LED_PIN = 11;
const int BLUE_LED_PIN = 10;

int const potPin = A0;
int potVal = 0;

int outputColour = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Set the digital outputs
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);


}

void loop() {

  // Read from the potentiometer
  potVal = analogRead(potPin);

  // Map values from [0,1023] -> [0,255]
  outputColour = map(potVal, 0, 1023, 0, 255);

  // Set out Values for all.
  
  
  analogWrite(GREEN_LED_PIN, outputColour);
  analogWrite(BLUE_LED_PIN, outputColour);
  analogWrite(RED_LED_PIN, outputColour);

  delay(15);

}
