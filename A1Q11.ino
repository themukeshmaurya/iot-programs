#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11
#define LED 12
#define BUZZ 11

int arr[5];

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(DHTPIN, INPUT);
  dht.begin();
  pinMode(LED, OUTPUT);
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  float c = dht.readTemperature();

  Serial.println("");
  
  for (int i = 0; i < 5; i++) {
    Serial.print("C ");
    Serial.print(i);
    Serial.print(" : ");
    Serial.println(c);
    arr[i] = c;
  }

  int sum = 0;

  for (int i = 0; i < 5; i++) {
    sum = sum + arr[i];
  }

  Serial.print("Average : ");
  Serial.print(sum / 5);
  delay(2000);

  int n = sum / 5, firstTerm = 0, secondTerm = 1;
  Serial.print("Fibonacci Series till ");
  Serial.print(n);
  Serial.println(" terms:");

  for (int i = 1; i <= n; ++i) {
    
    Serial.print(firstTerm);
    Serial.println(", ");

    // compute the next term
    int nextTerm = firstTerm + secondTerm;
    firstTerm = secondTerm;
    secondTerm = nextTerm;
    
  }
}