#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int* dp = (int*)calloc(N, sizeof(int)); // Comment: Initializes the DP array with zeros
    
    // Sets the cost to reach the second step
    dp[1] = abs(h[0] - h[1]); // Comment: Sets the cost to reach the second step
    
    // Computes the minimum cost to reach each step using dynamic programming
    for (int i = 2; i < N; i++) {
        dp[i] = (dp[i - 1] + abs(h[i] - h[i - 1])) < (dp[i - 2] + abs(h[i] - h[i - 2])) ? (dp[i - 1] + abs(h[i] - h[i - 1])) : (dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    
    // Prints the minimum cost to reach the last step
    printf("%d\n", dp[N-1]); // Comment: Prints the minimum cost to reach the last step
    
    // Frees the allocated memory
    free(dp);
    free(h);
    
    return 0;
}

// Utility function to find the absolute value of an integer
int abs(int a) {
    return a < 0 ? -a : a;
}

// Utility function to find the maximum value in a slice of integers
int max(int* a, int len) {
    int r = a[0];
    for (int i = 0; i < len; i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to find the minimum value in a slice of integers
int min(int* a, int len) {
    int r = a[0];
    for (int i = 0; i < len; i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to calculate the sum of a slice of integers
int sum(int* a, int len) {
    int r = 0;
    for (int i = 0; i < len; i++) {
        r += a[i];
    }
    return r;
}

// Variable to hold the nextReader function
char* nextReader();

// Initializes the nextReader function
char* nextReader() {
    static char buffer[1024];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        return buffer;
    }
    return NULL;
}

// nextString function to read the next string
char* nextString() {
    char* line = nextReader();
    if (line != NULL) {
        return strtok(line, " \n");
    }
    return NULL;
}

// nextInt64 function to read the next 64-bit integer
long long nextInt64() {
    char* str = nextString();
    if (str != NULL) {
        return atoll(str);
    }
    return 0;
}

// nextInt function to read the next integer
int nextInt() {
    char* str = nextString();
    if (str != NULL) {
        return atoi(str);
    }
    return 0;
}

// nextInts function to read a slice of integers of length N
int* nextInts(int n) {
    int* r = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        r[i] = nextInt();
    }
    return r;
}

// nextStrings function to read a slice of strings of length N
char** nextStrings(int n) {
    char** r = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        r[i] = nextString();
    }
    return r;
}

// nextFloat64 function to read the next float64
double nextFloat64() {
    char* str = nextString();
    if (str != NULL) {
        return atof(str);
    }
    return 0.0;
}

