#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define N 10000007

int main(){
    int tc,n,m,fl=0;
    scanf("%d%d%d",&tc,&n,&m);
    if(n>m) swap(n,m);
    for(int i=1;i<=m;i++){
        if(i*tc>=n&&i*tc<=m){
            printf("OK\n");
            fl=1;
            break;
        }
    }
    if(fl==0) puts("NG");
    return 0;
}

