#include <Audio.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "MyDsp.h"

// GUItool: begin automatically generated codeyd
MyDsp myDsp;
AudioControlSGTL5000     audioShield;



// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise1;         //xy=259,551
AudioInputI2S            i2s1;           //xy=274,298
AudioFilterBiquad        biquad1;        //xy=509,465
AudioFilterBiquad        biquad2;        //xy=515,561
AudioFilterBiquad        biquad3;        //xy=519,651
AudioMixer4              mixer1;         //xy=565,291
AudioAnalyzeFFT1024      fft1024_1;      //xy=806,252
AudioMixer4              mixer2;         //xy=806,553
AudioOutputI2S           i2s2;           //xy=1119,554
AudioConnection          patchCord1(noise1, biquad1);
AudioConnection          patchCord2(noise1, biquad2);
AudioConnection          patchCord3(noise1, biquad3);
AudioConnection          patchCord4(i2s1, 0, mixer1, 0);
AudioConnection          patchCord5(i2s1, 1, mixer1, 1);
AudioConnection          patchCord6(biquad1, 0, mixer2, 0);
AudioConnection          patchCord7(biquad2, 0, mixer2, 1);
AudioConnection          patchCord8(biquad3, 0, mixer2, 2);
AudioConnection          patchCord9(mixer1, fft1024_1);
AudioConnection          patchCord10(mixer2, 0, i2s2, 0);
AudioConnection          patchCord11(mixer2, 0, i2s2, 1);
// GUItool: end automatically generated code


float gains []= {3,3,3};
// http://www.pjrc.com/store/audio_tutorial_kit.html
// https://hackaday.io/project/8292-microcontroller-audio-workshop-had-supercon-2015
// 
// Part 3-2: Fourier Transform


void setup() {
  Serial.begin(9600);
  AudioMemory(10);
  audioShield.enable();
  audioShield.volume(0.5);
  noise1.amplitude(1);
  //noise1.begin(1.0, 440, WAVEFORM_SINE);
  audioShield.inputSelect(AUDIO_INPUT_MIC);
  audioShield.micGain(15);
  //pinMode(0, INPUT_PULLUP);

  mixer1.gain(0, 0.5);
  mixer1.gain(1,0.5);
  mixer1.gain(2, 0.0);
  mixer1.gain(3, 0.0);
  mixer2.gain(0, 0.5);
  mixer2.gain(1,0.5);
  mixer2.gain(2, 0.5);
  mixer1.gain(3, 0.0);
  biquad1.setBandpass(0, 12.5, 5);
  biquad2.setBandpass(0, 37.5, 5);
  biquad3.setBandpass(0, 62.5, 5);
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
    for (int i=0; i<3; i++) {  // 0-25  -->  DC to 1.25 kHz
      float n = fft1024_1.read(i);
      
      setGain(n,i);
    }
    Serial.print("gain:");
    Serial.println(gains[0]);
    mixer2.gain(0, gains[0]);
    mixer2.gain(1, gains[1]);
    mixer2.gain(2, gains[2]);
    Serial.println();
    
  }





}


void setGain(float n, int i) {

  if (n >= 0.005) {
    //alors on applique un filtre
    //trouver une relation entre n et le gain appliqué auy filtre
    //noise.filtre(gain, frequence, qualité)
    // il faut superposer tous les noise filtrés
    gains[i]= n;
    Serial.print(n, 3);
    Serial.print(" ");
    
  } else {
    //on esquive la fréquence adieu 
    gains[i] = 0;
    Serial.print("   -  "); // don't print "0.00"
  }
  


  
  /*for (int j=0;;j++){
    
  }*/
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
