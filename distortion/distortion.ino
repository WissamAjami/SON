#include <Audio.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "MyDsp.h"
// GUItool: begin automatically generated codeyd
MyDsp myDsp;
AudioInputI2S            i2s1;           //xy=141,1579
AudioMixer4              mixer1;         //xy=367,1593
AudioOutputI2S           i2s2;           //xy=587,1551
AudioAnalyzeFFT1024      fft1024_1;      //xy=705,290
AudioConnection          patchCord1(i2s1, 0, mixer1, 0);
AudioConnection          patchCord2(i2s1, 1, mixer1, 1);

AudioConnection          patchCord3(mixer1, fft1024_1);
AudioConnection          patchCord4(mixer1, 0, i2s2, 0);
AudioConnection          patchCord5(mixer1, 0, i2s2, 1);
AudioControlSGTL5000     audioShield;
float gains []= {0,0,0};

// GUItool: end automatically generated code

// GUItool: end automatically generated code

// Advanced Microcontroller-based Audio Workshop
//
// http://www.pjrc.com/store/audio_tutorial_kit.html
// https://hackaday.io/project/8292-microcontroller-audio-workshop-had-supercon-2015
// 
// Part 3-2: Fourier Transform


void setup() {
  Serial.begin(9600);
  AudioMemory(10);
  audioShield.enable();
  audioShield.volume(0.5);
  audioShield.inputSelect(AUDIO_INPUT_MIC);
  audioShield.micGain(10);
  //pinMode(0, INPUT_PULLUP);
 
  mixer1.gain(0, 0.5);
  mixer1.gain(1,0.5);
  mixer1.gain(2, 0.0);
  mixer1.gain(3, 0.0);
  // Uncomment one these to try other window functions
  //fft1024_1.windowFunction(NULL);
  // fft1024_1.windowFunction(AudioWindowBartlett1024);
  // fft1024_1.windowFunction(AudioWindowFlattop1024);
  delay(1000);
  
}

void loop() {
  // print Fourier Transform data to the Arduino Serial Monitor
  if (fft1024_1.available()) {
    Serial.print("FFT: ");
    for (int i=0; i<30; i++) {  // 0-25  -->  DC to 1.25 kHz
      float n = fft1024_1.read(i);
      verifyGain(n);
      srtgain
      printNumber(n);
    }
    Serial.println();
  }
  
  
  
 

}


void printNumber(float n) {
  
  if (n >= 0.001) {
    //alors on applique un filtre
    //trouver une relation entre n et le gain appliqué auy filtre
    //noise.filtre(gain, frequence, qualité)
    // il faut superposer tous les noise filtrés
    
    Serial.print(n, 3);
    Serial.print(" ");
  } else {
    //on esquive la fréquence adieu 
    Serial.print("   -  "); // don't print "0.00"
  }
  
  /*
  if (n > 0.25) {
    Serial.print("***** ");
  } else if (n > 0.18) {
    Serial.print(" ***  ");
  } else if (n > 0.06) {
    Serial.print("  *   ");
  } else if (n > 0.005) {
    Serial.print("  .   ");
  }
  */
}
