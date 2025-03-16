#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Utility functions
char* nextStr() {
    // Scans the next token from standard input.
    static char buffer[100];
    scanf("%s", buffer);
    return buffer;
}

int nextInt() {
    // Scans the next token from standard input and converts it to an integer.
    int i;
    scanf("%d", &i);
    return i;
}

// Helper functions for mathematical operations
int maxInt(int a, int b) {
    // Returns the maximum of two integers.
    return (a > b) ? a : b;
}

int minInt(int a, int b) {
    // Returns the minimum of two integers.
    return (a < b) ? a : b;
}

int absInt(int a) {
    // Returns the absolute value of an integer.
    return (a >= 0) ? a : -a;
}

double absFloat64(double a) {
    // Returns the absolute value of a floating-point number.
    return (a >= 0) ? a : -a;
}

double maxFloat64(double a, double b) {
    // Returns the maximum of two floating-point numbers.
    return (a > b) ? a : b;
}

double minFloat64(double a, double b) {
    // Returns the minimum of two floating-point numbers.
    return (a < b) ? a : b;
}

int str2Int(const char* s) {
    // Converts a string to an integer.
    return atoi(s);
}

char* reverse(const char* s) {
    // Reverses a given string.
    int len = strlen(s);
    char* reversed = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        reversed[i] = s[len - 1 - i];
    }
    reversed[len] = '\0';
    return reversed;
}

int powInt(int p, int q) {
    // Calculates 'p' raised to the power of 'q'.
    return (int)pow(p, q);
}

int isPrime(int x) {
    // Checks if a given number is prime.
    if (x <= 1) return 0; // 1 and less are not prime
    if (x == 2) return 1; // 2 is prime
    if (x % 2 == 0) return 0; // even numbers are not prime

    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) return 0; // found a divisor
    }
    return 1; // is prime
}

void PrimeFactors(int n, int* pfs, int* size) {
    // Finds the prime factors of a given number.
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)++] = 2;
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            pfs[(*size)++] = i;
            n /= i;
        }
    }

    if (n > 2) {
        pfs[(*size)++] = n;
    }
}

void PrimeFactorsMap(int n, int* pfs, int* counts, int* size) {
    // Finds the prime factors of a given number and returns them as a map.
    *size = 0;
    while (n % 2 == 0) {
        pfs[(*size)] = 2;
        counts[(*size)]++;
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            pfs[(*size)] = i;
            counts[(*size)]++;
            n /= i;
        }
    }

    if (n > 2) {
        pfs[(*size)] = n;
        counts[(*size)]++;
    }
}

// Example usage
int main() {
    // Example usage of the functions
    printf("Enter an integer: ");
    int n = nextInt();
    printf("Is %d prime? %d\n", n, isPrime(n));

    int pfs[100], size;
    PrimeFactors(n, pfs, &size);
    printf("Prime factors of %d: ", n);
    for (int i = 0; i < size; i++) {
        printf("%d ", pfs[i]);
    }
    printf("\n");

    return 0;
}

// <END-OF-CODE>
