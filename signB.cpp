//Sign B Config

#include "FastLED.h"

#define CHIPSET     WS2812B
#define COLOR_ORDER GRB

#define BRIGHTNESS  64

#define N_LEDS_WING_LEFT  266
#define N_LEDS_WING_RIGHT 266
#define N_LEDS_HEAD       45
#define N_LEDS_BODY_UPPER 275
#define N_LEDS_BODY_LOWER 145
#define N_LEDS_TAIL       30

#define MAX_STRIP_LENGTH  275
#define N_STRIPS          6

#define PIN_WING_LEFT   1
#define PIN_WING_RIGHT  2
#define PIN_HEAD        3
#define PIN_BODY_UPPER  4
#define PIN_BODY_LOWER  5
#define PIN_TAIL        6

#define INDEX_WING_LEFT  0
#define INDEX_WING_RIGHT 1
#define INDEX_HEAD       2
#define INDEX_BODY_UPPER 3
#define INDEX_BODY_LOWER 4
#define INDEX_TAIL       5

/*
CRGB signWingLeft[N_LEDS_WING_LEFT];
CRGB signWingRight[N_LEDS_WING_RIGHT];
CRGB signHead[N_LEDS_HEAD];
CRGB signBodyUpper[N_LEDS_BODY_UPPER];
CRGB signBodyLower[N_LEDS_BODY_LOWER];
CRGB signTail[N_LEDS_TAIL];
*/

CRGB leds[N_STRIPS][MAX_STRIP_LENGTH]

void setup() {
  /*
  FastLED.addLeds<CHIPSET, PIN_WING_LEFT,   COLOR_ORDER>(signWingLeft,  N_LEDS_WING_LEFT);
  FastLED.addLeds<CHIPSET, PIN_WING_RIGHT,  COLOR_ORDER>(signWingRight, N_LEDS_WING_RIGHT);
  FastLED.addLeds<CHIPSET, PIN_HEAD,        COLOR_ORDER>(signHead,      N_LEDS_HEAD);
  FastLED.addLeds<CHIPSET, PIN_BODY_UPPER,  COLOR_ORDER>(signBodyUpper, N_LEDS_BODY_UPPER);
  FastLED.addLeds<CHIPSET, PIN_BODY_LOWER,  COLOR_ORDER>(signBodyLower, N_LEDS_BODY_LOWER);
  FastLED.addLeds<CHIPSET, PIN_TAIL,        COLOR_ORDER>(signTail,      N_LEDS_TAIL);
  */

  FastLED.addLeds<CHIPSET, PIN_WING_LEFT,   COLOR_ORDER>(leds[INDEX_WING_LEFT],  N_LEDS_WING_LEFT);
  FastLED.addLeds<CHIPSET, PIN_WING_RIGHT,  COLOR_ORDER>(leds[INDEX_WING_RIGHT], N_LEDS_WING_RIGHT);
  FastLED.addLeds<CHIPSET, PIN_HEAD,        COLOR_ORDER>(leds[INDEX_HEAD],       N_LEDS_HEAD);
  FastLED.addLeds<CHIPSET, PIN_BODY_UPPER,  COLOR_ORDER>(leds[INDEX_BODY_UPPER], N_LEDS_BODY_UPPER);
  FastLED.addLeds<CHIPSET, PIN_BODY_LOWER,  COLOR_ORDER>(leds[INDEX_BODY_LOWER], N_LEDS_BODY_LOWER);
  FastLED.addLeds<CHIPSET, PIN_TAIL,        COLOR_ORDER>(leds[INDEX_TAIL],       N_LEDS_TAIL);
}

void loop() {

}

int XY(int x, int y) {
  if(y > HEIGHT) {
    y = HEIGHT;
  }
  if(y < 0) {
    y = 0;
  }
  if(x > WIDTH) {
    x = WIDTH;
  }
  if(x < 0) {
    x = 0;
  }
  // for a serpentine layout reverse every 2nd row:
  if(x % 2 == 1) {
    return (x * (WIDTH) + (HEIGHT - y -1));
  }
  else {
    // use that line only, if you have all rows beginning at the same side
    return (x * (WIDTH) + y);
  }
}

uint8_t getStripFromPixelIndex(uint16_t i) {
  if(i >= 0 && i < N_LEDS_WING_LEFT) {
    return INDEX_WING_LEFT;
  }
  if(i >= N_LEDS_WING_LEFT && i < N_LEDS_WING_LEFT + N_LEDS_WING_RIGHT) {
    return INDEX_WING_RIGHT;
  }
  if(i >= N_LEDS_WING_LEFT + N_LEDS_WING_RIGHT && i < N_LEDS_WING_LEFT + N_LEDS_WING_RIGHT + N_LEDS_HEAD) {
    return INDEX_HEAD;
  }
  if(i >= N_LEDS_WING_LEFT + N_LEDS_WING_RIGHT + N_LEDS_HEAD && i < N_LEDS_WING_LEFT + N_LEDS_WING_RIGHT + N_LEDS_HEAD) {
    return INDEX_HEAD;
  }
}
