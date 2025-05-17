#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

RTC_DS1307 rtc;

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on backlight
  Wire.begin();
  rtc.begin();

  if (! rtc.isrunning()) {
    lcd.print("RTC is NOT running!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  DateTime now = rtc.now();
  
  int hour = now.hour();
  int minute = now.minute();
  int second = now.second();
  int day = now.day();
  int month = now.month();
  int year = now.year();

  lcd.clear();
  // Display "TIME" in front of the time
  lcd.setCursor(0,0);
  lcd.print("TIME:");
  
  // Display time in 12-hour format with leading zeros
  if(hour < 10) {
    lcd.print("0");
  }
  if(hour == 0) {
    lcd.print("12");
  }
  else if(hour <= 12) {
    lcd.print(hour);
  }
  else {
    lcd.print(hour - 12);
  }
  lcd.print(":");
  
  if(minute < 10) {
    lcd.print("0");
  }
  lcd.print(minute);
  lcd.print(":");
  
  if(second < 10) {
    lcd.print("0");
  }
  lcd.print(second);
  
  if(hour >= 12) {
    lcd.print(" PM");
  } else {
    lcd.print(" AM");
  }
  
  // Display "DATE" in front of the date
  lcd.setCursor(0,1);
  lcd.print("DATE:");
  
  // Display date in dd/mm/yyyy format
  if(day < 10) {
    lcd.print("0");
  }
  lcd.print(day);
  lcd.print("/");
  
  if(month < 10) {
    lcd.print("0");
  }
  lcd.print(month);
  lcd.print("/");
  lcd.print(year);
  
  delay(1000); // Update every second
}