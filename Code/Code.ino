#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>
#include <dht.h>

// Define color sensor pins
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

unsigned long humiditySensorPreviousMillis = 0;
const unsigned long humiditySensorInterval = 20;
unsigned long pulseSensorPreviousMillis = 0;
const unsigned long pulseSensorInterval = 20;
unsigned long colorSensorPreviousMillis = 0;
const unsigned long colorSensorInterval = 20;

int PulseSensorPurplePin = A0;
int Signal;

// Variables for Color Pulse Width Measurements
int redPW = 0;
int greenPW = 0;
int bluePW = 0;

dht DHT;
const int RS = 2, EN = 3, D4 = 10, D5 = 11, D6 = 12, D7 = 13;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);   // Set Uno pins that are connected to LCD, 4-bit mode
const int relay_pin = A1;  // Relay pin connected to the LED

void setup() {
  // pinMode(buzzer, OUTPUT); // Set buzzer - pin 0 as an output
  pinMode(0, OUTPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  pinMode(sensorOut, INPUT);

  Serial.begin(9600);

  lcd.begin(16, 2);
  pinMode(relay_pin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // Humidity and temperature function
  if (currentMillis - humiditySensorPreviousMillis >= humiditySensorInterval) {
    humiditySensorPreviousMillis = currentMillis;
    updateHumidityAndTemperature();
  }

  // Pulse sensor function
  if (currentMillis - pulseSensorPreviousMillis >= pulseSensorInterval) {
    pulseSensorPreviousMillis = currentMillis;
    readPulseSensor();
  }

  // Color sensor function
  if (currentMillis - colorSensorPreviousMillis >= colorSensorInterval) {
    colorSensorPreviousMillis = currentMillis;
    readColorSensor();
  }
}

void updateHumidityAndTemperature() {
  int readDHT = DHT.read11(9);    // Grab 40-bit data packet from DHT sensor

  // Control relay based on temperature
  if (DHT.temperature > 31) {
    digitalWrite(relay_pin, LOW); // LED OFF
  } else {
    digitalWrite(relay_pin, HIGH); // LED ON
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(200);
}

void readPulseSensor() {
  Signal = analogRead(PulseSensorPurplePin);
  Serial.println(Signal);  // Print the signal value for debugging

  // Send the signal value to the plotter (for example, in the format "S,123")
  Serial.print("S,");
  Serial.println(Signal);
}

void readColorSensor() {
  redPW = getRedPW();
  greenPW = getGreenPW();
  bluePW = getBluePW();

  Serial.print("Red: ");
  Serial.print(redPW);
  Serial.print(" Green: ");
  Serial.print(greenPW);
  Serial.print(" Blue: ");
  Serial.print(bluePW);

  // Check if the color is yellow
  if ((120 < redPW) && (redPW < 160) && (greenPW > 160) && (greenPW < 220) && (bluePW > 160) && (bluePW < 210)) {
    Serial.print(" Yellow");
  } else if ((110 < redPW) && (redPW < 170) && (greenPW > 170) && (greenPW < 210) && (bluePW > 140) && (bluePW < 180)) {
    Serial.print(" Light Yellow");
  } else {
    Serial.print(" Unknown");
  }
}

int getRedPW() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  int PW;
  PW = pulseIn(sensorOut, LOW);
  return PW;
}

int getGreenPW() {
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  int PW;
  PW = pulseIn(sensorOut, LOW);
  return PW;
}

int getBluePW() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  int PW;
  PW = pulseIn(sensorOut, LOW);
  return PW;
}
