//#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>

using namespace std;
*/

// Main function to execute the program
int main(){

    // Vector to store strings and variables to store N and L
    char **v;
    int N,L;

    // Read the number of strings N and the length L from the standard input
    scanf("%d %d",&N,&L);

    // Allocate memory for the vector v
    v = (char**)malloc(N*sizeof(char*));

    // Read N strings from the standard input and store them in the vector v
    for(int i=0;i<N;i++){
        v[i] = (char*)malloc(L*sizeof(char));
        scanf("%s",v[i]);
    }

    // Sort the vector v in lexicographical order
    qsort(v,N,sizeof(char*),compare);

    // Concatenate and print the sorted strings without spaces
    for(int i=0;i<N;i++){
        printf("%s",v[i]);
    }
    printf("\n");

    // Free the memory allocated for the vector v
    for(int i=0;i<N;i++){
        free(v[i]);
    }
    free(v);
}

// Function to compare two strings in lexicographical order
int compare(const void *a,const void *b){
    return strcmp(*(char**)a,*(char**)b);
}

