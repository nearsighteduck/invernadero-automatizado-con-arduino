#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensor;
float temperatura;
float suma;

void setup() {
  lcd.begin(16,2);
}

void loop() {
  suma = 0;
  for(int i=0; i < 5; i++){
    sensor = analogRead(A0);
    temperatura = ((sensor * 5000.0)/1023)/10;
    suma = temperatura + suma - 50;
    delay(500);
    }

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(suma/5.0,1);
  lcd.print(" C");
}
