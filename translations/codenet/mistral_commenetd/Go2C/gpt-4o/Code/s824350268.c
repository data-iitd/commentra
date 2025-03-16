#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants definition
#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000
#define MOD 1000000007

// Function to read an integer from standard input
int getInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to calculate the minimum number of divisors
int minDivisors(int N) {
    int sqrtN = (int)sqrt(N);
    int min = N;

    for (int i = 1; i <= sqrtN; i++) {
        if (N % i != 0) {
            continue;
        }

        int num = i + (N / i) - 2;

        if (num < min) {
            min = num;
        }
    }

    return min;
}

// Main function
int main() {
    // Read the first integer from the standard input
    int N = getInt();

    // Calculate the minimum number of divisors
    int result = minDivisors(N);

    // Print the minimum number
    printf("%d\n", result);

    return 0;
}

// Additional functions can be added here if needed

// <END-OF-CODE>
