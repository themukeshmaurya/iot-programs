// A1Q15. Take only 3 readings of ultrasonic sensor (after trigger) at the intervals of 2 seconds then stop taking further readings. Average the readings and find out if that number is an Armstrong number or not. 

#define ECHO 6
#define TRIG 7

long duration;
int distance;

int n, r, s = 0, temp, sum, avg;

void setup() {
  Serial.begin(9600);
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIG, HIGH);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration * 0.034) / 2;
  Serial.println(distance);
  sum = 0;
  for (int i = 0; i < 3; i++) {
    sum += distance;
  }
  delay(2000);
  digitalWrite(TRIG, LOW);

  avg = sum / 3;

  Serial.println(avg);

  n = avg;

  temp = n;

  while (n > 0) {
    r = n % 10;
    s = s + (r * r * r);
    n = n / 10;
  }

  if (temp == s) {
    Serial.println("armstrong  number ");
  } else {
    Serial.println("not armstrong number");
  }
}