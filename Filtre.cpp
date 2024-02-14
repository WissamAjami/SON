#include <cmath>

#include "Filtre.h"

Filtre::Filtre(int samplingRate) : 
    w(0.0),
    w1(0.0),
    w2(0.0),
    a0(1),
    a1(1),
    a2(1),
    b0(1),
    b1(1),
    b2(1),
    SR(samplingRate){}

void Filtre::setParam(float b0_,float b1_,float b2_,float a0_,float a1_, float a2_){
    b0 = b0_;
    b1 = b1_;
    b2 = b2_;
    a0 = a0_;
    a1 = a1_;
    a2 = a2_;
}

float Filtre::tf2(float x){
    wget(x);
    float y = b0*w+ b1*w1+b2*w2;
    return y;    
}

void Filtre::wget(float x ){
    w = x - a1*w1 - a2*w2;
    w2 = w1;
    w1 = w;
}

float Filtre::tf2s(float x, float w1){
    float c   = 1/tan(w1*0.5/SR);
    float csq = c*c;
    float d   = a0 + a1 * c + csq;
    float b0d = (b0 + b1 * c + b2 * csq)/d;
    float b1d = 2 * (b0 - b2 * csq)/d;
    float b2d = (b0 - b1 * c + b2 * csq)/d;
    float a1d = 2 * (a0 - csq)/d;
    float a2d = (a0 - a1*c + csq)/d;
    
    setParam( b0d, b1d, b2d, a0, a1d, a2d);
    return tf2(x);
}

float Filtre :: resonlp(float fc, int Q, int gain, float x){
    float wc = 2*3.1415*fc;
    setParam( gain, 0, 0,  1, 1.0/Q,  0);
    return tf2s(x, wc);
}


float Filtre :: resonbp(float fc, int Q, int gain, float x){
    float wc = 2*3.1415*fc;
    setParam( 0,gain, 0, 1, 1.0/Q,  0);
    return tf2s(x, wc);
}

float Filtre :: resonhp(float fc, int Q, int gain, float x){
    float temp = resonlp(fc,Q,gain,x);
    return gain*x - temp;
}


float Filtre::peak_eq(float Lfx, float fx, float B, float x){
    float T = 1.0/SR;
    float wx = 2*3.1415*fx;
    float Bw = B*T/sin(wx*T); // prewarp s-bandwidth for more accuracy in z-plane
    float a_1 = 3.1415*Bw;
    float g = pow(10,abs(Lfx)/10);
    float b_1 = g*a_1;
    float b1s, a1s;
    if(Lfx>0) {
        b1s = b_1;
        a1s = a_1;
    }else {
        b1s = a_1;
        a1s = b_1;
    }
    setParam(1, b1s,1, 1 ,a1s, 1);
    return tf2s(x,wx);
}