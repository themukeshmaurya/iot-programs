// A1Q9. Use DHT 11 and glow the red light if temperature goes above 30’c and play the buzzer and blink the green LED if temperature goes below 30’c and stop the buzzer.

#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11
#define LED 12
#define BUZZ 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(DHTPIN, INPUT);
  dht.begin();
  pinMode(LED, OUTPUT);
  pinMode(BUZZ, OUTPUT);
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

  if (c > 30) {
    digitalWrite(BUZZ, HIGH);
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(BUZZ, LOW);
    digitalWrite(LED, HIGH);
  }
}