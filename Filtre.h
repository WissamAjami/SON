#ifndef FILTRE_H_INCLUDED
#define FILTRE_H_INCLUDED


class Filtre{
public:
  Filtre(int samplingRate);

  float resonlp(float wc, float c, int Q, int gain, float x);
  float resonbp(float wc,float c, int Q, int gain, float x);
  float resonhp(float wc, float c, int Q, int gain, float x);
  float peak_eq(float Lfx, float wx, float c, float Bw , float x );

  
private:
    float w , w1, w2, a0, a1, a2, b0, b1, b2;
    int SR;
    void setParam(float b0,float b1,float b2,float a0,float a1, float a2);
    float tf2(float x);
    void  wget(float x );
    float tf2s(float x, float wc, float c);
};

#endif  //FILTRE_H_INCLUDED