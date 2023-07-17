
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.begin();         // initialize the lcd
  lcd.backlight();    // Turn on the LCD screen backlight
}

void loop()
{
  lcd.noCursor();
  lcd.setCursor(4, 0);
  lcd.print("Robotron");
  delay(3000);
  lcd.clear();

  lcd.setCursor(2, 0);
  lcd.print("The human god ");
  lcd.setCursor(2, 1);
  lcd.print("Screen Test");
  delay(3000);
  lcd.clear();
}
