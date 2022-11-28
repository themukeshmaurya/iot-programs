// A1Q13. To interface IR Sensor with Arduino and write a program to blink red or white LED. If the Transmitter transmit and Photodiode receives the rays then glow White LED else glow Red LED/play the buzzer.

#define IRPIN 13
#define LED1 12
#define LED2 11
#define BUZZ 10

void setup() {
  Serial.begin(9600);
  pinMode(IRPIN, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  Serial.println("IR Range : ");
  Serial.println(digitalRead(IRPIN));
  delay(10);

  if (digitalRead(IRPIN) == 1) {
    digitalWrite(LED2, HIGH);
    digitalWrite(BUZZ, HIGH);
    digitalWrite(LED1, LOW);
  } else {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(BUZZ, LOW);
  }
}