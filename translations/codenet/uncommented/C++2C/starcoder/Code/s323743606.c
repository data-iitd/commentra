#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#include<stdbool.h>
#include<limits.h>
#include<float.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#include<stdbool.h>
#include<limits.h>
#include<float.h>

int main(){
    int m[5001][5001][5001];
    for(int i=0;i*200<5001;i++){
        for(int j=0;j*300<5001;j++){
            for(int k=0;k*500<5001;k++){
                int w=i*200+j*300+k*500;
                int p=i/5*5*380*0.8+i%5*380
                     +j/4*4*550*0.85+j%4*550
                     +k/3*3*850*0.88+k%3*850;
                if(m[w][0])m[w][0]=min(m[w][0],p);
                else m[w][0]=p;
            }
        }
    }
    int n;
    while(scanf("%d",&n),n){
        printf("%d\n",m[n][0]);
    }
}

