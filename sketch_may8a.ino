const int lm35Pin = A0;
const int buzzerPin = 8;
const int redLED = 9;
const int greenLED = 10;
const float threshold = 25.0;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int total = 0;
  for (int i = 0; i < 50; i++) {
    total += analogRead(lm35Pin);
    delay(5);
  }
  int raw = total / 50;

  float voltage = raw * (5.0 / 1023.0);
  float temperature = voltage * 100.0;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature >= threshold) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzerPin, LOW);
  }

  delay(1000);
}