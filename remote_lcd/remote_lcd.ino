#include <ir_Lego_PF_BitStreamEncoder.h>
#include <boarddefs.h>
#include <IRremoteInt.h>
#include <IRremote.h>
#include <LiquidCrystal.h>
int RECV_PIN = 5; // using pin 5
IRrecv irrecv(RECV_PIN);
decode_results results;


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Button pressed: ");
}

void loop()
{
  String pressed = "";
  if (irrecv.decode(&results))
    {
//        Serial.println(results.value, HEX); // print whatever the hex value is of the button pressed, useful for debugging the value of that button
     switch (results.value) {
     case 0xFF6897: Serial.println("0"); pressed = "0"; break; // 0
     case 0xFF30CF: Serial.println("1"); pressed = "1"; break; // 1
     case 0xFF18E7: Serial.println("2"); pressed = "2"; break; // 2
     case 0xFF7A85: Serial.println("3"); pressed = "3"; break; // 3
     case 0xFF10EF: Serial.println("4"); pressed = "4"; break; // 4
     case 0xFF38C7: Serial.println("5"); pressed = "5"; break; // 5
     case 0xFF5AA5: Serial.println("6"); pressed = "6"; break; // 6
     case 0xFF42BD: Serial.println("7"); pressed = "7"; break; // 7
     case 0xFF4AB5: Serial.println("8"); pressed = "8"; break; // 8
     case 0xFF52AD: Serial.println("9"); pressed = "9"; break; // 9
     case 0xFFFFFFFF: Serial.println("holding number");break; // if you hold for too long you get FFFFFF
     default: Serial.println("other");break; // default
     }

    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print(pressed);

     irrecv.resume(); // Receive the next value
    }
}
