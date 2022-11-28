// A1Q4. To interface BUZZER and write a program to turn ON/OFF Buzzer.

#define BUZZ 13

void setup() {
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  digitalWrite(BUZZ, HIGH);
  delay(1000);
  digitalWrite(BUZZ, LOW);
  delay(1000);
}