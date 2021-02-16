#include <HX711.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define DT A3
#define SCK A2
#define sw 9

HX711 scale;

float value;
void setup() {
  value = 0;
  lcd.begin(16, 2);
  scale.begin(DT, SCK);
  scale.tare(10);
  pinMode(sw, INPUT_PULLUP);
  lcd.print("Ready");
}
void loop() {
  if(digitalRead(sw)==HIGH){
    lcd.clear();
    value = (scale.get_value()*0.212389816)/79.96728456;
    lcd.print(value);
  }
  delay(100);
}
