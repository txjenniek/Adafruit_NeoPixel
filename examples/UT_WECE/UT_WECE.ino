#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 1

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
Adafruit_NeoPixel strip = Adafruit_NeoPixel(2, PIN, NEO_GRB + NEO_KHZ800);

// Initialize the pixels
void setup() {
  strip.begin();
  strip.show(); 
}

// UT WECE The main loop
// 2 demo programs have been created for you, CUSTOM and RAINBOW
// Comment/Uncomment function calls to choose accordingly and add as you please
void loop() {
    
    // CUSTOM program: Choose your own colors and period
    // strip.Color takes 3 parameters - (Red, Green, Blue) values for LEDs
    // Red/Green/Blue LED values can be between 0-255, where 0 is OFF and 255 is max power
    
    // colorWipe takes 2 parameters, the first is the return value of strip.Color
    // the second is the wait in milliseconds
    
    colorWipe(strip.Color(255, 0, 0), 200); // First color
    colorWipe(strip.Color(0, 255, 0), 200); // Second color
    colorWipe(strip.Color(0, 0, 255), 200); // Third color
    
    // RAINBOW program LED 
    // rainbow function cycles through all combinations of RGB values at the given period
    // The only parameter rainbow takes is a wait in milliseconds
    
    //rainbow(50);
}


// WECE NeoPixel Functions - change below here at your own risk
void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) % 255));
    }
    strip.show();
    delay(wait);
  }
}

// Wheel over pins 
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
