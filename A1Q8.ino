#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(DHTPIN, INPUT);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

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