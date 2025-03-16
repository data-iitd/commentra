
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char** v;
    int N,L;

    scanf("%d %d",&N,&L);
    v = (char**)malloc(sizeof(char*)*N);
    for(int i=0;i<N;i++){
        v[i] = (char*)malloc(sizeof(char)*(L+1));
        scanf("%s",v[i]);
    }

    qsort(v,N,sizeof(char*),strcmp);

    for(int i=0;i<N;i++){
        printf("%s",v[i]);
    }
    printf("\n");

    for(int i=0;i<N;i++){
        free(v[i]);
    }
    free(v);

    return 0;
}

