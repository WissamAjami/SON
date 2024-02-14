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
AudioSynthWaveformSine   sine2;
// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise;         //xy=74.66666793823242,354.9999942779541
AudioInputI2S            in;           //xy=79,788
AudioFilterBiquad        biquad2; //xy=233,45
AudioFilterBiquad        biquad3; //xy=233,70
AudioFilterBiquad        biquad4; //xy=234,88
AudioFilterBiquad        biquad8; //xy=234,180
AudioFilterBiquad        biquad1;        //xy=235,20
AudioFilterBiquad        biquad7; //xy=235,158
AudioFilterBiquad        biquad30; //xy=233,677
AudioFilterBiquad        biquad12; //xy=235,279
AudioFilterBiquad        biquad26; //xy=234,593
AudioFilterBiquad        biquad5; //xy=236,112
AudioFilterBiquad        biquad6; //xy=236,134
AudioFilterBiquad        biquad9; //xy=236,205
AudioFilterBiquad        biquad10; //xy=236,230
AudioFilterBiquad        biquad11; //xy=236,255
AudioFilterBiquad        biquad13; //xy=236,303
AudioFilterBiquad        biquad25; //xy=235,570
AudioFilterBiquad        biquad15; //xy=237,342
AudioFilterBiquad        biquad27; //xy=236,613
AudioFilterBiquad        biquad20; //xy=237,451
AudioFilterBiquad        biquad23; //xy=237,525
AudioFilterBiquad        biquad24; //xy=237,546
AudioFilterBiquad        biquad14; //xy=238,322
AudioFilterBiquad        biquad16; //xy=238,364
AudioFilterBiquad        biquad28; //xy=237,635
AudioFilterBiquad        biquad29; //xy=237,657
AudioFilterBiquad        biquad18; //xy=239,408
AudioFilterBiquad        biquad19; //xy=239,430
AudioFilterBiquad        biquad21; //xy=239,474
AudioFilterBiquad        biquad17; //xy=241,387
AudioFilterBiquad        biquad22; //xy=241,496
AudioMixer4              mixer1;         //xy=271,794
AudioMixer4              mixer2; //xy=462.44444465637207,50.66667175292969
AudioMixer4              mixer4; //xy=475.33329010009766,216.11109733581543
AudioMixer4              mixer3; //xy=477.666711807251,141.5555534362793
AudioMixer4              mixer9; //xy=476.6666488647461,653.3333053588867
AudioMixer4              mixer7; //xy=478.7777900695801,463
AudioMixer4              mixer6; //xy=479.33335876464844,382.7777671813965
AudioMixer4              mixer5; //xy=479.8888854980469,295
AudioMixer4              mixer8; //xy=483.00002670288086,562.7777404785156
AudioAnalyzeFFT1024      fft1024_1;      //xy=543,784
AudioMixer4              mixer10; //xy=672.2221603393555,285.5555419921875
AudioMixer4              mixer11; //xy=677.7777976989746,478.8888740539551
AudioMixer4              mixer12; //xy=834.4444351196289,359.9999771118164
AudioOutputI2S           out;           //xy=986.6666666666666,355.55555555555554
AudioConnection          patchCord1(sine2, biquad1);
AudioConnection          patchCord2(noise, biquad2);
AudioConnection          patchCord3(noise, biquad3);
AudioConnection          patchCord4(noise, biquad4);
AudioConnection          patchCord5(noise, biquad5);
AudioConnection          patchCord6(noise, biquad6);
AudioConnection          patchCord7(noise, biquad7);
AudioConnection          patchCord8(noise, biquad8);
AudioConnection          patchCord9(noise, biquad9);
AudioConnection          patchCord10(noise, biquad10);
AudioConnection          patchCord11(noise, biquad11);
AudioConnection          patchCord12(noise, biquad12);
AudioConnection          patchCord13(noise, biquad13);
AudioConnection          patchCord14(noise, biquad14);
AudioConnection          patchCord15(noise, biquad15);
AudioConnection          patchCord16(noise, biquad16);
AudioConnection          patchCord17(noise, biquad17);
AudioConnection          patchCord18(noise, biquad18);
AudioConnection          patchCord19(noise, biquad19);
AudioConnection          patchCord20(noise, biquad20);
AudioConnection          patchCord21(noise, biquad21);
AudioConnection          patchCord22(noise, biquad22);
AudioConnection          patchCord23(noise, biquad23);
AudioConnection          patchCord24(noise, biquad24);
AudioConnection          patchCord25(noise, biquad25);
AudioConnection          patchCord26(noise, biquad26);
AudioConnection          patchCord27(noise, biquad27);
AudioConnection          patchCord28(noise, biquad28);
AudioConnection          patchCord29(noise, biquad29);
AudioConnection          patchCord30(noise, biquad30);
AudioConnection          patchCord31(in, 0, mixer1, 0);
AudioConnection          patchCord32(in, 1, mixer1, 1);
AudioConnection          patchCord33(biquad2, 0, mixer2, 1);
AudioConnection          patchCord34(biquad3, 0, mixer2, 2);
AudioConnection          patchCord35(biquad4, 0, mixer2, 3);
AudioConnection          patchCord36(biquad8, 0, mixer3, 3);
AudioConnection          patchCord37(biquad1, 0, mixer2, 0);
AudioConnection          patchCord38(biquad7, 0, mixer3, 2);
AudioConnection          patchCord39(biquad30, 0, mixer9, 1);
AudioConnection          patchCord40(biquad12, 0, mixer4, 3);
AudioConnection          patchCord41(biquad26, 0, mixer8, 1);
AudioConnection          patchCord42(biquad5, 0, mixer3, 0);
AudioConnection          patchCord43(biquad6, 0, mixer3, 1);
AudioConnection          patchCord44(biquad9, 0, mixer4, 0);
AudioConnection          patchCord45(biquad10, 0, mixer4, 1);
AudioConnection          patchCord46(biquad11, 0, mixer4, 2);
AudioConnection          patchCord47(biquad13, 0, mixer5, 0);
AudioConnection          patchCord48(biquad25, 0, mixer8, 0);
AudioConnection          patchCord49(biquad15, 0, mixer5, 2);
AudioConnection          patchCord50(biquad27, 0, mixer8, 2);
AudioConnection          patchCord51(biquad20, 0, mixer6, 3);
AudioConnection          patchCord52(biquad23, 0, mixer7, 2);
AudioConnection          patchCord53(biquad24, 0, mixer7, 3);
AudioConnection          patchCord54(biquad14, 0, mixer5, 1);
AudioConnection          patchCord55(biquad16, 0, mixer5, 3);
AudioConnection          patchCord56(biquad28, 0, mixer8, 3);
AudioConnection          patchCord57(biquad29, 0, mixer9, 0);
AudioConnection          patchCord58(biquad18, 0, mixer6, 1);
AudioConnection          patchCord59(biquad19, 0, mixer6, 2);
AudioConnection          patchCord60(biquad21, 0, mixer7, 0);
AudioConnection          patchCord61(biquad17, 0, mixer6, 0);
AudioConnection          patchCord62(biquad22, 0, mixer7, 1);
AudioConnection          patchCord63(mixer1, fft1024_1);
AudioConnection          patchCord64(mixer2, 0, mixer10, 0);
AudioConnection          patchCord65(mixer4, 0, mixer10, 2);
AudioConnection          patchCord66(mixer3, 0, mixer10, 1);
AudioConnection          patchCord67(mixer9, 0, mixer11, 3);
AudioConnection          patchCord68(mixer7, 0, mixer11, 1);
AudioConnection          patchCord69(mixer6, 0, mixer11, 0);
AudioConnection          patchCord70(mixer5, 0, mixer10, 3);
AudioConnection          patchCord71(mixer8, 0, mixer11, 2);
AudioConnection          patchCord72(mixer10, 0, mixer12, 0);
AudioConnection          patchCord73(mixer11, 0, mixer12, 1);
AudioConnection          patchCord74(mixer12, 0, out, 0);
AudioConnection          patchCord75(mixer12, 0, out, 1);


