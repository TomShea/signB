//Sign B basic functions

#include "FastLED.h"

#define CHIPSET           WS2812B
#define COLOR_ORDER       GRB

#define BRIGHTNESS        64

//The number of pixels in each section:
#define N_LEDS_WING_LEFT  266
#define N_LEDS_WING_RIGHT 266
#define N_LEDS_HEAD       45
#define N_LEDS_BODY_UPPER 275
#define N_LEDS_BODY_LOWER 145
#define N_LEDS_TAIL       30

#define MAX_STRIP_LENGTH  275
#define N_STRIPS          6

//The data pins
#define PIN_WING_LEFT     1
#define PIN_WING_RIGHT    2
#define PIN_HEAD          3
#define PIN_BODY_UPPER    4
#define PIN_BODY_LOWER    5
#define PIN_TAIL          6

//The order in which the strips are wired
#define INDEX_WING_LEFT   0
#define INDEX_WING_RIGHT  1
#define INDEX_HEAD        2
#define INDEX_BODY_UPPER  3
#define INDEX_BODY_LOWER  4
#define INDEX_TAIL        5

//The dimensions of the virtual pixelMap to be rendered
#define MAP_WIDTH         111
#define MAP_HEIGHT        25

//An integer to indicate a non-existent pixel
#define DNE               -1

/*
CRGB signWingLeft[N_LEDS_WING_LEFT];
CRGB signWingRight[N_LEDS_WING_RIGHT];
CRGB signHead[N_LEDS_HEAD];
CRGB signBodyUpper[N_LEDS_BODY_UPPER];
CRGB signBodyLower[N_LEDS_BODY_LOWER];
CRGB signTail[N_LEDS_TAIL];
*/

int16_t pixelMap[MAP_HEIGHT][MAP_WIDTH] = {
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},

  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},

  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},

  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},

  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,},
  {,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,,,,,  ,}
};

CRGB leds[N_STRIPS][MAX_STRIP_LENGTH];

uint16_t offsetWingLeft = N_LEDS_WING_LEFT;
uint16_t offsetWingRight = N_LEDS_WING_LEFT + N_LEDS_WING_RIGHT;
uint16_t offsetHead = N_LEDS_WING_LEFT + N_LEDS_WING_RIGHT + N_LEDS_HEAD;
uint16_t offsetBodyUpper = N_LEDS_WING_LEFT + N_LEDS_WING_RIGHT + N_LEDS_HEAD + N_LEDS_BODY_UPPER;
uint16_t offsetBodyLower = N_LEDS_WING_LEFT + N_LEDS_WING_RIGHT + N_LEDS_HEAD + N_LEDS_BODY_UPPER + N_LEDS_BODY_LOWER;


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
  return pixelMap[y][x];
}

/*
**  Use the following two functions together to get strip index and pixel index
**  E.G. leds[getStripFromPixelIndex(i)][getPixelIndexInStrip(i)]
*/

uint8_t getStripFromPixelIndex(uint16_t i) {
  if(i >= 0 && i < offsetWingLeft) {
    return INDEX_WING_LEFT;
  }
  if(i >= offsetWingLeft && i < offsetWingRight) {
    return INDEX_WING_RIGHT;
  }
  if(i >= offsetWingRight && i < offsetHead) {
    return INDEX_HEAD;
  }
  if(i >= offsetHead && i < offsetBodyUpper) {
    return INDEX_BODY_UPPER;
  }
  if(i >= offsetBodyUpper && i < offsetBodyLower) {
    return INDEX_BODY_LOWER;
  }
  if(i >= offsetBodyLower && i < offsetTail) {
    return INDEX_TAIL;
  }
}

uint16_t getPixelIndexInStrip(uint16_t i) {
  if(i >= 0 && i < offsetWingLeft) {
    return i;
  }
  if(i >= offsetWingLeft && i < offsetWingRight) {
    return i - offsetWingLeft;
  }
  if(i >= offsetWingRight && i < offsetHead) {
    return i - offsetWingRight;
  }
  if(i >= offsetHead && i < offsetBodyUpper) {
    return i - offsetHead;
  }
  if(i >= offsetBodyUpper && i < offsetBodyLower) {
    return i - offsetBodyUpper;
  }
  if(i >= offsetBodyLower && i < offsetTail) {
    return i - offsetBodyLower;
  }
}
