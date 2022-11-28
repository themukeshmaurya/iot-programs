// A1Q14. To interface Ultrasonic Sensor with Arduino. Use the ultrasonic sensor and extract the distance of object.

#define ECHO 6
#define TRIG 7

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration * 0.034) / 2;
  Serial.println(distance);
}