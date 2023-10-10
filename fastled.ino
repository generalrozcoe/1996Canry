#include <FastLED.h>
#define LED_PIN     17
#define brakePin 5
#define bool runningLamp false
#define bool brake false
#define bool brakeBool false
#define NUM_LEDS    20
#define BRIGHTNESS  64
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

   void setup() { 
       FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
       pinMode(5, INPUT);
   }


    void loop() {       
      for(int dot = 0; dot < NUM_LEDS; dot++) { 
            leds[dot] = CRGB::Black;
            FastLED.setBrightness(0);
          
        }


        for(int dot = 0; dot < NUM_LEDS; dot++) { 
            leds[dot] = CRGB::Red;
            FastLED.setBrightness(12);
        }
      if(digitalRead(5) == HIGH){
        for(int dot = 0; dot < NUM_LEDS; dot++){
          leds[dot] = CRGB::Red;
          FastLED.setBrightness(128);


        }
        }
     FastLED.show();

    }