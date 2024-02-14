#ifndef FILTRE_H_INCLUDED
#define FILTRE_H_INCLUDED


class Filtre{
public:
  Filtre(int samplingRate);

  float resonlp(float fc, int Q, int gain, float x);
  float resonbp(float fc, int Q, int gain, float x);
  float resonhp(float fc, int Q, int gain, float x);
  float peak_eq(float Lfx, float fx, float B, float x);

  
private:
    float w , w1, w2, a0, a1, a2, b0, b1, b2;
    int SR;
    void setParam(float b0,float b1,float b2,float a0,float a1, float a2);
    float tf2(float x);
    void  wget(float x );
    float tf2s(float x, float w1);
};

#endif  //FILTRE_H_INCLUDED