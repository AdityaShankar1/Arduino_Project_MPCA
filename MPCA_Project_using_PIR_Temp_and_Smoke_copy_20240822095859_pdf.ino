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

// Read temperature from DHT sensor
  float temperature = dht.readTemperature();

  // Read digital output from smoke sensor
  int smokeValue = digitalRead(smokeSensorPin);


  // If smoke is detected, turn on the LED
  if (smokeValue == HIGH) {
    digitalWrite(ledPin, HIGH); // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED
  }

  delay(1000);  // Delay between readings

  int pirValue = digitalRead(pirSensorPin); // Read PIR sensor value
  
  if (pirValue == HIGH) {
    // Motion detected
    digitalWrite(ledPin, HIGH); // Turn on the LED
    delay(500); // Wait for 1/2 second
  } else {
    // No motion detected
    digitalWrite(ledPin, LOW); // Turn off the LED
  }
}
