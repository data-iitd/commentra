
#include <stdio.h>
#include <stdlib.h>

// Define a struct for the FastScanner
typedef struct {
    char *buf;
    int p;
} FastScanner;

// Define a function to create a new FastScanner
FastScanner *NewFastScanner() {
    // Initialize a new FastScanner object with a buffer size of 1024 bytes
    FastScanner *fsc = (FastScanner *)malloc(sizeof(FastScanner));
    fsc->buf = (char *)malloc(1024 * sizeof(char));
    fsc->p = 0;
    return fsc;
}

// Define a function to read the next token from the input
char *Next(FastScanner *fsc) {
    // Preprocess the input buffer if necessary
    if (fsc->p >= 1024) {
        // Read a new line into the buffer
        fgets(fsc->buf, 1024, stdin);
        fsc->p = 0;
    }

    // Find the start index of the next token
    int start = fsc->p;
    // Find the end index of the next token (space or newline character)
    while (fsc->buf[fsc->p]!='' && fsc->buf[fsc->p]!= '\n') {
        fsc->p++;
    }

    // Return the substring of the input buffer from the start index to the current position
    char *result = (char *)malloc((fsc->p - start + 1) * sizeof(char));
    strncpy(result, fsc->buf + start, fsc->p - start);
    result[fsc->p - start] = '\0';
    // Move the position index to the next character
    fsc->p++;

    // Return the result
    return result;
}

// Define a function to read the next line from the input
char *NextLine(FastScanner *fsc) {
    // Preprocess the input buffer if necessary
    if (fsc->p >= 1024) {
        // Read a new line into the buffer
        fgets(fsc->buf, 1024, stdin);
        fsc->p = 0;
    }

    // Find the start index of the next line
    int start = fsc->p;
    // Read the rest of the line into the buffer
    while (fsc->buf[fsc->p]!= '\n') {
        fsc->p++;
    }

    // Return the substring of the input buffer from the start index to the end of the line
    char *result = (char *)malloc((fsc->p - start + 1) * sizeof(char));
    strncpy(result, fsc->buf + start, fsc->p - start);
    result[fsc->p - start] = '\0';

    // Return the result
    return result;
}

// Define a function to read the next integer from the input
int NextInt(FastScanner *fsc) {
    // Read a string token as an integer
    char *token = Next(fsc);
    // Convert the string token to an integer and return it
    int num = atoi(token);
    free(token);
    return num;
}

// Define a function to find the maximum of two integers
int IntMax(int a, int b) {
    // Return the larger of the two integers
    if (a < b) {
        return b;
    }
    return a;
}

// Define a function to find the minimum of two integers
int IntMin(int a, int b) {
    // Return the smaller of the two integers
    if (a > b) {
        return b;
    }
    return a;
}

// Define a function to find the greatest common divisor of two integers
int IntGcd(int a, int b) {
    // If b is 0, return a as the GCD
    if (b == 0) {
        return a;
    }

    // Recursively call IntGcd with b and the remainder of a divided by b
    return IntGcd(b, a % b);
}

// Define a function to find the absolute value of an integer
int IntAbs(int a) {
    // If a is negative, return the negative of a
    if (a < 0) {
        return -a;
    }
    // Otherwise, return a as is
    return a;
}

// Define a function to find the maximum of three integers
int IntMax3(int a, int b, int c) {
    return IntMax(a, IntMax(b, c));
}

// Define a function to find the minimum of three integers
int IntMin3(int a, int b, int c) {
    return IntMin(a, IntMin(b, c));
}

// Define a function to find the maximum of four integers
int IntMax4(int a, int b, int c, int d) {
    return IntMax(a, IntMax(b, IntMax(c, d)));
}

// Define a function to find the minimum of four integers
int IntMin4(int a, int b, int c, int d) {
    return IntMin(a, IntMin(b, IntMin(c, d)));
}

// Define a function to find the maximum of five integers
int IntMax5(int a, int b, int c, int d, int e) {
    return IntMax(a, IntMax(b, IntMax(c, IntMax(d, e))));
}

// Define a function to find the minimum of five integers
int IntMin5(int a, int b, int c, int d, int e) {
    return IntMin(a, IntMin(b, IntMin(c, IntMin(d, e))));
}

