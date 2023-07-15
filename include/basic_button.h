#ifndef _BASIC_BUTTON_H
#define _BASIC_BUTTON_H 

    class MyButton
    {
        private:
            int button_pin;
            int prev_state;
            int button_state;
            unsigned long prev_time;
        
        public:
            MyButton(int pin);
            int debounce(unsigned long delay);
        

    };
#endif