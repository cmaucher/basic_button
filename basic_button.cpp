/////////////////////////////////////////////////////////////////////////////
// This is a class to set up a switch input for debouncing on the Arduino.
// The debounce function will return the switch state after the "delay"
// in ms.
//
// Usage:  Above the setup section, create class instance of MyButton with the 
//          pin number that the switch is attached.  e.g. this_button Mybutton(2)
//          In the loop section, call the debounce function with a time 
//          representing the amount of time to determine a change in the 
//          switch state.  e.g. this_button.debounce(20)
//
// author - Chris Maucher
////////////////////////////////////////////////////////////////////////////

#include "basic_button.h"

MyButton::MyButton(int pin)
    {
        button_pin = pin;  //the pin the switch is attached.
        pinMode(button_pin, INPUT);  //setup the pin mode
        prev_state = LOW; // initial state of the switch
        prev_time = 0; //variable to remember the time
    }


int MyButton::debounce(unsigned long delay)
{
    int result = prev_state;
    button_state = digitalRead(button_pin);

    if(button_state != prev_state)  // check to see if the switch is switched
    {
        if(millis()-prev_time >= delay) // check to verify that the amount of time has passed
        {
            if(button_state == HIGH)  // we now have the desired switch state
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
        prev_time = millis();  // record the current time
    }

    return result;
    
}