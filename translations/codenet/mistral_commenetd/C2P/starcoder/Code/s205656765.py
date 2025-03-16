#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define A 100
#define B 100
#define C 100

#define MAX 1000000000

int main()
{
    int X,i,j,k,kosu=0;

    scanf("%d", &X);

    for(i=0;i<=A;i++){
        for(j=0;j<=B;j++){
            for(k=0;k<=C;k++){
                if(X == (10*i) + (2*j) + k){
                    kosu++;
                }
            }
        }
    }

    printf("%d\n",kosu);

    return 0;
}

