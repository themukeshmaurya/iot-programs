// A1Q5. To interface 2 LED with different colour and write a program to turn ON/OFF LED light on after another, which works light police Van Light. And also play the buzzer of police van or ambulance.

#define LED1 8
#define BUZZ 12
#define LED2 13

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH);
  digitalWrite(BUZZ, LOW);
  digitalWrite(LED2, LOW);
  delay(140);
  digitalWrite(LED1, LOW);
  digitalWrite(BUZZ, HIGH);
  digitalWrite(LED2, HIGH);
  delay(140);
}