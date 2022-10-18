#define 

int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  lcd.begin(16, 2);
  lcd.print("Praful");
}

void loop() {  
  for(int i = 0; i < 16; i++)
  {
    lcd.scrollDisplayRight();
    delay(1000);
  
  }
  for(int i = 16; i >= 0; i--)
  {
    lcd.scrollDisplayLeft();
    delay(1000);
  }
  
}