
#include <stdio.h>

void A(void);
void B(void);
void C(void);
void D(void);

int main(void){
    B();
}

void B(void){
    long long int x,sum;
    scanf("%lld",&x);
    int i;
    sum=100;
    for(i=0;sum<x;++i){
        sum+=sum/100;
    }
    printf("%d\n",i);
}

