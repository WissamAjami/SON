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
filtre31(AUDIO_SAMPLE_RATE_EXACT),
filtre32(AUDIO_SAMPLE_RATE_EXACT),
filtre33(AUDIO_SAMPLE_RATE_EXACT),
filtre34(AUDIO_SAMPLE_RATE_EXACT),
filtre35(AUDIO_SAMPLE_RATE_EXACT),
filtre36(AUDIO_SAMPLE_RATE_EXACT),
filtre37(AUDIO_SAMPLE_RATE_EXACT),
filtre38(AUDIO_SAMPLE_RATE_EXACT),
filtre39(AUDIO_SAMPLE_RATE_EXACT),
filtre40(AUDIO_SAMPLE_RATE_EXACT),
filtre41(AUDIO_SAMPLE_RATE_EXACT),
filtre42(AUDIO_SAMPLE_RATE_EXACT),
filtre43(AUDIO_SAMPLE_RATE_EXACT),
filtre44(AUDIO_SAMPLE_RATE_EXACT),
filtre45(AUDIO_SAMPLE_RATE_EXACT),
filtre46(AUDIO_SAMPLE_RATE_EXACT),
filtre47(AUDIO_SAMPLE_RATE_EXACT),
filtre48(AUDIO_SAMPLE_RATE_EXACT),
filtre49(AUDIO_SAMPLE_RATE_EXACT),
filtre50(AUDIO_SAMPLE_RATE_EXACT),
filtre51(AUDIO_SAMPLE_RATE_EXACT),
filtre52(AUDIO_SAMPLE_RATE_EXACT),
filtre53(AUDIO_SAMPLE_RATE_EXACT),
filtre54(AUDIO_SAMPLE_RATE_EXACT),
filtre55(AUDIO_SAMPLE_RATE_EXACT),
filtre56(AUDIO_SAMPLE_RATE_EXACT),
filtre57(AUDIO_SAMPLE_RATE_EXACT),
filtre58(AUDIO_SAMPLE_RATE_EXACT),
filtre59(AUDIO_SAMPLE_RATE_EXACT),
filtre60(AUDIO_SAMPLE_RATE_EXACT),
filtre61(AUDIO_SAMPLE_RATE_EXACT),
filtre62(AUDIO_SAMPLE_RATE_EXACT),
filtre63(AUDIO_SAMPLE_RATE_EXACT),
filtre64(AUDIO_SAMPLE_RATE_EXACT),
filtre65(AUDIO_SAMPLE_RATE_EXACT),
filtre66(AUDIO_SAMPLE_RATE_EXACT),
filtre67(AUDIO_SAMPLE_RATE_EXACT),
filtre68(AUDIO_SAMPLE_RATE_EXACT),
filtre69(AUDIO_SAMPLE_RATE_EXACT),
filtre70(AUDIO_SAMPLE_RATE_EXACT),
filtres{&filtre1, &filtre2, &filtre3, &filtre4, &filtre5, &filtre6, &filtre7, &filtre8, &filtre9, &filtre10, 
        &filtre11, &filtre12, &filtre13, &filtre14, &filtre15, &filtre16, &filtre17, &filtre18, &filtre19, &filtre20, 
        &filtre21, &filtre22, &filtre23, &filtre24, &filtre25, &filtre26, &filtre27, &filtre28, &filtre29, &filtre30,
        &filtre31, &filtre32, &filtre33, &filtre34, &filtre35, &filtre36, &filtre37, &filtre38, &filtre39, &filtre31,
        &filtre41, &filtre42, &filtre43, &filtre44, &filtre45, &filtre46, &filtre47, &filtre48, &filtre49, &filtre50,
        &filtre51, &filtre52, &filtre53, &filtre54, &filtre55, &filtre56, &filtre57, &filtre58, &filtre59, &filtre60,
        &filtre61, &filtre62, &filtre63, &filtre64, &filtre65, &filtre66, &filtre67, &filtre68, &filtre69, &filtre70}

{
  for (int i = 0; i < 70; ++i) {
        quality[i] = frequencies[i]/43;
        float w = 2* 3.1415* frequencies[i];
        paramC[i] = 1/tan(w*0.5/AUDIO_SAMPLE_RATE_EXACT);
        puls[i] = w;
        Bw[i] = (1.0/AUDIO_SAMPLE_RATE_EXACT)*sin(puls[i]*(1.0/AUDIO_SAMPLE_RATE_EXACT));
    }
    
    // Initialisation des gains à zéro
    for (int i = 0; i < 70; ++i) {
        gains[i] = 0;
    }
    //Initialisation des fitres
    for( int j = 0; j< 70; j++) {
         (*filtres[j]).resonbp(paramC[j], 1000);
    }
}


MyDsp::~MyDsp(){}

void MyDsp::setGains(float newGains[50]){
   for (int i = 0; i < 70; ++i) {
      gains[i] = newGains[i];
    }
}


void MyDsp::update(void) {
  audio_block_t* outBlock[AUDIO_OUTPUTS];
  for (int channel = 0; channel < AUDIO_OUTPUTS; channel++) {
    outBlock[channel] = allocate();
    if (outBlock[channel]) {
      for (int i = 0; i < AUDIO_BLOCK_SAMPLES; i++) {
        float noiseSound = noise.tick()*0.25;
        float currentSample = 0.0;
        for( int j = 0; j< 70; j++) {
          currentSample = currentSample + (*filtres[j]).tick(noiseSound, gains[j])*0.5;
        }
        //currentSample = currentSample *0.5;
        currentSample = max(-1,min(1,currentSample));
        int16_t val = currentSample*MULT_16;
        outBlock[channel]->data[i] = val;
      }
      transmit(outBlock[channel], channel);
      release(outBlock[channel]);
    
    }
  }
}
