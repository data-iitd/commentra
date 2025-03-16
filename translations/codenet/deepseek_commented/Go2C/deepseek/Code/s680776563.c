#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Main function: Entry point of the program.
// Initializes a FastScanner, reads three integers A, B, and C,
// and checks if the difference between consecutive integers is the same.
// If the difference is the same, it prints "YES"; otherwise, it prints "NO".
int main() {
    int A = readInt();
    int B = readInt();
    int C = readInt();
    if (B - A == C - B) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

// Utility functions for various operations.
int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int abs(int a) {
    return a < 0 ? -a : a;
}
