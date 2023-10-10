//Arduino project file for esp32 controlled taillights. 
//Features to be coded
//Running lamp, Reverse Lamps, Sound visualizer



#include <FastLED.h>
const int LED_PIN = 17;
const int brakePin = 5;
const int blinkerPin = 16;
const int NUM_LEDS = 40;
String LED_TYPE = "WS2812";
String COLOR_ORDER = "GRB";
float blinkCount;
int lightHue[NUM_LEDS];
int lightSaturation[NUM_LEDS];
int lightValue[NUM_LEDS];
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 500

   void setup() { 
       FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
       pinMode(5, INPUT);
       pinMode(16, INPUT);
       for (int i = 0; i < NUM_LEDS; i++){
        lightHue[i] = 0;
        lightSaturation[i] = 0;
        lightValue[i] = 0;
       }
   }


void loop() {
if(digitalRead(16) == HIGH){
    delay(60);
    blinkCount += 1;
    if(blinkCount > 9 || blinkCount == -1){
      blinkCount = 0;
    }

}
else if(digitalRead(16) == LOW){
  blinkCount == -1;
}



if(digitalRead(5) == HIGH){
  for(int i=0; i < NUM_LEDS; i++){
        lightHue[i] = 0;
        lightValue[i] = 191;
        lightSaturation[i] = 255;}}


if(digitalRead(16) == HIGH){
    for(int i=0; i < NUM_LEDS; i++){
      if(i%10 == blinkCount){
        lightHue[i] = 42;
        lightValue[i] = 255;
        lightSaturation[i] = 255;      
      }
}}




for(int i=0; i < NUM_LEDS; i++){
	leds[i] = CHSV( lightHue[i], lightSaturation[i], lightValue[i]);
}
     FastLED.show();

for(int i=0; i < NUM_LEDS; i++)
{ 
  if(lightValue[i] < 10 && lightValue[i] != 0){
  lightValue[i] = 0;
  }
  if(lightValue[i] > 0){
  
  lightValue[i] -= 16;
  }
  }


}


