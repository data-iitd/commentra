#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Reads the next integer from the input
int nextInt() {
    int v;
    scanf("%d", &v);
    return v;
}

// Reads a slice of integers of length N
int* nextInts(int N) {
    int* r = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        r[i] = nextInt();
    }
    return r;
}

// Main function to solve the problem
int main() {
    // Reads the number of steps N
    int N = nextInt(); // Comment: Reads the number of steps N
    
    // Reads the list of heights h
    int* h = nextInts(N); // Comment: Reads the list of heights h
    
    // Initializes the DP array with zeros
    int* dp = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        dp[i] = 0;
    }
    
    // Sets the cost to reach the second step
    dp[1] = abs(h[0] - h[1]); // Comment: Sets the cost to reach the second step
    
    // Computes the minimum cost to reach each step using dynamic programming
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                    dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    
    // Prints the minimum cost to reach the last step
    printf("%d\n", dp[N-1]); // Comment: Prints the minimum cost to reach the last step
    
    // Frees the memory allocated for the DP array
    free(dp);
    
    // Frees the memory allocated for the heights array
    free(h);
    
    return 0;
}

// Utility function to find the absolute value of an integer
int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

// Utility function to find the maximum value in a slice of integers
int max(int* a, int N) {
    int r = a[0];
    for (int i = 0; i < N; i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to find the minimum value in a slice of integers
int min(int* a, int N) {
    int r = a[0];
    for (int i = 0; i < N; i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to calculate the sum of a slice of integers
int sum(int* a, int N) {
    int r = 0;
    for (int i = 0; i < N; i++) {
        r += a[i];
    }
    return r;
}

// Pair struct to represent a pair of integers
typedef struct {
    int a, b;
} Pair;

// Pairs slice to represent a slice of Pair
typedef struct {
    Pair* p;
    int N;
} Pairs;

// Len method to get the length of the Pairs slice
int pairsLen(Pairs p) {
    return p.N;
}

// Swap method to swap two elements in the Pairs slice
void pairsSwap(Pairs p, int i, int j) {
    Pair t = p.p[i];
    p.p[i] = p.p[j];
    p.p[j] = t;
}

// Less method to compare two elements in the Pairs slice
int pairsLess(Pairs p, int i, int j) {
    return p.p[i].b < p.p[j].b;
}

// nextString function to read the next string
char* nextString() {
    char* r = (char*)malloc(1024 * sizeof(char));
    scanf("%s", r);
    return r;
}

// nextInt64 function to read the next 64-bit integer
long long nextInt64() {
    long long v;
    scanf("%lld", &v);
    return v;
}

// nextInt function to read the next integer
int nextInt() {
    int v;
    scanf("%d", &v);
    return v;
}

// nextInts function to read a slice of integers of length N
int* nextInts(int N) {
    int* r = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        r[i] = nextInt();
    }
    return r;
}

// nextStrings function to read a slice of strings of length N
char** nextStrings(int N) {
    char** r = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        r[i] = nextString();
    }
    return r;
}

// nextFloat64 function to read the next float64
double nextFloat64() {
    double f;
    scanf("%lf", &f);
    return f;
}

