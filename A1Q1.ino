// A1Q1. To interface LED with Arduino and write a program to turn ON/OFF LED light at interval of every 1 Sec.

#define LED 13

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
}