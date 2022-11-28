// A1Q3. To interface 2 LED with different colour and write a program to turn ON/OFF LED light at a same time. 

#define LED1 13
#define LED2 12

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  delay(1000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  delay(1000);
}