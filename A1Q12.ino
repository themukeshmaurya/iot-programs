#define IRPIN 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IRPIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("IR Range : ");
  Serial.println(digitalRead(IRPIN));
  delay(1000);
}