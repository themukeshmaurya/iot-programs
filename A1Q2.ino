// A1Q2. To interface LED with ESP32(Node MCU-8266) and write a program to turn ON/OFF LED light at interval of every 1 Sec.

#define LED1 13

void setup() {
  pinMode(LED1, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH);
  delay(1000);
  digitalWrite(LED1, LOW);
  delay(1000);
}