#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Main function is the entry point of our program
int main() {
    // Read the first three integers A, B, and C from the standard input
    int A = readInt();
    int B = readInt();
    int C = readInt();

    // Check if the difference between B and A is equal to the difference between C and B
    if (B - A == C - B) {
        // If it is, print "YES"
        printf("YES\n");
    } else {
        // Otherwise, print "NO"
        printf("NO\n");
    }

    return 0;
}

// Helper functions for finding the maximum and minimum values
int IntMax(int a, int b) {
    return (a > b) ? a : b;
}

long long Int64Max(long long a, long long b) {
    return (a > b) ? a : b;
}

double Float64Max(double a, double b) {
    return (a > b) ? a : b;
}

int IntMin(int a, int b) {
    return (a < b) ? a : b;
}

long long Int64Min(long long a, long long b) {
    return (a < b) ? a : b;
}

double Float64Min(double a, double b) {
    return (a < b) ? a : b;
}

// Helper function for finding the greatest common divisor of two integers
int IntGcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return IntGcd(b, a % b);
}

long long Int64Gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return Int64Gcd(b, a % b);
}

// Helper function for finding the absolute value of an integer
int IntAbs(int a) {
    return (a < 0) ? -a : a;
}

long long Int64Abs(long long a) {
    return (a < 0) ? -a : a;
}

// <END-OF-CODE>
