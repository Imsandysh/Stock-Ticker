#include <LiquidCrystal.h>
String str = "";
float o;
float c;
String s;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16, 2);
lcd.setCursor(0,0);
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()>0){
  s = Serial.readStringUntil('*');
  o = Serial.parseFloat();
  c = Serial.parseFloat();
 
}
lcd.print(s + "open:" + o);
lcd.setCursor(0,1);
lcd.print("current:");
lcd.print(c);
delay(2000);
for (int positionCounter = 0; positionCounter < 17; positionCounter++) {
lcd.scrollDisplayLeft();
delay(200);
}
delay(500);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("change: ");
lcd.print(c-o);
delay(2000);
for (int positionCounter = 0; positionCounter < 17; positionCounter++) {
lcd.scrollDisplayLeft();
delay(200);
}
lcd.clear();
}
