#include <xc.h>
#include "pattern.h"

static unsigned char i = 0;

/* Keypad initialization */
void init_digital_keypad(void)
{
    TRISC |= 0x0F;      // RC0?RC3 as input
}

/* Digital keypad read */
unsigned char read_digital_keypad(unsigned char type)
{
    static unsigned char flag = 0;
    unsigned char key = PORTC & 0x0F;

    if (type == EDGE)
    {
        if ((key != 0x0F) && (flag == 0))
        {
            flag = 1;
            return key;
        }
        else if (key == 0x0F)
        {
            flag = 0;
        }
    }
    else    // LEVEL
    {
        return key;
    }
    return 0x0F;
}

/* Pattern 1: Shift left, clear, shift right, clear */
void pattern1(void)
{
    if (i < 8)
    {
        PORTB = (PORTB << 1) | 0x01;
    }
    else if (i < 16)
    {
        PORTB <<= 1;
    }
    else if (i < 24)
    {
        PORTB = (PORTB >> 1) | 0x80;
    }
    else if (i < 32)
    {
        PORTB >>= 1;
    }
    else
    {
        i = 0;
        PORTB = 0x00;
    }
    i++;
}

/* Pattern 2: Left fill and clear */
void pattern2(void)
{
    if (i < 8)
    {
        PORTB = (PORTB << 1) | 0x01;
    }
    else if (i < 16)
    {
        PORTB <<= 1;
    }
    else
    {
        i = 0;
        PORTB = 0x00;
    }
    i++;
}

/* Pattern 3: Toggle given pattern */
void pattern3(unsigned char a)
{
    static unsigned char state = 0;

    if (state)
        PORTB = a;
    else
        PORTB = ~a;

    state ^= 1;
}
