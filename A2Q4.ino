#include <LiquidCrystal.h>

#define ECHO 6
#define TRIG 7

long duration;
int distance;

int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8, sum, avg, n, r, s = 0, temp;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  lcd.begin(16, 2);
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
  sum = 0;

  for (int i = 0; i < 3; i++) {
    sum += distance;
  }

  avg = sum / 3;

  n = avg;

  temp = n;

  while (n > 0) {
    r = n % 10;
    s = (s * 10) + r;
    n = n / 10;
  }

  Serial.println(distance);
  lcd.clear();

  if (temp == s)
  {
    lcd.print("palindrome");
  }
  else
  {
    lcd.print("not palindrome");
  }

}