#include <Audio.h>
#include "MyDsp.h"


float frequencies[] = {20,60,100,140,180,220,260,300, 340, 380,420,460,500,540,580,620,660,700, 740,780,820, 860, 900, 940,980, 1020,1060, 1100, 1140, 1180};
MyDsp myDsp(frequencies);
AudioOutputI2S out;
AudioInputI2S in; 
AudioControlSGTL5000 audioShield;
AudioMixer4 mixer1;
AudioSynthWaveform sine;
AudioAnalyzeFFT1024 fft1024;
AudioConnection patchCord0(myDsp,0,out,0);
AudioConnection patchCord1(myDsp,0,out,1);
AudioConnection patchCord2(in, 0, mixer1, 0);
AudioConnection patchCord3(in, 1, mixer1, 1);
AudioConnection patchCord4(mixer1, fft1024);
//AudioConnection patchCord5(mixer1, out);
float newGains []= {8,0,0,0,0,0,0,0,5,0,0,0,0,0,3,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,};

void setup() {
  Serial.begin(9600);
 
  Serial.print("cojfjh");
  AudioMemory(10);
  audioShield.enable();
  audioShield.volume(0.5);
  audioShield.inputSelect(AUDIO_INPUT_MIC);
  audioShield.micGain(15);
  myDsp.setGains(newGains);
 
  sine.begin(0.5,420,WAVEFORM_SAWTOOTH);

  mixer1.gain(0,0.5);
  mixer1.gain(1,0.5);
  mixer1.gain(2,0);
  mixer1.gain(3,0);

  fft1024.windowFunction(NULL);
  Serial.print("J'attends\n");
  delay(100);
}

void loop() {
  Serial.print("Je loupe\n");
  //Serial.print(newGains[0]);
 
  /*if (fft1024.available()) {
    //Serial.print("FFT: ");
    for (int i=0; i<30; i++) {  // 0-25  -->  DC to 1.25 kHz
      float n = fft1024.read(i)*10;
      fftRead(n,i);
    }
    //Serial.print("\n");
    myDsp.setGains(newGains);
   }
  */
    myDsp.setGains(newGains);
    delay(1000);
}


void fftRead(float n, int i) {
  if (n >= 0.00) {
    newGains[i]= n;
    //Serial.print(n, 3);
    //Serial.print(" ");
  } else {
    //on esquive la fréquence adieu 
    newGains[i] = 0;
    //Serial.print("   -  "); // don't print "0.00"
  }
}
