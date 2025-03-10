#include <DHT.h>
#define DHTPIN 2          // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11     // DHT sensor type (DHT11 or DHT22)

const int smokeSensorPin = 3; // Digital pin connected to the smoke sensor
const int ledPin = 13;        // Connect an LED (with resistor) to digital pin 13

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor


const int pirSensorPin = 7; // Connect the PIR sensor output to digital pin 7
  // Connect an LED (with resistor) to digital pin 13

void setup() {

Serial.begin(9600);    // Initialize serial communication
  pinMode(smokeSensorPin, INPUT); // Set smoke sensor pin as input
  pinMode(ledPin, OUTPUT);// Set LED pin as output
  dht.begin();            // Initialize DHT sensor

  pinMode(pirSensorPin, INPUT); // Set PIR sensor pin as input
  pinMode(ledPin, OUTPUT);      // Set LED pin as output
}

void loop() {

  float temperature = dht.readTemperature();
  int smokeValue = digitalRead(smokeSensorPin);
  int pirValue = digitalRead(pirSensorPin);

  Serial.print(temperature);
  Serial.print(",");
  Serial.print(smokeValue);
  Serial.print(",");
  Serial.println(pirValue);

  delay(1000); // Send data every second
}
