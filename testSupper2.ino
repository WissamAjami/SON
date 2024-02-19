#include <Audio.h>
#include "MyDsp.h"


float frequencies[70] = {43, 86, 129, 172, 215, 258, 301, 344, 387, 430, 473, 516, 559, 602, 645, 688, 731, 774, 817, 860, 903, 946, 989, 1032, 1075, 1118, 1161, 1204, 1247, 1290, 1333, 1376, 1419, 1462, 1505, 1548, 1591, 1634, 1677, 1720, 1763, 1806, 1849, 1892, 1935, 1978, 2021, 2064, 2107, 2150, 2193, 2236, 2279, 2322, 2365, 2408, 2451, 2494, 2537, 2580, 2623, 2666, 2709, 2752, 2795, 2838, 2881, 2924, 2967, 3010};
MyDsp myDsp(frequencies);
AudioOutputI2S out;
AudioInputI2S in; 
AudioControlSGTL5000 audioShield;
AudioMixer4 mixer1;
AudioSynthWaveform sine;
AudioAnalyzeFFT1024 fft1024;
AudioConnection patchCord0(myDsp,0,out,0);
AudioConnection patchCord1(myDsp,0,out,1);
AudioConnection patchCord(in, 0, mixer1, 0);
AudioConnection patchCord3(in,1, mixer1, 1);
AudioConnection patchCord4(mixer1, fft1024);
//AudioConnection patchCord5(mixer1, out);
float newGains [70]= {0};



void setup() {
  Serial.begin(9600);
  Serial.print("coucou");
  AudioMemory(1600);
  Serial.print("jai alloué ta mémoire");
  audioShield.enable();
  Serial.print("AudioShield enable");
  audioShield.volume(0.5);
  Serial.print("edehzfozoh");
  audioShield.inputSelect(AUDIO_INPUT_MIC);
  audioShield.micGain(20);
  myDsp.setGains(newGains);
 
  sine.begin(0.5,200,WAVEFORM_SINE);

  mixer1.gain(0,0.5);
  mixer1.gain(1,0.5);
  mixer1.gain(2,0);
  mixer1.gain(3,0);

  

  Serial.print("all is good");

}

void loop() {
  //delay(100);
  //Serial.print("I am looping");

 
  
  if (fft1024.available()) {
    Serial.print("FFT: ");
    for (int i=1; i<71; i++) {  // 0 : DC 
      float n = fft1024.read(i);
      fftRead(n,i);
    }
    Serial.print("\n");
    myDsp.setGains(newGains);
   }

   
   //afficher();
}

void afficher(){
  Serial.print("je suis là");
  for(int i=0; i<70; i++){
    Serial.print(newGains[i]);
  }
}

void fftRead(float n, int i) {
  if (n >= 0.0005) {
    //newGains[i]= Db2gain[a];
    float a = n*4;
    a = min(1,a);
    Serial.print(a, 3);
    newGains[i-1] = a;
    Serial.print(" ");
  } else {
    newGains[i-1] = 0;
    Serial.print("   -  "); // don't print "0.00"
  }
}
