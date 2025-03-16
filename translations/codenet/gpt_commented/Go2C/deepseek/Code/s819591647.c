#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007

// Define a constant for modulus operation
const int constMod = 1000000007;

// Initialize scanner and writer for input and output
// (Note: In C, we don't have built-in functions for input/output like in Go)

// -----------------------------------------

// getInt reads a single integer from input
int getInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// getIntSlice reads n integers from input and returns them as a slice
int* getIntSlice(int n) {
    int* ns = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }
    return ns;
}

// getIntDoubleSlice reads m slices of n integers from input and returns them as a 2D array
int** getIntDoubleSlice(int m, int n) {
    int** nds = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        nds[i] = getIntSlice(n);
    }
    return nds;
}

// getString reads a single string from input
char* getString() {
    char* buffer = (char*)malloc(100 * sizeof(char));
    scanf("%s", buffer);
    return buffer;
}

// getStringSlice reads n strings from input and returns them as a array of strings
char** getStringSlice(int n) {
    char** ss = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        ss[i] = getString();
    }
    return ss;
}

// getStringDoubleSlice reads m slices of n strings from input and returns them as a 2D array of strings
char*** getStringDoubleSlice(int m, int n) {
    char*** sds = (char***)malloc(m * sizeof(char**));
    for (int i = 0; i < m; i++) {
        sds[i] = getStringSlice(n);
    }
    return sds;
}

// -----------------------------------------

// Sort Functions

// sortIntSlice sorts a slice of integers in ascending order
void sortIntSlice(int* ns, int n) {
    qsort(ns, n, sizeof(int), (int (*)(const void*, const void*))compareInt);
}

// sortIntReverseSlice sorts a slice of integers in descending order
void sortIntReverseSlice(int* ns, int n) {
    qsort(ns, n, sizeof(int), (int (*)(const void*, const void*))reverseCompareInt);
}

// -----------------------------------------

// Number Functions

// numAbs returns the absolute value of an integer x
int numAbs(int x) {
    return (x < 0) ? -x : x;
}

// numModPow computes a^n % m using modular exponentiation
int numModPow(int a, int n, int m) {
    int result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        n >>= 1;
    }
    return result;
}

// numGcd computes the greatest common divisor of a and b
int numGcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// numLcm computes the least common multiple of a and b
int numLcm(int a, int b) {
    return a * b / numGcd(a, b);
}

// numModInv computes the modular inverse of a under modulo p
int numModInv(int a, int p) {
    if (a == 1) {
        return 1;
    }
    return p - numModInv(p % a, p) * (p / a) % p;
}

// numModFrac computes factorials modulo constMod up to n
int* numModFrac(int n) {
    int* frac = (int*)malloc((n + 1) * sizeof(int));
    frac[0] = 1;
    for (int i = 1; i <= n; i++) {
        frac[i] = i * frac[i - 1] % constMod;
    }
    return frac;
}

// numModConb computes nCr % constMod using precomputed factorials
int numModConb(int n, int r, int* frac) {
    return (frac[n] / ((frac[n - r] * frac[r]) % constMod)) % constMod;
}

// -----------------------------------------

// solve function implements the main logic of the problem
void solve() {
    // Read n and m from input
    int n = getInt();
    int m = getInt();
    // Read n integers into array a
    int* a = getIntSlice(n);

    // Calculate the sum of all elements in a
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    // Count how many elements in a meet the required rate
    int count = 0;
    for (int i = 0; i < n; i++) {
        double rate = (double)sum / (4 * m);
        if ((double)a[i] >= rate) {
            count++;
        }
    }

    // Output "Yes" if count is greater than or equal to m, otherwise "No"
    if (count >= m) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // Free allocated memory
    free(a);
}

// -----------------------------------------

// main function initializes the program and calls solve
int main() {
    // Call the solve function to execute the main logic
    solve();
    return 0;
}

