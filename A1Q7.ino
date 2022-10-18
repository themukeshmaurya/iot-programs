#define PULLUPBTN 13
#define LED 12
void setup() {
  // put your setup code here, to run once:
  pinMode(PULLUPBTN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(PULLUPBTN) == LOW) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}