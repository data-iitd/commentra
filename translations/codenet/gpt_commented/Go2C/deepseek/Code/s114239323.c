#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int nextInt();
int* nextInts(int n);
int Abs(int a);
int Min(int a, int b);

int main() {
    // Read the number of elements
    int N = nextInt();
    // Read the heights into an array
    int h[N];
    for (int i = 0; i < N; i++) {
        h[i] = nextInt();
    }

    // Initialize a dynamic programming array to store minimum costs
    int dp[N];
    for (int i = 0; i < N; i++) {
        dp[i] = 0; // Set initial values to zero
    }
    
    // Base case: cost to jump from the first to the second height
    dp[1] = Abs(h[0] - h[1]);

    // Fill the dp array with minimum costs for each position
    for (int i = 2; i < N; i++) {
        dp[i] = Min(
            dp[i-1] + Abs(h[i] - h[i-1]), // Cost from the previous height
            dp[i-2] + Abs(h[i] - h[i-2])  // Cost from two heights back
        );
    }

    // Output the minimum cost to reach the last height
    printf("%d\n", dp[N-1]);

    return 0;
}

// Max function returns the maximum value from an array of integers
int Max(int a[], int n) {
    int r = a[0];
    for (int i = 0; i < n; i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Min function returns the minimum value from an array of integers
int Min(int a, int b) {
    return (a < b) ? a : b;
}

// Sum function calculates the sum of an array of integers
int Sum(int a[], int n) {
    int r = 0;
    for (int i = 0; i < n; i++) {
        r += a[i];
    }
    return r;
}

// Abs function returns the absolute value of an integer
int Abs(int a) {
    return (a < 0) ? -a : a;
}

// nextInt reads the next integer from input
int nextInt() {
    int v;
    scanf("%d", &v);
    return v;
}

// nextInts reads n integers from input and returns them as an array
int* nextInts(int n) {
    int* r = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        r[i] = nextInt();
    }
    return r;
}
