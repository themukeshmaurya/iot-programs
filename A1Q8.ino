// A1Q8. To interface DHT11 Sensor with Arduino and write a program to print temperature and humidity reading.

#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(DHTPIN, INPUT);
  dht.begin();
}

void loop() {

  float h = dht.readHumidity();
  float f = dht.readTemperature(true);
  float c = dht.readTemperature();

  if (isnan(h) || isnan(f) || isnan(c)) {
    Serial.println("Not a value");
  } else {
    Serial.println("H : ");
    Serial.println(h);
    Serial.println("F : ");
    Serial.println(f);
    Serial.println("C : ");
    Serial.println(c);
  }

  delay(2000);
}