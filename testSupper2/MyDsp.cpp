#include "MyDsp.h"

#define AUDIO_OUTPUTS 1

#define MULT_16 32767
#define DIV_16 0.0000305185

MyDsp::MyDsp(float frequencies[30]) : 
AudioStream(AUDIO_OUTPUTS, new audio_block_t*[AUDIO_OUTPUTS]),
noise(),
filtre1(AUDIO_SAMPLE_RATE_EXACT),
filtre2(AUDIO_SAMPLE_RATE_EXACT),
filtre3(AUDIO_SAMPLE_RATE_EXACT),
filtre4(AUDIO_SAMPLE_RATE_EXACT),
filtre5(AUDIO_SAMPLE_RATE_EXACT),
filtre6(AUDIO_SAMPLE_RATE_EXACT),
filtre7(AUDIO_SAMPLE_RATE_EXACT),
filtre8(AUDIO_SAMPLE_RATE_EXACT),
filtre9(AUDIO_SAMPLE_RATE_EXACT),
filtre10(AUDIO_SAMPLE_RATE_EXACT),
filtre11(AUDIO_SAMPLE_RATE_EXACT),
filtre12(AUDIO_SAMPLE_RATE_EXACT),
filtre13(AUDIO_SAMPLE_RATE_EXACT),
filtre14(AUDIO_SAMPLE_RATE_EXACT),
filtre15(AUDIO_SAMPLE_RATE_EXACT),
filtre16(AUDIO_SAMPLE_RATE_EXACT),
filtre17(AUDIO_SAMPLE_RATE_EXACT),
filtre18(AUDIO_SAMPLE_RATE_EXACT),
filtre19(AUDIO_SAMPLE_RATE_EXACT),
filtre20(AUDIO_SAMPLE_RATE_EXACT),
filtre21(AUDIO_SAMPLE_RATE_EXACT),
filtre22(AUDIO_SAMPLE_RATE_EXACT),
filtre23(AUDIO_SAMPLE_RATE_EXACT),
filtre24(AUDIO_SAMPLE_RATE_EXACT),
filtre25(AUDIO_SAMPLE_RATE_EXACT),
filtre26(AUDIO_SAMPLE_RATE_EXACT),
filtre27(AUDIO_SAMPLE_RATE_EXACT),
filtre28(AUDIO_SAMPLE_RATE_EXACT),
filtre29(AUDIO_SAMPLE_RATE_EXACT),
filtre30(AUDIO_SAMPLE_RATE_EXACT),
filtres{&filtre1, &filtre2, &filtre3, &filtre4, &filtre5, &filtre6, &filtre7, &filtre8, &filtre9, &filtre10, 
         &filtre11, &filtre12, &filtre13, &filtre14, &filtre15, &filtre16, &filtre17, &filtre18, &filtre19, &filtre20, 
         &filtre21, &filtre22, &filtre23, &filtre24, &filtre25, &filtre26, &filtre27, &filtre28, &filtre29, &filtre30}
{
  for (int i = 0; i < 30; ++i) {
        float w = 2* 3.1415* frequencies[i];
        paramC[i] = 1/tan(w*0.5/AUDIO_SAMPLE_RATE_EXACT);
        puls[i] = w;
        Bw[i] = (1.0/AUDIO_SAMPLE_RATE_EXACT)*sin(puls[i]*(1.0/AUDIO_SAMPLE_RATE_EXACT));
    }
    
    // Initialisation des gains à zéro
    for (int i = 0; i < 30; ++i) {
        gains[i] = 0;
    }
}

MyDsp::~MyDsp(){}

void MyDsp::setGains(float newGains[30]){
   for (int i = 0; i < 15; ++i) {
      gains[i] = newGains[i];
    }
}


void MyDsp::update(void) {
  audio_block_t* outBlock[AUDIO_OUTPUTS];
  for (int channel = 0; channel < AUDIO_OUTPUTS; channel++) {
    outBlock[channel] = allocate();
    if (outBlock[channel]) {
      for (int i = 0; i < AUDIO_BLOCK_SAMPLES; i++) {
        float noiseSound = noise.tick()*0.5;
        float currentSample = noiseSound;
        for( int j = 0; j< 30; j++) {
          currentSample = (*filtres[j]).peak_eq(1.58,puls[j], paramC[j], 0.5*Bw[j], currentSample);
        }
        currentSample = currentSample *0.5;
        //currentSample= (filtre1).peak_eq(10,puls[10], paramC[10], 0.5*Bw[10], currentSample);
        currentSample = max(-1,min(1,currentSample));
        int16_t val = currentSample*MULT_16;
        outBlock[channel]->data[i] = val;
      }
      transmit(outBlock[channel], channel);
      release(outBlock[channel]);
    
    }
  }
}
