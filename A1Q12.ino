// A1Q12. To interface IR Sensor with Arduino and write a program to print readings of IR sensor.

#define IRPIN 13

void setup() {
  Serial.begin(9600);
  pinMode(IRPIN, INPUT);
}

void loop() {
  Serial.println("IR Range : ");
  Serial.println(digitalRead(IRPIN));
  delay(1000);
}