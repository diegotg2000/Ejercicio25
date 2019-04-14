#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;
//La ecuación diferencial es: dy/dt = -wy, con y(0)=1 y es de t=0 hasta t=4/w

void explicit_Euler(float h);
void implicit(float h);
void rk4(float h);
float w=4.0;

int main(){
    explicit_Euler(0.01/w);
    implicit(0.01/w);
    rk4(0.01/w);
    return 0;
}

void explicit_Euler(float h){
    ofstream outfile;

    outfile.open("explicito.txt");

    float yn, yn1;
    int N=4/(w*h);
    yn=1;
    outfile<<0<<' '<<yn<<endl;
    for(int i=1;i<=N;i++){
        yn1=yn*(1-h*w);
        yn=yn1;
        outfile<<i*h<<' '<<yn<<endl;        
    }
    
    outfile.close();
}

void implicit(float h){
    ofstream outfile;

    outfile.open("implicito.txt");

    float yn, yn1;
    int N=4/(w*h);
    yn=1;
    outfile<<0<<' '<<yn<<endl;
    for(int i=1;i<=N;i++){
        yn1=yn*(1-h*w);
        yn=yn1;
        outfile<<i*h<<' '<<yn<<endl;        
    }
    
    outfile.close();
}
void rk4(float h){
    ofstream outfile;

    outfile.open("rk4.txt");

    float yn, yn1;
    int N=4/(w*h);
    yn=1;
    outfile<<0<<' '<<yn<<endl;
    for(int i=1;i<=N;i++){
        float k1,k2,k3,k4;
        k1=h*(-w*yn);
        k2=h*(-w*(yn+k1/2));
        k3=h*(-w*(yn+k2/2));
        k4=h*(-w*(yn+k3));
        yn1=yn+(k1+2*k2+2*k3+k4)/6;
        yn=yn1;
        outfile<<i*h<<' '<<yn<<endl;        
    }
    
    outfile.close();
}

