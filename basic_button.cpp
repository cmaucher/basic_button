#include "basic_button.h"

MyButton::MyButton(int pin)
    {
        button_pin = pin;
        pinMode(button_pin, OUTPUT);
        prev_state = LOW;
        prev_time = 0;
    }


int MyButton::debounce(unsigned long delay)
{
    int result = prev_state;
    button_state = digitalRead(button_pin);

    if(button_state != prev_state)
    {
        if(millis()-prev_time >= delay)
        {
            if(button_state == HIGH)
            {
                result = HIGH;
                prev_state = HIGH;
            }
            else if(button_state = LOW)
            {
                result = LOW;
                prev_state = LOW;
            }
        }
    }
    else
    {
        prev_time = millis();
    }

    return result;
    
}