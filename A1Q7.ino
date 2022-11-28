// A1Q7. To interface PULLUP BUTTON with Arduino. write a program to turn ON/OFF LED as per the button pullup.

#define PULLUPBTN 13
#define LED 12

void setup() {
  pinMode(PULLUPBTN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (digitalRead(PULLUPBTN) == LOW) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}