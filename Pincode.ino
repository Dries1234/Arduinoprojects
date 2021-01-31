#include <Key.h>
#include <Keypad.h>

const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte rowPins[rows] = {8, 7, 6, 5};
byte columnPins[cols] = {4, 3, 2, 9};
Keypad keyPad = Keypad(makeKeymap(keys), rowPins, columnPins, rows, cols);
String pincode = "1234";
void setup()
{
    Serial.begin(9600);
    keyPad.setHoldTime(1000); //set time to hold at 1 second
    keyPad.setDebounceTime(50);
}

void loop()
{
    char first = keyPad.waitForKey();
    String code = "";
    switch (first)
    {
    case '*':
        
            Serial.println("Enter password");
            //play beep
            code = "";
            for (int i = 0; i < 4; i++)
            {
                code += keyPad.waitForKey();
            }
            if (code == pincode)
            {
              Serial.println("Enter new password");
                //play correct beep
                code = "";
                for (int i = 0; i < 4; i++)
                {
                    code += keyPad.waitForKey();
                }
                pincode = code;
                Serial.println(pincode);
                //play confirm beep
            }
            else
            {
                //play wrong beep
            }
    
        break;
    default:
        code = "";
        code += first;
        for (int i = 0; i < 3; i++)
        {
            char temp = keyPad.waitForKey();
            code += temp;
    
        }
        if (code == pincode)
        {
          Serial.println("correct");
            //play correct beep
        }
        else
        {
          Serial.println("incorrect");
        }
        break;
    }
}
