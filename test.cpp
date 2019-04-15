#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;
//La ecuación diferencial es: d2y/dt2 = -w2sin(y), con y(0)=pi/3 y v(0)=0. Se va a integrar de 0 hasta 40.

void explicit_Euler(float h);
void rk4(float h);
float w=1.0;
float Y=0.5;
float T=40.0;

int main(){
    explicit_Euler(T/50000); 
    rk4(T/50000);
    return 0;
}

void explicit_Euler(float h){
    ofstream outfile;

    outfile.open("explicito.txt");

    float yn, yn1;
    float vn,vn1;
    int N=T/h;
    yn=Y;
    vn=0;
    outfile<<0<<' '<<yn<<endl;
    for(int i=1;i<=N;i++){
        yn1=yn+h*vn;
        vn1=vn-h*w*w*sin(yn);
        yn=yn1;
        vn=vn1;
        outfile<<i*h<<' '<<yn<<endl;        
    }
    
    outfile.close();
}
void rk4(float h){
    ofstream outfile;

    outfile.open("rk4.txt");

    float yn, yn1;
    float vn,vn1;
    int N=T/h;
    float k11,k12,k13,k14;
    float k21,k22,k23,k24;
    yn=Y;
    vn=0;
    outfile<<0<<' '<<yn<<endl;
    for(int i=1;i<=N;i++){
        k11=h*(vn);
        k21=h*(-w*w*sin(yn));
            
        k12=h*(vn+k21/2);
        k22=h*(-w*w*sin(yn+k11/2));
            
        k13=h*(vn+k22/2);
        k23=h*(-w*w*sin(yn+k12/2));
        
        k14=h*(vn+k23);
        k24=h*(-w*w*sin(yn+k13));
        
        yn1=yn+(k11+k12+k13+k14)/6;
        vn1=vn+(k21+k22+k23+k24)/6;
        yn=yn1;
        vn=vn1;
        outfile<<i*h<<' '<<yn<<endl;        
    }
    
    outfile.close();
}



