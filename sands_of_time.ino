#include "SPI.h"
#include "Adafruit_WS2801.h"
#include "sand_grain.h"


/* VARIABLES */

uint8_t dataPin  = 2;
uint8_t clockPin = 3;

uint32_t led_off   = 0;

uint8_t number_of_pixels = 25;
Adafruit_WS2801 strip = Adafruit_WS2801(number_of_pixels, dataPin, clockPin);

SandGrain* grain = new SandGrain();
SandGrain* grain2 = new SandGrain();


/* SETUP */

void setup() {
  strip.begin();
  strip.show();

  grain->pick_color();
  grain->position = 0;

  grain2->pick_color();
  grain2->position = 0;
}



/* MAIN LOOP */

void loop() {
  clear_leds();

  grain->position++;
  grain->position %= number_of_pixels;

  if(grain->position == 0) {
    grain->pick_color();
  }

  // do this in HourGlass controller to render hour glass view
  strip.setPixelColor(grain->position, grain->color);
  strip.show();
  delay(30);
}



// put in hour glass view
void clear_leds() {
  for(uint8_t i = 0; i < number_of_pixels; i++) {
    strip.setPixelColor(i, led_off);
  }
}
