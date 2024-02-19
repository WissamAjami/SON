#ifndef faust_teensy_h_
#define faust_teensy_h_

#include "Arduino.h"
#include "AudioStream.h"
#include "Audio.h"
#include "Noise.h"
#include "Filtre.h"


class MyDsp : public AudioStream
{
  public:
    MyDsp(float frequencies[50]);
    ~MyDsp();
    
    virtual void update(void);
    void setGains(float newGains[50]);

    
  private:
    Noise noise;
    Filtre filtre1;
    Filtre filtre2;
    Filtre filtre3;
    Filtre filtre4;
    Filtre filtre5;
    Filtre filtre6;
    Filtre filtre7;
    Filtre filtre8;
    Filtre filtre9;
    Filtre filtre10;
    Filtre filtre11;
    Filtre filtre12;
    Filtre filtre13;
    Filtre filtre14;
    Filtre filtre15;
    Filtre filtre16;
    Filtre filtre17;
    Filtre filtre18;
    Filtre filtre19;
    Filtre filtre20;
    Filtre filtre21;
    Filtre filtre22;
    Filtre filtre23;
    Filtre filtre24;
    Filtre filtre25;
    Filtre filtre26;
    Filtre filtre27;
    Filtre filtre28;
    Filtre filtre29;
    Filtre filtre30;
    Filtre filtre31;
    Filtre filtre32;
    Filtre filtre33;
    Filtre filtre34;
    Filtre filtre35;
    Filtre filtre36;
    Filtre filtre37;
    Filtre filtre38;
    Filtre filtre39;
    Filtre filtre40;
    Filtre filtre41;
    Filtre filtre42;
    Filtre filtre43;
    Filtre filtre44;
    Filtre filtre45;
    Filtre filtre46;
    Filtre filtre47;
    Filtre filtre48;
    Filtre filtre49;
    Filtre filtre50;
    Filtre filtre51;
    Filtre filtre52;
    Filtre filtre53;
    Filtre filtre54;
    Filtre filtre55;
    Filtre filtre56;
    Filtre filtre57;
    Filtre filtre58;
    Filtre filtre59;
    Filtre filtre60;
    Filtre filtre61;
    Filtre filtre62;
    Filtre filtre63;
    Filtre filtre64;
    Filtre filtre65;
    Filtre filtre66;
    Filtre filtre67;
    Filtre filtre68;
    Filtre filtre69;
    Filtre filtre70;

    Filtre* filtres[70];
    float quality[70];
    float puls[70];
    float paramC[70];
    float gains[70];
    float Bw[70];
   
    
};

#endif
