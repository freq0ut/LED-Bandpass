#include "Adafruit_NeoPixel.h"
#include "WS2812_Definitions.h"

#define PIN 4
#define LED_COUNT 60

Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

int StrobePin = 8;
int ResetPin = 7;
int ReadPin = A0;

float analogVal;

void setup()
{
  leds.begin();  // Call this to start up the LED strip.
  clearLEDs();   // This function, defined below, turns all LEDs off...
  leds.show();   // ...but the LEDs don't actually update until you call this.
  pinMode(StrobePin, OUTPUT);
  pinMode(ResetPin, OUTPUT);
  pinMode(ReadPin, INPUT);
  digitalWrite(StrobePin, LOW);
  digitalWrite(ResetPin, LOW);
  Reset(); //reset multiplexer 
}

void loop()
{
	int sensitivity = 200;
	StepStrobe();
	analogVal = map(analogRead(ReadPin), 60, 1023, sensitivity, 1);
	Bass(MAROON, analogVal);
	
	StepStrobe();
	analogVal = map(analogRead(ReadPin), 60, 1023, sensitivity, 1);
	Bass1(DARKRED, analogVal);
	
	StepStrobe();
	analogVal = map(analogRead(ReadPin), 60, 1023, sensitivity, 1);
	Midrange(SIENNA, analogVal);
	
	StepStrobe();
	analogVal = map(analogRead(ReadPin), 60, 1023, sensitivity, 1);
	Midrange1(OLIVE, analogVal);
	
	StepStrobe();
	analogVal = map(analogRead(ReadPin), 60, 1023, sensitivity, 1);
	Midrange2(LIME, analogVal);
	
	StepStrobe();
	analogVal = map(analogRead(ReadPin), 60, 1023, sensitivity, 1);
	Highs(MIDNIGHTBLUE, analogVal);
	
	StepStrobe();
	analogVal = map(analogRead(ReadPin), 60, 1023, sensitivity, 1);
	Highs1(INDIGO, analogVal);
}

void clearLEDs()
{
  for (int i=0; i<LED_COUNT; i++)
  {
    leds.setPixelColor(i, 0);
  }
}

void Bass(unsigned long color , byte brightness)
{
	int i = 0;
	
	byte red = (color & 0xFF0000) >> 16;
	byte green = (color & 0x00FF00) >> 8;
	byte blue = (color & 0x0000FF);
	
	while(i <= LED_COUNT)
	{
		leds.setPixelColor(i, red/(brightness), green/(brightness), blue/(brightness));
		i = i + 7;
	}
	
	leds.show();
}

void Bass1(unsigned long color , byte brightness)
{
	int i = 1;
	
	byte red = (color & 0xFF0000) >> 16;
	byte green = (color & 0x00FF00) >> 8;
	byte blue = (color & 0x0000FF);
	
	while(i <= LED_COUNT)
	{
		leds.setPixelColor(i, red/(brightness), green/(brightness), blue/(brightness));
		i = i + 7;
	}
	
	leds.show();
}

void Midrange(unsigned long color , byte brightness)
{
	int i = 2;
	
	byte red = (color & 0xFF0000) >> 16;
	byte green = (color & 0x00FF00) >> 8;
	byte blue = (color & 0x0000FF);
	
	while(i <= LED_COUNT)
	{
		leds.setPixelColor(i, red/(brightness), green/(brightness), blue/(brightness));
		i = i + 7;
	}
}

void Midrange1(unsigned long color , byte brightness)
{
	int i = 3;
	
	byte red = (color & 0xFF0000) >> 16;
	byte green = (color & 0x00FF00) >> 8;
	byte blue = (color & 0x0000FF);
	
	while(i <= LED_COUNT)
	{
		leds.setPixelColor(i, red/(brightness), green/(brightness), blue/(brightness));
		i = i + 7;
	}
}

void Midrange2(unsigned long color , byte brightness)
{
	int i = 4;
	
	byte red = (color & 0xFF0000) >> 16;
	byte green = (color & 0x00FF00) >> 8;
	byte blue = (color & 0x0000FF);
	
	while(i <= LED_COUNT)
	{
		leds.setPixelColor(i, red/(brightness), green/(brightness), blue/(brightness));
		i = i + 7;
	}
}

void Highs(unsigned long color , byte brightness)
{
	int i = 5;
	
	byte red = (color & 0xFF0000) >> 16;
	byte green = (color & 0x00FF00) >> 8;
	byte blue = (color & 0x0000FF);
	
	while(i <= LED_COUNT)
	{
		leds.setPixelColor(i, red/(brightness), green/(brightness), blue/(brightness));
		i = i + 7;
	}
}

void Highs1(unsigned long color , byte brightness)
{
	int i = 6;
	
	byte red = (color & 0xFF0000) >> 16;
	byte green = (color & 0x00FF00) >> 8;
	byte blue = (color & 0x0000FF);
	
	while(i <= LED_COUNT)
	{
		leds.setPixelColor(i, red/(brightness), green/(brightness), blue/(brightness));
		i = i + 7;
	}
}

void StepStrobe()
{
	digitalWrite(StrobePin, HIGH);
	digitalWrite(StrobePin, LOW);
	delayMicroseconds(30);
}

void Reset()
{
	digitalWrite(ResetPin, HIGH);
	digitalWrite(ResetPin, LOW);
	delayMicroseconds(30);
}