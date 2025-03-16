#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int i,j,k,w,p,n;
    int *m;
    m=(int*)malloc(5001*sizeof(int));
    for(i=0;i*200<5001;i++){
        for(j=0;j*300<5001;j++){
            for(k=0;k*500<5001;k++){
                w=i*200+j*300+k*500;
                p=i/5*5*380*0.8+i%5*380
                 +j/4*4*550*0.85+j%4*550
                 +k/3*3*850*0.88+k%3*850;
                if(m[w])m[w]=min(m[w],p);
                else m[w]=p;
            }
        }
    }
    while(scanf("%d",&n),n){
        printf("%d\n",m[n]);
    }
    free(m);
}

