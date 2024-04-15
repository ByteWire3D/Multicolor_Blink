#include "multicolor_blink.h"

#define LED_MAX_DIM 255

unsigned long previousMillis = 0;
unsigned long currentMillis;
int led_state = LOW;
int count = 0;

void Blink_Order(int num_fuctions, String list_blink_order[]) {
  while (count <= num_fuctions) {
    String color = list_blink_order[count];
    Millis_Blink(color, 1000);
    if (count == num_fuctions) {
      count = 0;
    }
  }
}

// MILIS() blink:
void Millis_Blink(String color, int millis_blink_duration) {
  currentMillis = millis();
  if (currentMillis - previousMillis >= millis_blink_duration) {
    previousMillis = currentMillis;
    if (led_state == LOW) {
      LED_ON(color);
      //Serial.println("red led on");
      led_state = HIGH;
    } else {
      LED_OFF();
      //Serial.println("red led off");
      led_state = LOW;
      count += 1;
    }
  }
}



//singel fuction to turn color combinations on
void LED_ON(String color) {
  if (color == "RED") {
    RED_ON();
  }
  if (color == "GREEN") {
    GREEN_ON();
  }
  if (color == "BLUE") {
    BLUE_ON();
  }
  if (color == "YELLOW") {
    YELLOW_ON();
  }
  if (color == "PURPLE") {
    PURPLE_ON();
  }
  if (color == "BLUEGREEN") {
    BLUEGREEN_ON();
  }
  if (color == "WHITE") {
    WHITE_ON();
  }
}
// set led to low
void LED_OFF() {
  digitalWrite(LED_BLUE, HIGH);   // BLUE LOW
  digitalWrite(LED_GREEN, HIGH);  // GREEN LOW
  digitalWrite(LED_RED, HIGH);    // RED LOW
}

// test fuctions::
//TEST AL THE COLOURS;
void Red_Green_Blue_Test() {
  LED_Blink("RED", 1000);
  LED_Blink("GREEN", 1000);
  LED_Blink("BLUE", 1000);
}
void All_Colours_Blink() {
  LED_Blink("RED", 1000);
  LED_Blink("GREEN", 1000);
  LED_Blink("BLUE", 1000);
  LED_Blink("YELLOW", 1000);
  LED_Blink("PURPLE", 1000);
  LED_Blink("BLUEGREEN", 1000);
  LED_Blink("WHITE", 1000);
}
void ALL_MILLIS_Blink(int num_fuctions) {
  switch (count) {
    case 0:
      Millis_Blink("RED", 1000);
      Serial.println("Red");
      break;
    case 1:
      Millis_Blink("GREEN", 1000);
      Serial.println("green");
      break;
    case 2:
      Millis_Blink("BLUE", 1000);
      Serial.println("blue");
      break;
    case 3:
      Millis_Blink("YELLOW", 1000);
      Serial.println("yellow");
      break;
    case 4:
      Millis_Blink("PURPLE", 1000);
      Serial.println("purple");
      break;
    case 5:
      Millis_Blink("BLUEGREEN", 1000);
      Serial.println("bluegreen");
      break;
    case 6:
      Millis_Blink("WHITE", 1000);
      Serial.println("white");
      break;
  }
  if (count == num_fuctions) {
    count = 0;
  } else {
    //Serial.println(count);
  }
}
// singel fuction to blink in certain colors
void LED_Blink(String color, int Blink_duration) {
  LED_ON(color);
  delay(Blink_duration);
  LED_OFF();
  delay(Blink_duration);
}
// DIMM RGB
void DIM_LED(String color) {
  if (color == "RED") {
    for (int i = 0; i < (LED_MAX_DIM + 1); i++) {
      digitalWrite(LED_BLUE, HIGH);
      digitalWrite(LED_GREEN, HIGH);
      analogWrite(LED_RED, i);
      Serial.println(i);
      if (i >= LED_MAX_DIM) {
        i = 0;
        break;
      }
      delay(10);
    }
  }
  if (color == "GREEN") {
    for (int i = 0; i < (LED_MAX_DIM + 1); i++) {
      digitalWrite(LED_BLUE, HIGH);  // BLUE LOW
      digitalWrite(LED_RED, HIGH);   // RED LOW
      analogWrite(LED_GREEN, i);     // VARIABLE
      Serial.println(i);
      if (i >= LED_MAX_DIM) {
        i = 0;
        break;
      }
      delay(10);
    }
  }
  if (color == "BLUE") {
    for (int i = 0; i < (LED_MAX_DIM + 1); i++) {
      digitalWrite(LED_RED, HIGH);    // RED LOW
      digitalWrite(LED_GREEN, HIGH);  //GREEN LOW
      analogWrite(LED_BLUE, i);       // VARIABLE
      Serial.println(i);
      if (i >= LED_MAX_DIM) {
        i = 0;
        break;
      }
      delay(10);
    }
  }
}


//color combinations on
void RED_ON() {
  digitalWrite(LED_BLUE, HIGH);   //GREEN LOW
  digitalWrite(LED_GREEN, HIGH);  // GREEN LOW
  digitalWrite(LED_RED, LOW);     // RED HIGH
}
void GREEN_ON() {
  digitalWrite(LED_RED, HIGH);   // RED LOW
  digitalWrite(LED_BLUE, HIGH);  // RED LOW
  digitalWrite(LED_GREEN, LOW);  // GREEN HIGH
}
void BLUE_ON() {
  digitalWrite(LED_RED, HIGH);    // RED LOW
  digitalWrite(LED_GREEN, HIGH);  // GREEN LOW
  digitalWrite(LED_BLUE, LOW);    // BLUE HIGH
}
void YELLOW_ON() {
  digitalWrite(LED_RED, LOW);    // RED HIGH
  digitalWrite(LED_GREEN, LOW);  // GREEN HIGH
  digitalWrite(LED_BLUE, HIGH);  // BLUE LOW
}
void PURPLE_ON() {
  digitalWrite(LED_RED, LOW);     // RED HIGH
  digitalWrite(LED_GREEN, HIGH);  // GREEN LOW
  digitalWrite(LED_BLUE, LOW);    // BLUE HIGH
}
void BLUEGREEN_ON() {
  digitalWrite(LED_RED, HIGH);   // RED LOW
  digitalWrite(LED_GREEN, LOW);  // GREEN HIGH
  digitalWrite(LED_BLUE, LOW);   // BLUE HIGH
}
void WHITE_ON() {
  digitalWrite(LED_RED, LOW);    // RED HIGH
  digitalWrite(LED_GREEN, LOW);  // GREEN HIGH
  digitalWrite(LED_BLUE, LOW);   // BLUE HIGH
}
