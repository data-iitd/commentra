#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    // Vector to store strings and variables to store N and L
    char **v;
    int N,L;

    // Read the number of strings N and the length L from the standard input
    scanf("%lld %lld",&N,&L);

    // Allocate memory for the vector v
    v=(char**)malloc(N*sizeof(char*));

    // Read N strings from the standard input and store them in the vector v
    for(int i=0;i<N;i++){
        v[i]=(char*)malloc(L*sizeof(char));
        scanf("%s",v[i]);
    }

    // Sort the vector v in lexicographical order
    qsort(v,N,L,strcmp);

    // Concatenate and print the sorted strings without spaces
    for(int i=0;i<N;i++){
        printf("%s",v[i]);
    }
    printf("\n");
}

