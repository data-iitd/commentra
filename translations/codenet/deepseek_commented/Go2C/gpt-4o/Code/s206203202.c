#include <stdio.h>

// Abs returns the absolute value of an integer
int Abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

// min returns the smaller of two integers
int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K); // Read two integers from input

    int x;
    x = N % K; // Calculate the remainder of N divided by K

    x = min(Abs(x - K), x); // Calculate the minimum of the absolute difference and x itself
    printf("%d\n", x);      // Print the result

    return 0;
}

// <END-OF-CODE>
