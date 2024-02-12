#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code

AudioControlSGTL5000 audioShield;
AudioSynthWaveform       waveform1;      //xy=274,192
AudioMixer4              mixer1;         //xy=556,177
AudioOutputI2S           i2s1;           //xy=696,81
AudioAnalyzeFFT1024      fft1024_1;      //xy=705,290
AudioConnection          patchCord1(waveform1, 0, mixer1, 0);
AudioConnection          patchCord2(mixer1, 0, i2s1, 0);
AudioConnection          patchCord3(mixer1, 0, i2s1, 1);
AudioConnection          patchCord4(mixer1, fft1024_1);
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
  
  //pinMode(0, INPUT_PULLUP);
 
  mixer1.gain(0, 0.5);
  mixer1.gain(1,0.5);
  mixer1.gain(2, 0.0);
  mixer1.gain(3, 0.0);
  // Uncomment one these to try other window functions
  fft1024_1.windowFunction(NULL);
  // fft1024_1.windowFunction(AudioWindowBartlett1024);
  // fft1024_1.windowFunction(AudioWindowFlattop1024);
  delay(1000);
}


int noteNumber = 0;
const float noteFrequency[12] = {
  220.00,  // A3
  233.08,  // A#3
  246.94,  // B3
  261.63,  // C4
  277.18,  // C#4
  293.66,  // D4
  311.13,  // D#4
  329.63,  // E4
  349.23,  // F4
  369.99,  // F#4
  392.00,  // G4
  415.30   // G#4
};



void loop() {
   waveform1.begin(1.0, 440, WAVEFORM_SINE);
   noteNumber = noteNumber + 1;
   if (noteNumber >= 12) noteNumber = 0;
  // print Fourier Transform data to the Arduino Serial Monitor
  if (fft1024_1.available()) {
    Serial.print("FFT: ");
    for (int i=0; i<30; i++) {  // 0-25  -->  DC to 1.25 kHz
      float n = fft1024_1.read(i);
      printNumber(n);
    }
    Serial.println();
  }
  
  
  
 

}


void printNumber(float n) {
  
  if (n >= 0.001) {
    Serial.print(n, 3);
    Serial.print(" ");
  } else {
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
