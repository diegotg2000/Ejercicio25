#include <iostream>
#include <cmath>
using namespace std;
//La ecuación diferencial es: dy/dt = -wy, con y(0)=1 y es de t=0 hasta t=4/w

void explicit_Euler(float h);
void implicit(float h);
float w=4.0;

int main{
    explicit_Euler(0.01/w);
    implicit(0.01/w);    
}

void explicit_Euler(float h){
    float yn, yn1;
    int N=4/(w*h)
    yn=1;
    cout<<0<<' '<<yn<<endl;
    for(int i=1;i<=N;i++){
        yn1=yn*(1-h*w);
        yn=yn1;
        cout<<i*h<<' '<<yn<<endl;        
    }
}

void implicit(float h){
    float yn, yn1;
    int N=4/(w*h)
    yn=1;
    cout<<0<<' '<<yn<<endl;
    for(int i=1;i<=N;i++){
        yn1=yn/(1+h*w);
        yn=yn1;
        cout<<i*h<<' '<<yn<<endl;        
    }
}