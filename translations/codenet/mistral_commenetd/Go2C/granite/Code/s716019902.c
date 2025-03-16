
#include <stdio.h>

// Constants
#define mod 998244353
#define facNum 300001

// Main function
int main() {
    // Initialize a new scanner
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    // Read an integer N from the standard input
    int N = 0;
    fscanf(input, "%d", &N);

    // Initialize a variable sum to 0
    int sum = 0;

    // Loop through numbers from 1 to N
    for (int i = 1; i <= N; i++) {
        // If the number is not divisible by 3 or 5, add it to the sum
        if (i % 3!= 0 && i % 5!= 0) {
            sum += i;
        }
    }

    // Print the result to the standard output
    fprintf(output, "%d", sum);

    // Close the input and output files
    fclose(input);
    fclose(output);

    return 0;
}

// I/O
// Helper methods for scanner
int s(FILE *input) {
    // Scan the next token and return it as a string
    char buf[1024];
    fgets(buf, 1024, input);
    return atoi(buf);
}

int i(FILE *input) {
    // Convert the next token to an integer and return it
    int i;
    fscanf(input, "%d", &i);
    return i;
}

float f(FILE *input) {
    // Convert the next token to a float64 and return it
    float f;
    fscanf(input, "%f", &f);
    return f;
}

char *bs(FILE *input) {
    // Return the next token as a byte slice
    char buf[1024];
    fgets(buf, 1024, input);
    return buf;
}

int *is(FILE *input, int n) {
    // Read n integers from the standard input and return them as a slice
    int *res = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = i(input);
    }
    return res;
}

float *fs(FILE *input, int n) {
    // Read n floating-point numbers from the standard input and return them as a slice
    float *res = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        res[i] = f(input);
    }
    return res;
}

// Math functions
int Pow(int a, int n) {
    // Calculate a^n modulo mod
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if ((n & 1) == 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        n = n >> 1;
    }
    return ans;
}

int Gcd(int a, int b) {
    // Calculate the greatest common divisor of a and b
    if (a < b) {
        return Gcd(b, a);
    }
    for (int i = 0; i < b; i++) {
        a, b = b, a % b;
    }
    return a;
}

int min(int a, int b) {
    // Return the minimum of a and b
    if (a < b) {
        return a;
    }
    return b;
}

// Combination function
int combination(int n, int k, int *fac, int *ifac) {
    // Calculate the binomial coefficient (n choose k) modulo mod
    if (n < k || n < 0) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }
    // While n is not 0
    int ans = ifac[k] * ifac[n - k] % mod;
    return ans * fac[n] % mod;
}

// Factorial function
int *factorial() {
    // Calculate and return the factorial of all numbers from 0 to facNum-1
    int *fac = (int *)malloc(facNum * sizeof(int));
    fac[0] = 1;
    int *ifac = (int *)malloc(facNum * sizeof(int));
    ifac[0] = 1;
    for (int i = 1; i < facNum; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
        ifac[i] = ifac[i - 1] * Pow(i, mod - 2) % mod;
    }
    return fac;
}

// Lower bound function
int lowerBound(int *vs, int v) {
    // Calculate the index of the first element in vs that is greater than or equal to v
    int n = 0;
    int m = 0;
    for (int i = 0; i < facNum; i++) {
        if (vs[i] < v) {
            n = (m - n + 1) / 2 + n;
            //m = m
        } else {
            m = n;
            n = n / 2;
        }
    }
    return n;
}

// IntSlice function
int *IntSlice(int n, int init) {
    // Create and initialize a slice of length n with the given initial value
    int *r = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        r[i] = init;
    }
    return r;
}

// 

