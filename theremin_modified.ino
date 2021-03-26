int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13;


void setup() {
  // sebastian added this
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  while (millis() < 5000000) {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop() {
  sensorValue = analogRead(A0);
  // sebastian added this
  Serial.println(sensorValue);

  // int pitch = map(sensorValue,sensorLow,sensorHigh, 50, 4000);
  // i want my tone lower
  //when there's stuff you don't know, look it up: https://www.arduino.cc/reference/en/language/functions/math/map/
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 800);
  // e.g. tone(pin, frequency, duration)
  //tone(8,pitch,20);

  delay(10);
}
