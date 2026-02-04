#include <xc.h>
#include "pattern.h"

void init_config(void)
{
    TRISB = 0x00;     // PORTB as output
    PORTB = 0x00;
    init_digital_keypad();
}

void main(void)
{
    unsigned char key;
    unsigned char flag = 0;
    unsigned long int delay = 0;

    init_config();

    while (1)
    {
        key = read_digital_keypad(EDGE);

        if (key == SWITCH1)
            flag = 1;
        else if (key == SWITCH2)
            flag = 2;
        else if (key == SWITCH3)
            flag = 3;
        else if (key == SWITCH4)
            flag = 4;

        if (++delay >= 10000)
        {
            delay = 0;

            switch (flag)
            {
                case 1:
                    pattern1();
                    break;

                case 2:
                    pattern2();
                    break;

                case 3:
                    pattern3(0x55);
                    break;

                case 4:
                    pattern3(0x0F);
                    break;

                default:
                    PORTB = 0x00;
                    break;
            }
        }
    }
}
