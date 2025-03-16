#include <stdio.h>

// Function to return the absolute value of an integer
int Abs(int x) {
    if (x < 0) {
        // If the input integer is negative, return its negation
        return -x;
    }
    // Otherwise, return the input integer as it is
    return x;
}

// Function to return the minimum of two integers
int min(int a, int b) {
    if (a > b) {
        // If the first integer is greater than the second, return the second
        return b;
    }
    // Otherwise, return the first integer
    return a;
}

int main() {
    // Declare and initialize two integer variables, N and K, using scanf
    int N, K;
    scanf("%d %d", &N, &K);

    // Declare and initialize an integer variable, x, with the value of N modulo K
    int x = N % K;

    // Call the Abs function to get the absolute value of x if it's negative
    x = Abs(x);

    // Call the min function to find the minimum between x and Abs(x-K)
    x = min(Abs(x-K), x);

    // Print the result using printf
    printf("%d\n", x);

    return 0;
}

