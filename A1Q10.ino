#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11

int arr[10];

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(DHTPIN, INPUT);
  dht.begin();
}

void loop() {

  int sumOfH = 0;
  int sumOfTempC = 0;
  int sumOfTempF = 0;

  for (int i = 0; i < 10; i++) {
    float h = dht.readHumidity();
    arr[i] = h;
    sumOfH = sumOfH + h;
    Serial.print("Humidity");
    Serial.print(" : ");
    Serial.println(h);
    delay(1000);
  }

  delay(1000);
  Serial.print("Average");
  Serial.print(" : ");
  Serial.println(sumOfH / 10);
  delay(1000);

  for (int i = 0; i < 3; i++) {
    float c = dht.readTemperature();
    float f = dht.readTemperature(true);
    sumOfTempC = sumOfTempC + c;
    sumOfTempF = sumOfTempF + f;
  }
  delay(1000);

  Serial.print("Celcius : ");
  Serial.print(sumOfTempC);
  if (sumOfTempC % 2 == 0) {
    Serial.println(" number is even...");
  } else {
    Serial.println(" number is odd...");
  }

  Serial.print("Feranhate : ");
  Serial.print(sumOfTempF);
  if (sumOfTempF % 2 == 0) {
    Serial.println(" number is even...");
  } else {
    Serial.println(" number is odd...");
  }

  delay(1000);
}