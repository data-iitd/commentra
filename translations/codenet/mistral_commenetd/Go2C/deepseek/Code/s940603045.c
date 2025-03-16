#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define INF 2147483647

// Constants and variables declaration
const int inf = INF;

// Global variables declaration

// Function prototypes
void init();
void main();

// init function initializes the program
void init() {
    // Set log flags for short file names
    // Seed random number generator with current time
}

// main function is the entry point of the program
void main() {
    // Read input N as a string
    char N[100];
    scanf("%s", N);
    // Convert N to an integer
    int n = 0;
    for (int i = 0; i < strlen(N); i++) {
        n += N[i] - '0';
    }
    // Read input m as an integer
    int m;
    sscanf(N, "%d", &m);
    // Check if m is divisible by n
    if (m % n == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

