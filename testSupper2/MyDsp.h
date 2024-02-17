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
    MyDsp(float frequencies[30]);
    ~MyDsp();
    
    virtual void update(void);
    void setGains(float newGains[30]);

    
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
    Filtre* filtres[30];
    float puls[30];
    float paramC[30];
    float gains[30];
   
    
};

#endif
