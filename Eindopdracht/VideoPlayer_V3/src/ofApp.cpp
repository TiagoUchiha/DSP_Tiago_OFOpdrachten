/*
 *  Be One With Music (aka. B1WM) V1
 *  Door Tiago Dos Santos Pedrosa IAD2
 *  06/12/15 - Edwin van Ouwerkerk
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

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // Load 5 images with the name: image00(i+1) on an ofImage array[5]
    for (int i=0; i < 5; i++){
        string name = "image00" + ofToString(i+1) + ".jpg";
        image[i].loadImage(name);
    }

    // Load 5 tracks with the name: track00(i+1) on an ofSoundPlayer array[5]
    // and set the volume, play the song but pauze it.
    for (int i=0; i < 5; i++){
        soundPaused[i] = true;
        string name2 = "track00" + ofToString(i+1) + ".mp3";
        sound[i].loadSound(name2);
        sound[i].setVolume(1);
        sound[i].play();
        sound[i].setPaused(soundPaused[i]);
    }

    // Set the general volume
    ofSoundSetVolume(0.2);

    // Load the poster front images
    uiTop.loadImage("front.gif");
    uiDown.loadImage("down.gif");
    uiInfo.loadImage("info.gif");

    // "Define" constants
    width = ofGetWidth();
    height = ofGetHeight();

    // Connect with the arduino
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    isArduinoInitialized = false;

    arduino.connect("COM4",57600);
    arduino.sendFirmwareVersionRequest();
}

//--------------------------------------------------------------
void ofApp::setupArduino(const int& version){
    // Remove listener because we don't need it anymore
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
    // set flag: Arduino now ready for use
    isArduinoInitialized = true;

    // Set pin 3-7 as output (White LEDS showing which NFC you can use)
    arduino.sendDigitalPinMode(7, ARD_OUTPUT);
    arduino.sendDigitalPinMode(6, ARD_OUTPUT);
    arduino.sendDigitalPinMode(5, ARD_OUTPUT);
    arduino.sendDigitalPinMode(4, ARD_OUTPUT);
    arduino.sendDigitalPinMode(3, ARD_OUTPUT);

    // Set pin 9-11  as output (RGB LED which notifies if the speaker is in the right place)
    arduino.sendDigitalPinMode(9, ARD_OUTPUT);
    arduino.sendDigitalPinMode(10, ARD_OUTPUT);
    arduino.sendDigitalPinMode(11, ARD_OUTPUT);

    // Set pin A0 as analog input (Light sensor that notifies if the speaker is placed or not)
    arduino.sendAnalogPinReporting(0,ARD_ANALOG);

    // Set listeners for pin events
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);

}

//--------------------------------------------------------------
void ofApp::update(){
    // Update the poster images and the general sound
    uiTop.update();
    uiDown.update();
    uiInfo.update();
    ofSoundUpdate();
    arduino.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    // Draw the images (selfies) with no transparancy

    /* If speaker is on the right place then show image[i].
     * Check if the lightvalue is right and sound [i] is playing first, if that is true
     * then show image [i] aswell.
     */

    ofEnableAlphaBlending();
    ofSetColor(255,255,255,255);

    if(playCheck == true && sound[0].getIsPlaying() == true){
        image[0].resize(width,height);
        image[0].draw(0,0);
    }
    else if(playCheck == true && sound[1].getIsPlaying() == true){
        image[1].draw(0,0);
    }
    else if(playCheck == true && sound[2].getIsPlaying() == true){
        image[2].draw(0,0);
    }
    else if(playCheck == true && sound[3].getIsPlaying() == true){
        image[3].draw(0,0);
    }
    else if(playCheck == true && sound[4].getIsPlaying() == true){
        image[4].resize(width,height);
        image[4].draw(0,0);
    }
    else {
        //done drawing
    }
    ofDisableAlphaBlending;

    // Draw the User interface images with transparency
    ofEnableAlphaBlending();
    ofSetColor(255,255,255,127);
    uiTop.draw(0,0);
    uiDown.draw(0, height-300);
    ofSetColor(255,255,255,255);
    uiInfo.draw(width-530, height-305);
    ofDisableAlphaBlending;
}

