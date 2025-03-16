#include<stdio.h> // Include standard input-output header for basic I/O functions
#include<stdlib.h> // Include standard library header for general utilities
#include<string.h> // Include string header for string manipulation
#include<math.h> // Include math header for mathematical functions
#include<limits.h> // Include limits header for numeric limits
#include<stdbool.h> // Include stdbool header for boolean data type

#define rep(i, n) for(int i = 0; i < (int)(n); i++) // Define a macro for loop iteration
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++) // Define a macro for loop iteration with start and end values
#define in(x) scanf("%d", &x) // Define a macro to read input into variable 'x'
#define out(str) printf("%s\n", str) // Define a macro to output a string followed by a newline

typedef long long ll; // Define a type alias 'll' for long long integers

int L,N; // Declare global variables for the length of strings and the number of strings

int main(){
    in(N); // Read the number of strings
    in(L); // Read the length of each string
    char S[N][L+1]; // Declare an array to store the strings
    rep(i,N)scanf("%s", S[i]); // Read each string and store it in the array
    qsort(S,N,sizeof(S[0]),cmp); // Sort the array of strings alphabetically
    rep(i,N)printf("%s", S[i]); // Output each sorted string
    printf("\n"); // Output a newline character
    return 0;
}

int cmp(const void *a, const void *b){
    return strcmp(*(char**)a, *(char**)b);
}

