#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to read an integer from input
int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to calculate the maximum of three integers
int max(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}

// Function to calculate the power of a number
int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

// Main function
int main() {
    // Read input values
    int A = nextInt();
    int B = nextInt();
    int C = nextInt();
    int K = nextInt();

    // Find the maximum value among A, B, and C
    int ma = max(A, B, C);

    // Calculate the rest of the numbers that need to be multiplied by 2 to reach or exceed K
    int rest = 0;
    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }

    // Calculate the final answer
    int answer = pow(ma, K) + rest;

    // Print the answer
    printf("%d\n", answer);

    return 0;
}

// <END-OF-CODE>
