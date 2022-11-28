// A1Q6. Write a program to play a melody using buzzer.

#define BUZZ 12
void setup() {
  pinMode(BUZZ, OUTPUT);
}

void loop() {
    digitalWrite(BUZZ, LOW);
    delay(50);
    digitalWrite(BUZZ, HIGH);
    delay(100);
    digitalWrite(BUZZ, LOW);
    delay(260);
    digitalWrite(BUZZ, HIGH);
    delay(200);
    digitalWrite(BUZZ, LOW);
    delay(50);
    digitalWrite(BUZZ, HIGH);
    delay(400);
    digitalWrite(BUZZ, LOW);
    delay(340);
    digitalWrite(BUZZ, HIGH);
    delay(500);
    digitalWrite(BUZZ, LOW);
    delay(50);
    digitalWrite(BUZZ, HIGH);
    delay(400);
}