#ifndef PATTERN_H
#define	PATTERN_H

#include <xc.h>

/* Switch definitions (Active LOW) */
#define SWITCH1      0x0E
#define SWITCH2      0x0D
#define SWITCH3      0x0B
#define SWITCH4      0x07

#define EDGE   1
#define LEVEL  0

void init_digital_keypad(void);
unsigned char read_digital_keypad(unsigned char type);

void pattern1(void);
void pattern2(void);
void pattern3(unsigned char a);

#endif
