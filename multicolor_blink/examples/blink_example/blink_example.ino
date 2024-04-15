#include <multicolor_blink.h>

/*
this file is write by byteWire3d for easy acces to the build in rgb led, 
this library is not at all reseved for the nrf52840 but is what is coded it for.
*/


//The NRF52840 rgb led uses a not gate to drive the leds, so high = led_off and low = led_on


/*
All optional fuctions:
  Blink_Order();
  Millis_Blink();
  LED_ON();
  LED_OFF();
  ALL_MILLIS_Blink();
  Red_Green_Blue_Test();
  All_Colours_Blink();
  LED_Blink();
  DIM_LED(); // only accepts RGB

 Handy fuctions: 
  Blink_Order();
  Millis_Blink();
  LED_ON();
  LED_OFF();

 Test fuctions:
  ALL_MILLIS_Blink();
  Red_Green_Blue_Test();
  All_Colours_Blink();
  LED_Blink();
  DIM_LED();
*/


void setup() {
  Serial.begin(115200);
  pinMode(LED_RED, OUTPUT);    //red light output
  pinMode(LED_BLUE, OUTPUT);   // bluee light output
  pinMode(LED_GREEN, OUTPUT);  //green light output
}

void loop() {
  //ALL_MILLIS_Blink(7);
  String colors_blink_order[7] = { "WHITE", "RED", "YELLOW", "PURPLE", "RED", "BLUE", "GREEN" };
  Blink_Order(7, colors_blink_order);  // CLORORS MILLS BLINK
}