// GUItool: end automatically generated code

AudioSynthWaveform waveform1;
AudioConnection patchCord310(waveform1, 0, mixer1, 2);

//Listes des mixers, des gains et des filtres
AudioMixer4 *mixers[] = {&mixer2, &mixer3, &mixer4, &mixer5, &mixer6, &mixer7, &mixer8, &mixer9};
float gains[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
AudioFilterBiquad*  filtres [] = {&biquad1, &biquad2, &biquad3, &biquad4, &biquad5, &biquad6, &biquad7, &biquad8, &biquad9, &biquad10, &biquad11,
                                  &biquad12, &biquad13, &biquad14, &biquad15, &biquad16, &biquad17, &biquad18, &biquad19, &biquad20, &biquad21, &biquad22, &biquad23, &biquad24, &biquad25, &biquad26,
                                  &biquad27, &biquad28, &biquad29, &biquad30
                                 };


void setup() {
  Serial.begin(9600);
  AudioMemory(200);
  audioShield.enable();
  audioShield.volume(0.5);
  noise.amplitude(0.3);
  waveform1.begin(0.5, 440, WAVEFORM_SINE);
  audioShield.inputSelect(AUDIO_INPUT_MIC);
  audioShield.micGain(15);

  //Configuration des gains des mixers
  mixer1.gain(0, 0.5);
  mixer1.gain(1, 0.5);
  mixer1.gain(2, 0.5);
  mixer1.gain(3, 0.0);

  mixer10.gain(0, 0.25);
  mixer10.gain(1, 0.25);
  mixer10.gain(2, 0.25);
  mixer10.gain(3, 0.25);

  mixer11.gain(0, 0.25);
  mixer11.gain(1, 0.25);
  mixer11.gain(2, 0.25);
  mixer11.gain(3, 0.25);

  mixer12.gain(0, 0.5);
  mixer12.gain(1, 0.5);
  mixer12.gain(2, 0);
  mixer12.gain(3, 0);

  setMixerGain(mixers);

  //configuration des filtres
  setFiltres(filtres);

  // Uncomment one these to try other window functions
  //fft1024_1.windowFunction(NULL);
  // fft1024_1.windowFunction(AudioWindowBartlett1024);
  // fft1024_1.windowFunction(AudioWindowFlattop1024);
  sine2.amplitude(1);
  sine2.frequency(440);
  delay(1000);

}
void setMixerGain(AudioMixer4 *mixers[]) {
  Serial.print("Je set les gains\n");
  for (int i = 0; i < 32; i = i + 4) {
    AudioMixer4* mixer = mixers[i];
    if (mixer != NULL) {
      mixer->gain(0, gains[i]);
      Serial.print("Je set le premier in\n");
      mixer->gain(1, gains[i + 1]);
      mixer->gain(2, gains[i + 2]);
      mixer->gain(3, gains[i + 3]);
    }
  }
  Serial.print("j'ai set les mixers");
}

void setFiltres(AudioFilterBiquad  *filtres[]) {
  float freq = 38;
  for (int i = 0; i < 30; i++) {
    AudioFilterBiquad * filtre = filtres[i];
    filtre->setBandpass(0, freq, 5);
    freq = freq + 25;
  }
}


void loop() {
  //biquad1.setBandpass(0,440,130);
  // print Fourier Transform data to the Arduino Serial Monitor
  if (fft1024_1.available()) {
    Serial.print("FFT: ");
    for (int i = 0; i < 30; i++) { // 0-25  -->  DC to 1.25 kHz
      float n = fft1024_1.read(i);
      setGain(n, i);
    }
    Serial.print("gain:");
    Serial.println(gains[0]);
    Serial.println(gains[15]);
    setMixerGain(mixers);
    Serial.println();
    mixer2.gain(0, 0.75);
  }
}


void setGain(float n, int i) {
  if (n >= 0.5) {
    gains[i] = n * 10;
    Serial.print(n, 3);
    Serial.print(" ");

  } else {
    gains[i] = 0;
    Serial.print("   -  "); // don't print "0.00"
  }

}
