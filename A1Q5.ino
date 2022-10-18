#define LED1 8
#define BUZZ 12
#define LED2 13
void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1, HIGH);
  digitalWrite(BUZZ, LOW);
  digitalWrite(LED2, LOW);
  delay(140);
  digitalWrite(LED1, LOW);
  digitalWrite(BUZZ, HIGH);
  digitalWrite(LED2, HIGH);
  delay(140);
}