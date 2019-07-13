/*    Arduino Anemometer Radio Receiver using HC-12 and LCD Module   */

/*  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)*/

#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

SoftwareSerial HC12(8, 9); // HC-12 TX Pin, HC-12 RX Pin

/*********/
/* SETUP */
/*********/  
void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12

  lcd.begin(20, 2);
  lcd.setCursor(0, 0);  
  // Print a message to the LCD.
  lcd.print("    Anemometer"); 
  lcd.setCursor(0, 1);  
  lcd.print("    Test");           
  delay(1000); 
  lcd.clear(); 
}

/*************/
/* PROGRAMME */
/*************/
void loop() {
  while (HC12.available()) {      // If HC-12 has data
    int incomingChar = HC12.read();
    Serial.print ( "buffer : " );
    Serial.println (incomingChar); 
    lcd.setCursor(0, 0); 
    lcd.print(incomingChar); 
    lcd.setCursor(4, 0); 
    lcd.print("Km/h");     
  }
}