void ofApp::analogPinChanged(const int& pinNum)
{
    //Get the light value with arduino.getAnalog(pinNum));
    //And show the value on LOG
    lightValue = arduino.getAnalog(pinNum);
    ofLog(OF_LOG_NOTICE,"Lightsensor works: "+ ofToString(lightValue));


    /* If the value < 100 (speaker is in the right place)
     * then set the RGB color to green (pin 10)
     * else if the value > 100 but smakker than 400
     * (speaker is on top of the right place, but not there yet)
     * then set RGB color to blue (pin 9)
     * else the speaker isn't in the right place
     * set RGB color to red (pin 11);
     */

    if (lightValue < 120)
    {
        arduino.sendDigital(10, ARD_HIGH);
        arduino.sendDigital(11, ARD_LOW);
        arduino.sendDigital(9, ARD_LOW);
        playCheck = true;
    }
    else if (lightValue < 400 && lightValue > 120)
    {
        arduino.sendDigital(10, ARD_LOW);
        arduino.sendDigital(11, ARD_LOW);
        arduino.sendDigital(9, ARD_HIGH);
        playCheck = false;
        for(int i =0; i < 5; i++){
            soundPaused[i] = true;
            sound[i].setPaused(soundPaused[i]);
        }
    }
    else
    {
        arduino.sendDigital(10, ARD_LOW);
        arduino.sendDigital(11, ARD_HIGH);
        arduino.sendDigital(9, ARD_LOW);
        playCheck = false;
        for(int i =0; i < 5; i++){
            soundPaused[i] = true;
            sound[i].setPaused(soundPaused[i]);
        }
    }

    /* If lightvalue < 100 (speaker is on the right place)
     * then start playing the songs.
     * Check if there is a sound playing and put in an array of booleans.
     * Then check the array from end to start if there is a song playing.
     * If no sound is playing, then start playing the first one.
     * If the first one is playing and stopped playing, then go to the second one, etc..
     */

    if (playCheck == true){

        for(int i=0; i<5;i++){
            soundPlaying[i] = sound[i].getIsPlaying();
        }

        if(soundPlaying[3] == false){
            soundPaused[4] = false;
            sound[4].setPaused(soundPaused[4]);
            ofLogNotice() << "Playing sound 4" << endl;
        }
        else if(soundPlaying[2] == false){
            soundPaused[3] = false;
            sound[3].setPaused(soundPaused[3]);
            ofLogNotice() << "Playing sound 3" << endl;
        }
        else if(soundPlaying[1] == false){
            soundPaused[2] = false;
            sound[2].setPaused(soundPaused[2]);
            ofLogNotice() << "Playing sound 2" << endl;
        }
        else if(soundPlaying[0] == false){
            soundPaused[1] = false;
            sound[1].setPaused(soundPaused[1]);
            ofLogNotice() << "Playing sound 1" << endl;
        }
        else {
            soundPaused[0] = false;
            sound[0].setPaused(soundPaused[0]);
            ofLogNotice() << "Playing sound 0" << endl;
        }
    }


    /* Pin 3 = sound 1   Pin 4 = sound 2
     * Pin 5 = sound 3   Pin 6 = sound 4
     * Pin 7 = sound 5
     * If the sound[i] is playing then
     * set the according LED on and the others off.
     */

    if (sound[0].getIsPlaying() == true){
         arduino.sendDigital(3, ARD_HIGH);
         arduino.sendDigital(7, ARD_LOW);
         arduino.sendDigital(6, ARD_LOW);
         arduino.sendDigital(5, ARD_LOW);
         arduino.sendDigital(4, ARD_LOW);
    }
    else if (sound[1].getIsPlaying() == true){
         arduino.sendDigital(4, ARD_HIGH);
         arduino.sendDigital(7, ARD_LOW);
         arduino.sendDigital(6, ARD_LOW);
         arduino.sendDigital(5, ARD_LOW);
         arduino.sendDigital(3, ARD_LOW);
    }
    else if (sound[2].getIsPlaying() == true){
         arduino.sendDigital(5, ARD_HIGH);
         arduino.sendDigital(7, ARD_LOW);
         arduino.sendDigital(6, ARD_LOW);
         arduino.sendDigital(3, ARD_LOW);
         arduino.sendDigital(4, ARD_LOW);
    }
    else if (sound[3].getIsPlaying() == true){
         arduino.sendDigital(6, ARD_HIGH);
         arduino.sendDigital(7, ARD_LOW);
         arduino.sendDigital(3, ARD_LOW);
         arduino.sendDigital(5, ARD_LOW);
         arduino.sendDigital(4, ARD_LOW);
    }
    else if (sound[4].getIsPlaying() == true){
         arduino.sendDigital(7, ARD_HIGH);
         arduino.sendDigital(3, ARD_LOW);
         arduino.sendDigital(6, ARD_LOW);
         arduino.sendDigital(5, ARD_LOW);
         arduino.sendDigital(4, ARD_LOW);
    }
    else{
         arduino.sendDigital(3, ARD_LOW);
         arduino.sendDigital(7, ARD_LOW);
         arduino.sendDigital(6, ARD_LOW);
         arduino.sendDigital(5, ARD_LOW);
         arduino.sendDigital(4, ARD_LOW);
    }

}
