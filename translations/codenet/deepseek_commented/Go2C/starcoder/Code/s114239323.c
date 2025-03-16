#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// Reads the next integer from the input
int nextInt() {
    return nextInt(); // Comment: Reads the next integer from the input
}

// Reads a slice of integers of length N
int* nextInts(int N) {
    return nextInts(N); // Comment: Reads a slice of integers of length N
}

// Main function to solve the problem
int main() {
    // Reads the number of steps N
    int N = nextInt(); // Comment: Reads the number of steps N
    
    // Reads the list of heights h
    int* h = nextInts(N); // Comment: Reads the list of heights h
    
    // Initializes the DP array with zeros
    int* dp = malloc(N * sizeof(int)); // Comment: Initializes the DP array with zeros
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
int max(int* a, int n) {
    int r = a[0];
    for (int i = 0; i < n; i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to find the minimum value in a slice of integers
int min(int* a, int n) {
    int r = a[0];
    for (int i = 0; i < n; i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to calculate the sum of a slice of integers
int sum(int* a, int n) {
    int r = 0;
    for (int i = 0; i < n; i++) {
        r += a[i];
    }
    return r;
}

// Utility function to calculate the sum of a slice of integers
int sum(int* a, int n) {
    int r = 0;
    for (int i = 0; i < n; i++) {
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
    Pair* data;
    int len;
} Pairs;

// Len method to get the length of the Pairs slice
int Pairs_len(Pairs* p) {
    return p->len;
}

// Swap method to swap two elements in the Pairs slice
void Pairs_swap(Pairs* p, int i, int j) {
    Pair t = p->data[i];
    p->data[i] = p->data[j];
    p->data[j] = t;
}

// Less method to compare two elements in the Pairs slice
bool Pairs_less(Pairs* p, int i, int j) {
    return p->data[i].b < p->data[j].b;
}

// Variable to hold the nextReader function
int (*nextReader)();

// Initializes the nextReader function
void init() {
    nextReader = NewScanner();
}

// NewScanner function to create a new scanner for reading input
int* NewScanner() {
    int* r = malloc(sizeof(int));
    scanf("%d", r);
    return r;
}

// nextString function to read the next string
char* nextString() {
    char* r = malloc(1024);
    scanf("%s", r);
    return r;
}

// nextInt64 function to read the next 64-bit integer
long long nextInt64() {
    long long r;
    scanf("%lld", &r);
    return r;
}

// nextInt function to read the next integer
int nextInt() {
    int r;
    scanf("%d", &r);
    return r;
}

// nextInts function to read a slice of integers of length N
int* nextInts(int n) {
    int* r = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }
    return r;
}

// nextStrings function to read a slice of strings of length N
char** nextStrings(int n) {
    char** r = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        r[i] = malloc(1024);
        scanf("%s", r[i]);
    }
    return r;
}

// nextFloat64 function to read the next float64
double nextFloat64() {
    double r;
    scanf("%lf", &r);
    return r;
}

