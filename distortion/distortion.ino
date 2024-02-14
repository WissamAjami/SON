#include <Audio.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "MyDsp.h"

// Local
MyDsp myDsp;
AudioControlSGTL5000     audioShield;

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=135,1923
AudioSynthNoiseWhite     noise1;         //xy=167,1441
AudioMixer4              mixer1;         //xy=361,1937
AudioFilterBiquad        biquad6; //xy=566,1684
AudioAnalyzeFFT256       fft1024_1;       //xy=572,1949
AudioFilterBiquad        biquad7; //xy=582,1634
AudioFilterBiquad        biquad1;        //xy=586,1403
AudioFilterBiquad        biquad2;        //xy=602,1353
AudioFilterBiquad        biquad10; //xy=605,1458
AudioFilterBiquad        biquad8; //xy=605,1572
AudioFilterBiquad        biquad9; //xy=614,1514
AudioFilterBiquad        biquad5;        //xy=625,1177
AudioFilterBiquad        biquad3;        //xy=625,1291
AudioFilterBiquad        biquad4;        //xy=634,1233
AudioMixer4              mixer4; //xy=857,1443
AudioMixer4              mixer5; //xy=862,1643
AudioMixer4              mixer2; //xy=921,1299
AudioMixer4              mixer3; //xy=1089,1466
AudioOutputI2S           i2s2;           //xy=1336,1484
AudioConnection          patchCord1(i2s1, 0, mixer1, 0);
AudioConnection          patchCord2(i2s1, 1, mixer1, 1);
AudioConnection          patchCord3(noise1, biquad5);
AudioConnection          patchCord4(noise1, biquad4);
AudioConnection          patchCord5(noise1, biquad3);
AudioConnection          patchCord6(noise1, biquad2);
AudioConnection          patchCord7(noise1, biquad1);
AudioConnection          patchCord8(noise1, biquad10);
AudioConnection          patchCord9(noise1, biquad9);
AudioConnection          patchCord10(noise1, biquad8);
AudioConnection          patchCord11(noise1, biquad6);
AudioConnection          patchCord12(noise1, biquad7);
AudioConnection          patchCord13(mixer1, fft1024_1);
AudioConnection          patchCord14(biquad6, 0, mixer5, 2);
AudioConnection          patchCord15(biquad7, 0, mixer5, 0);
AudioConnection          patchCord16(biquad1, 0, mixer4, 0);
AudioConnection          patchCord17(biquad2, 0, mixer2, 3);
AudioConnection          patchCord18(biquad10, 0, mixer4, 1);
AudioConnection          patchCord19(biquad8, 0, mixer4, 3);
AudioConnection          patchCord20(biquad9, 0, mixer4, 2);
AudioConnection          patchCord21(biquad5, 0, mixer2, 0);
AudioConnection          patchCord22(biquad3, 0, mixer2, 2);
AudioConnection          patchCord23(biquad4, 0, mixer2, 1);
AudioConnection          patchCord24(mixer4, 0, mixer3, 1);
AudioConnection          patchCord25(mixer5, 0, mixer3, 3);
AudioConnection          patchCord26(mixer2, 0, mixer3, 2);
AudioConnection          patchCord27(mixer3, 0, i2s2, 0);
AudioConnection          patchCord28(mixer3, 0, i2s2, 1);

AudioFilterBiquad filtres [] = {biquad1, biquad2, biquad3, biquad4, biquad5, biquad6, biquad7, biquad8, biquad9, biquad10};
float gains [] = {1,1,0,0,0,0,0,0,0,0};  //
AudioMixer4 listMixer [] = {mixer1,mixer2,mixer3,mixer4,mixer5};
// Advanced Microcontroller-based Audio Workshop
//
// http://www.pjrc.com/store/audio_tutorial_kit.html
// https://hackaday.io/project/8292-microcontroller-audio-workshop-had-supercon-2015
// 
// Part 3-2: Fourier Transform


void setup() {
  Serial.begin(9600);
  AudioMemory(10);
  noise1.amplitude(1);
  
  audioShield.enable();
  audioShield.volume(0.5);
  audioShield.inputSelect(AUDIO_INPUT_MIC);
  audioShield.micGain(10);
  //pinMode(0, INPUT_PULLUP);
 
  mixer1.gain(0, 0.5);
  mixer1.gain(1,0.5);
  mixer1.gain(2, 0.0);
  mixer1.gain(3, 0.0);
  for (int i = 2;i<5;i++){
    listMixer[i].gain(0,0.5);
    listMixer[i].gain(1,0.5);
    listMixer[i].gain(2,0.5);
    listMixer[i].gain(3,0.5);
  }
  // Uncomment one these to try other window functions
  //fft1024_1.windowFunction(NULL);
  // fft1024_1.windowFunction(AudioWindowBartlett1024);
  // fft1024_1.windowFunction(AudioWindowFlattop1024);
  delay(1000);
  
}

void loop() {
  // print Fourier Transform data to the Arduino Serial Monitor
  Serial.println("fhekuhek");
  if (fft1024_1.available()) {
    Serial.print("FFT: ");
    for (int i=0; i<30; i++) {  // 0-25  -->  DC to 1.25 kHz
      float n = fft1024_1.read(i);
      setGain(i,n);
    }
    Serial.println();
    }
 

}


void setGain(int i, float n) {
  
  if (n >= 0.001) {
    //alors on applique un filtre
    //trouver une relation entre n et le gain appliqué auy filtre
    //noise.filtre(gain, frequence, qualité)
    // il faut superposer tous les noise filtrés
    
    Serial.print(n, 3);
    Serial.print(" ");
    gains[i] = n *3;
  } else {
    //on esquive la fréquence adieu 
    gains[i] = 0;
    Serial.print("   -  "); // don't print "0.00"
  }
  filtres[i].setBandpass(gains[i], i*25/2, 5);
  
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
