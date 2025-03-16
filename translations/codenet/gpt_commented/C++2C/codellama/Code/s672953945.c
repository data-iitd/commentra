// Include necessary header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

// Define long long as int for convenience
#define int long long

// Macros for loop iterations
#define REP(i,s,e) for((i)=(s);(i)<(e);(i)++)
#define RREP(i,s,e) for((i)=((s)-1);(i)>=(e);(i)--)
#define FOR(i,n) for((i)=(0);(i)<(n);(i)++)
#define RFOR(i,n) for((i)=((n)-1);(i)>=(0);(i)--)

// Define a constant for modulo operation
#define MOD 1000000007

int main() {
    // Declare a vector to store strings and variables for input
    char **v;
    int N, L;

    // Read the number of strings (N) and the length of strings (L)
    scanf("%d %d", &N, &L);

    // Allocate memory for the vector of strings
    v = (char**)malloc(N * sizeof(char*));

    // Input N strings from the user and store them in the vector
    for(int i = 0; i < N; i++) {
        v[i] = (char*)malloc(L * sizeof(char));
        scanf("%s", v[i]); // Add the string to the vector
    }

    // Sort the vector of strings in lexicographical order
    qsort(v, N, sizeof(char*), compare);

    // Output the sorted strings
    for(int i = 0; i < N; i++) {
        printf("%s", v[i]); // Print each string in the sorted order
    }
    printf("\n"); // Print a newline at the end

    // Free the memory allocated for the vector
    for(int i = 0; i < N; i++) {
        free(v[i]);
    }
    free(v);

    return 0;
}

// Function to compare two strings in lexicographical order
int compare(const void *a, const void *b) {
    return strcmp(*(char**)a, *(char**)b);
}

