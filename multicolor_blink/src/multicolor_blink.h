#ifndef MULTICOLOR_BLINK_H
#define MULTICOLOR_BLINK_H

#include <Arduino.h>

void Blink_Order(int num_fuctions, String list_blink_order[]);
void Millis_Blink(String color, int millis_blink_duration);

void LED_ON(String color);
void LED_OFF();

void Red_Green_Blue_Test();
void All_Colours_Blink();
void ALL_MILLIS_Blink(int num_fuctions);
void LED_Blink(String color, int Blink_duration);
void DIM_LED(String color);


void RED_ON();
void GREEN_ON();
void BLUE_ON();
void YELLOW_ON();
void PURPLE_ON();
void BLUEGREEN_ON();
void WHITE_ON();

#endif