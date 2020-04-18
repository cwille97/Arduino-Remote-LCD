#include <ir_Lego_PF_BitStreamEncoder.h>
#include <boarddefs.h>
#include <IRremoteInt.h>
#include <IRremote.h>
int RECV_PIN = 5;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results))
    {
//        Serial.println(results.value, HEX); // print whatever the hex value is of the button pressed, useful for debugging the value of that button
     switch (results.value) {
     case 0xFF6897: Serial.println("0");break; // 0
     case 0xFF30CF: Serial.println("1");break; // 1
     case 0xFF18E7: Serial.println("2");break; // 2
     case 0xFF7A85: Serial.println("3");break; // 3
     case 0xFF10EF: Serial.println("4");break; // 4
     case 0xFF38C7: Serial.println("5");break; // 5
     case 0xFF5AA5: Serial.println("6");break; // 6
     case 0xFF42BD: Serial.println("7");break; // 7
     case 0xFF4AB5: Serial.println("8");break; // 8
     case 0xFF52AD: Serial.println("9");break; // 9
     case 0xFFFFFFFF: Serial.println("holding number");break; // if you hold for too long you get FFFFFF
     default: Serial.println("other");break; // default
     }

     irrecv.resume(); // Receive the next value
    }
}
