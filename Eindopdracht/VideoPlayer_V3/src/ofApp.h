/*
 *  Be One With Music (aka. B1WM) V1
 *  Door Tiago Dos Santos Pedrosa IAD2
 *  06/12/15 - Edwin  van Ouwerkerk
 *
 *  Eindopdracht Openframeworks
 *  Benodigdheden
 *  Sensor: lichtsensor
 *  Actuatoren: 5 witte LEDS en 1 RGB LED
 *
 *
 *  Uitleg:
 *
 *  De code is een software voor grafische vormgeving project.
 *  In deze code wordt er een poster afgebeeld op het beeldscherm.
 *  Als de gebruiker de speaker (of iets dergelijks) voor de lichtsensor
 *  neerzet, dan wordt er gekeken hoe goed het object gepositioneerd is op
 *  de lichtsensor, de RGB LED geeft als feedback aan of je dat goed hebt gedaan.
 *  Rood = slecht, Blauw = bijna goed en groen = goed.
 *  Als het goed is (onder de 120), dan wordt de eerste geluid afgespeeld en
 *  de bijhorende plaatje wordt getoont op het beeldscherm.
 *  Verder gaat de bijhorende witte LED branden, dus geluid 1 heeft witte Led 1.
 *  De witte LEDS laten zien waar de gebruiker met zijn smartphone NFC reader de
 *  geluid kan downloaden die hij/zij te horen krijgt. De NFC functionaliteit wordt
 *  in deze code niet geprogrammeerd. Het valt buiten de openframeworks opdracht.
 *
 *  Tutorials/guides:
 *  http://forum.openframeworks.cc/t/windows-7-quicktime-error-loading-videos/2882/2
 *  http://www.slideshare.net/roxlu/openframeworks-007-video
 */

#pragma once

#include "ofMain.h"
#include "ofEvents.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofImage image[5];
		ofImage uiTop, uiDown, uiInfo;
		ofSoundPlayer sound[5];
		bool soundPaused[5];
		bool soundPlaying[5];
		bool playCheck, songCheck;
		int lightValue;
		int width,height;

        ofArduino	arduino;
        bool	isArduinoInitialized;
        void setupArduino(const int & version);
        void analogPinChanged(const int & pinNum);

};
