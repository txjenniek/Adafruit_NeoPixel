#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 1

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed. 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  strip.begin();
  strip.show(); 
}

void loop() {
  
    // GIRLSTART INSTRUCTIONS:
    // Change the color by manipulating numbers inside "colorWipe" function
    // The lower the number, the less the LED is turned on
    // The higher the number, the more the LED is turned on
    
    // The first number controls the brightness of the RED 
    // The second number controls the brightness of the GREEN 
    // The third number controls the brightness of the BLUE 

    // The computer understands the format (#RED, #GREEN, #BLUE)
    
    // Example: (255, 0, 0) will make the NeoPixel very RED
    // Example: (0, 255, 0) will make the NeoPixel very GREEN
    // Question: (0, 0, 255) will make the NeoPixel what color??
    
    // Mix to see what colors appear! Can you make purple? White?

    colorWipe(strip.Color(255, 0, 0), 10); // First color
    colorWipe(strip.Color(0, 255, 0), 10); // Second color
    colorWipe(strip.Color(0, 0, 255), 10); // Third color

    /* GIRLSTART EXTRA CREDIT CHALLENGES!
     * How do you make it only flash 2 colors?  What about 4?
     * What does that last number (currently 10) do?
     * 
     * In case you want to start over, this will make it blink red:
     * colorWipe(strip.Color(255, 0, 0), 10);
     * (Copy/Paste it above)
     */
}

// GIRLSTART: DO NOT CHANGE BELOW HERE
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

