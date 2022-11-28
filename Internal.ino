// Write a program on pull up button press and event start the seven segment counter by 5,4,3,2,1 then start the taking 10 records on dht11 and perform the average temp of humidity and print that on serial.

#include "DHT.h"
#define DHTPIN 12
#define DHTTYPE DHT11

float hsum = 0, havg = 0, tsum = 0, tavg = 0;
int pullup = 10, led = 11;
float h, t;

int num_array[5][7] = {
  { 1, 0, 0, 1, 1, 1, 1 },
  { 0, 0, 1, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 1, 1, 0 },
  { 1, 0, 0, 1, 1, 1, 0 },
  { 0, 1, 0, 0, 1, 0, 0 }
};

DHT dht(DHTPIN, DHT11);

void num_write(int);

void setup() {
  pinMode(pullup, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void temp() {
  for (int i = 0; i < 10; i++) {
    h = dht.readHumidity();
    Serial.print(h);
    hsum += h;
    t = dht.readTemperature();
    Serial.print(t);
    tsum += t;
    delay(3000);
  }

  havg = hsum / 10;
  tavg = tsum / 10;
  Serial.println("Average of Temperature");
  Serial.print(tavg);
  Serial.println("Average of Humidity");
  Serial.print(havg);
}

void num_write(int number) {
  int pin = 2;
  for (int k = 0; k < 7; k++) {
    if (pin == 5) {
      pin++;
    }
    digitalWrite(pin, num_array[number][k]);
    pin++;
  }
}

void counter() {
  digitalWrite(led, LOW);
  delay(2000);
  for (int j = 5; j > 0; j--) {
    delay(1000);
    num_write(j - 1);
  }
  delay(3000);
  temp();
  exit;
}

void loop() {
  if (digitalRead(pullup) == LOW) {
    counter();
  } else {
    digitalWrite(led, HIGH);
  }
}