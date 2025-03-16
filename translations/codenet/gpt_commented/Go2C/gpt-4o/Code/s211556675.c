#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of three integers
int max(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}

// Function to read an integer from input
int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Main function
int main() {
    // Read four integers from input
    int A = nextInt();
    int B = nextInt();
    int C = nextInt();
    int K = nextInt();

    // Determine the maximum value among A, B, and C
    int ma = max(A, B, C);
    int rest = 0; // Initialize the rest variable to hold the sum of the other two values

    // Calculate the sum of the two smaller values
    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }

    // Double the maximum value K times
    for (int i = 0; i < K; i++) {
        ma *= 2;
    }

    // Output the final result: doubled max value plus the sum of the other two
    printf("%d\n", ma + rest);
    return 0; // End of the program
}

// <END-OF-CODE>