// Define a function to find the maximum of six integers
int IntMax6(int a, int b, int c, int d, int e, int f) {
    return IntMax(a, IntMax(b, IntMax(c, IntMax(d, IntMax(e, f))));
}

// Define a function to find the minimum of six integers
int IntMin6(int a, int b, int c, int d, int e, int f) {
    return IntMin(a, IntMin(b, IntMin(c, IntMin(d, IntMin(e, f))));
}

// Define a function to find the maximum of seven integers
int IntMax7(int a, int b, int c, int d, int e, int f, int g) {
    return IntMax(a, IntMax(b, IntMax(c, IntMax(d, IntMax(e, IntMax(f, g))));
}

// Define a function to find the minimum of seven integers
int IntMin7(int a, int b, int c, int d, int e, int f, int g) {
    return IntMin(a, IntMin(b, IntMin(c, IntMin(d, IntMin(e, IntMin(f, g))));
}

// Define a function to find the maximum of eight integers
int IntMax8(int a, int b, int c, int d, int e, int f, int g, int h) {
    return IntMax(a, IntMax(b, IntMax(c, IntMax(d, IntMax(e, IntMax(f, IntMax(g, h))))));
}

// Define a function to find the minimum of eight integers
int IntMin8(int a, int b, int c, int d, int e, int f, int g, int h) {
    return IntMin(a, IntMin(b, IntMin(c, IntMin(d, IntMin(e, IntMin(f, IntMin(g, h))))));
}

// Define a function to find the maximum of nine integers
int IntMax9(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    return IntMax(a, IntMax(b, IntMax(c, IntMax(d, IntMax(e, IntMax(f, IntMax(g, IntMax(h, i))))))));
}

// Define a function to find the minimum of nine integers
int IntMin9(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    return IntMin(a, IntMin(b, IntMin(c, IntMin(d, IntMin(e, IntMin(f, IntMin(g, IntMin(h, i))))))));
}

// Define a function to find the maximum of ten integers
int IntMax10(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
    return IntMax(a, IntMax(b, IntMax(c, IntMax(d, IntMax(e, IntMax(f, IntMax(g, IntMax(h, IntMax(i, j))))))))));
}

// Define a function to find the minimum of ten integers
int IntMin10(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
    return IntMin(a, IntMin(b, IntMin(c, IntMin(d, IntMin(e, IntMin(f, IntMin(g, IntMin(h, IntMin(i, j))))))))));
}

// Define a function to find the maximum of eleven integers
int IntMax11(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) {
    return IntMax(a, IntMax(b, IntMax(c, IntMax(d, IntMax(e, IntMax(f, IntMax(g, IntMax(h, IntMax(i, IntMax(j, k)))))))))));
}

// Define a function to find the minimum of eleven integers
int IntMin11(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) {
    return IntMin(a, IntMin(b, IntMin(c, IntMin(d, IntMin(e, IntMin(f, IntMin(g, IntMin(h, IntMin(i, IntMin(j, k)))))))))));
}

// Define a function to find the maximum of twelve integers
int IntMax12(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
    return IntMax(a, IntMax(b, IntMax(c, IntMax(d, IntMax(e, IntMax(f, IntMax(g, IntMax(h, IntMax(i, IntMax(j, IntMax(k, l))))))))))))));
}

// Define a function to find the minimum of twelve integers
int IntMin12(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
    return IntMin(a, IntMin(b, IntMin(c, IntMin(d, IntMin(e, IntMin(f, IntMin(g, IntMin(h, IntMin(i, IntMin(j, IntMin(k, l))))))))))))));
}

// Define a function to find the maximum of thirteen integers
int IntMax13(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m) {
    return IntMax(a, IntMax(b, IntMax(c, IntMax(d, IntMax(e, IntMax(f, IntMax(g, IntMax(h, IntMax(i, IntMax(j, IntMax(k, IntMax(l, m)))))))))))))
}

// Define a function to find the minimum of thirteen integers
int IntMin13(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m) {
    return IntMin(a, IntMin(b, IntMin(c, IntMin(d, IntMin(e, IntMin(f, IntMin(g, IntMin(h, IntMin(i, IntMin(j, IntMin(k, IntMin(l, m)))))))))))))
}

// Define a function to find the maximum of fourteen integers
int IntMax14(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n) {
    return IntMax(a, IntMax(b, IntMax(c, IntMax(d, IntMax(e, IntMax(f, IntMax(g, IntMax(h, IntMax(i, IntMax(j, IntMax(k, IntMax(l, IntMax(m, n))))))))))))))
}

// Define a function to find the minimum of fourteen integers
int IntMin14(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n) {
    return IntMin(a, IntMin(b, IntMin(c, IntMin(d, IntMin(e, IntMin(f, IntMin(g, IntMin(h, IntMin(i, IntMin(j, IntMin(k, IntMin(l, IntMin(m, n))))))))))))))
}

// Define a function to find the maximum of fifteen integers
int IntMax15(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o) {
    return IntMax(a, IntMax(b, IntMax(c, IntMax(d, IntMax(e, IntMax(f, IntMax(g, IntMax(h, IntMax(i, IntMax(j, IntMax(k, IntMax(l, IntMax(m, IntMax(n, IntMax(o, 0)))))))));
}

// Define a function to find the minimum of fifteen integers
int IntMin15(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o) {
    return IntMin(a, IntMin(b, IntMin(c, IntMin(d, IntMin(e, IntMin(f, IntMin(g, IntMin(h, IntMin(i, IntMin(j, IntMin(k, IntMin(l, IntMin(m, IntMin(n, IntMin(o, 0)))))))));
}

// Define a function to find the maximum of sixteen integers
int IntMax16(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p) {
    return IntMax(a, IntMax(b, IntMax(c, IntMax(d, IntMax(e, IntMax(f, IntMax(g, IntMax(h, IntMax(i, IntMax(j, IntMax(k, IntMax(l, IntMax(m, IntMax(n, IntMax(o, IntMax(p, 0)))))))));
}

// Define a function to find the minimum of sixteen integers
int IntMin16(int a