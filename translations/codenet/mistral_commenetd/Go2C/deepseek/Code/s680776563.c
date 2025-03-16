#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FastScanner struct and methods for reading input efficiently
typedef struct {
    char buf[1024];
    int p;
} FastScanner;

FastScanner* NewFastScanner() {
    FastScanner* s = (FastScanner*)malloc(sizeof(FastScanner));
    s->p = 0;
    return s;
}

char* Next(FastScanner* s) {
    // Preprocess the input buffer if necessary
    if (s->p >= 1024) {
        // Read a new line
        fgets(s->buf, 1024, stdin);
        s->p = 0;
    }

    // Find the start index of the next token
    int start = s->p;
    // Find the end index of the next token (space or newline character)
    while (s->p < strlen(s->buf)) {
        if (s->buf[s->p] == ' ' || s->buf[s->p] == '\n') {
            break;
        }
        s->p++;
    }

    // Return the substring of the input buffer from the start index to the current position
    char* result = (char*)malloc(s->p - start + 1);
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;

    return result;
}

char* NextLine(FastScanner* s) {
    // Preprocess the input buffer if necessary
    if (s->p >= 1024) {
        // Read a new line
        fgets(s->buf, 1024, stdin);
        s->p = 0;
    }

    // Find the start index of the next line
    int start = s->p;
    // Read the rest of the line into the buffer
    s->p = strlen(s->buf);

    // Return the substring of the input buffer from the start index to the end of the line
    char* result = (char*)malloc(s->p - start + 1);
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';

    return result;
}

int NextInt(FastScanner* s) {
    // Read a string token as an integer
    char* token = Next(s);
    // Convert the string token to an integer and return it
    int num = atoi(token);
    free(token);
    return num;
}

// Helper functions for finding the maximum and minimum values
int IntMax(int a, int b) {
    // Return the larger of the two integers
    return a < b ? b : a;
}

long long Int64Max(long long a, long long b) {
    // Return the larger of the two integers
    return a < b ? b : a;
}

double Float64Max(double a, double b) {
    // Return the larger of the two floating-point numbers
    return a < b ? b : a;
}

int IntMin(int a, int b) {
    // Return the smaller of the two integers
    return a > b ? b : a;
}

long long Int64Min(long long a, long long b) {
    // Return the smaller of the two integers
    return a > b ? b : a;
}

double Float64Min(double a, double b) {
    // Return the smaller of the two floating-point numbers
    return a > b ? b : a;
}

// Helper function for finding the greatest common divisor of two integers
int IntGcd(int a, int b) {
    // If b is 0, return a as the GCD
    if (b == 0) {
        return a;
    }

    // Recursively call IntGcd with b and the remainder of a divided by b
    return IntGcd(b, a % b);
}

long long Int64Gcd(long long a, long long b) {
    // If b is 0, return a as the GCD
    if (b == 0) {
        return a;
    }

    // Recursively call Int64Gcd with b and the remainder of a divided by b
    return Int64Gcd(b, a % b);
}

// Helper function for finding the absolute value of an integer
int IntAbs(int a) {
    // If a is negative, return the negative of a
    return a < 0 ? -a : a;
}

long long Int64Abs(long long a) {
    // If a is negative, return the negative of a
    return a < 0 ? -a : a;
}

int main() {
    // Initialize a new FastScanner object called fsc
    FastScanner* fsc = NewFastScanner();

    // Read the first three integers A, B, and C from the standard input
    int A = NextInt(fsc);
    int B = NextInt(fsc);
    int C = NextInt(fsc);

    // Check if the difference between B and A is equal to the difference between C and B
    if (B - A == C - B) {
        // If it is, print "YES"
        printf("YES\n");
    } else {
        // Otherwise, print "NO"
        printf("NO\n");
    }

    // Free the FastScanner object
    free(fsc);

    return 0;
}
