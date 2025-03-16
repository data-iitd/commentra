#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 200000
#define MAGIC 1000000007

// Function prototypes
int find(int n);
void solve();
void flush();
void logf(const char *format, ...);
int combination(int n, int m);
int lucas(int n, int m, int p);
int combMod(int n, int m, int p);
void bfs(int start, int nodes[MAX_SIZE][MAX_SIZE], int nodeCount, void (*fn)(int));
void dfs(int node, int nodes[MAX_SIZE][MAX_SIZE], int nodeCount, void (*fn)(int));
void dfs2(int node, int nodes[MAX_SIZE][MAX_SIZE], int nodeCount, void (*fn1)(int, int), void (*fn2)(int, int));
int gcd(int a, int b);
int power2mod(int n, int mod);
int power2(int n);
void findDivisors(int n, int *a, int *size);
void removeDuplicate(int *a, int *size);
int abs(int a);

// Global variables
int N;
int p[MAX_SIZE];

<<<<<<< HEAD
// Function to find if a number exists in the array p
=======
// Find checks if a number exists in the array p.
>>>>>>> 98c87cb78a (data updated)
int find(int n) {
    for (int i = 0; i < N; i++) {
        if (n == p[i]) {
            return 0;
        }
    }
    return 1;
}

<<<<<<< HEAD
// Main logic to solve the problem
=======
// Solve is the main function that handles the program logic.
>>>>>>> 98c87cb78a (data updated)
void solve() {
    int X;
    scanf("%d", &X);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &p[i]);
    }

<<<<<<< HEAD
    // Search for the closest number to X in the array p
=======
    // Search for the closest number to X in the array p.
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i <= 100; i++) {
        if (find(X - i) == 1) {
            printf("%d\n", X - i);
            exit(0);
        }
        if (find(X + i) == 1) {
            printf("%d\n", X + i);
            exit(0);
        }
    }
}

<<<<<<< HEAD
// Entry point of the program
int main() {
    solve();
    return 0;
}

// Function to log formatted output
=======
// Main is the entry point of the program.
int main(int argc, char *argv[]) {
    // Profiling flags can be added here if needed

    solve();

    return 0;
}

// Log print formatted output to standard output
>>>>>>> 98c87cb78a (data updated)
void logf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

<<<<<<< HEAD
// Function to calculate combination
=======
// Calculate combination
>>>>>>> 98c87cb78a (data updated)
int combination(int n, int m) {
    if (m > n) {
        return 0;
    } else if (m == n || m == 0) {
        return 1;
    } else {
        int res = 1;
        for (int i = 0; i < m; i++) {
            res *= (n - i);
        }
        for (int i = 1; i <= m; i++) {
            res /= i;
        }
        return res;
    }
}

<<<<<<< HEAD
// Function to calculate combination modulo based on Lucas theorem
=======
// Calculate combination modulo based on Lucas theorem
>>>>>>> 98c87cb78a (data updated)
int lucas(int n, int m, int p) {
    int ntemp = n;
    int mtemp = m;
    int res = 1;
    for (int i = 0; i < 100; i++) {
        int nreminder = ntemp % p;
        ntemp = ntemp / p;
        int mreminder = mtemp % p;
        mtemp = mtemp / p;
        res = res * (combination(nreminder, mreminder) % p);
        if (ntemp == 0) {
            break;
        }
    }
    return res % p;
}

<<<<<<< HEAD
// Function to calculate combination modulo
=======
>>>>>>> 98c87cb78a (data updated)
int combMod(int n, int m, int p) {
    return lucas(n, m, p);
}

<<<<<<< HEAD
// Function to find divisors
=======
// GCD function
int gcd(int a, int b) {
    while (a != 0) {
        int t = b % a;
        b = a;
        a = t;
    }
    return b;
}

// Power of 2 modulo
int power2mod(int n, int mod) {
    int res = 1, x = 2;
    while (n > 0) {
        if (n & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int power2(int n) {
    return power2mod(n, MAGIC);
}

// Find divisors
>>>>>>> 98c87cb78a (data updated)
void findDivisors(int n, int *a, int *size) {
    if (n == 1) {
        return;
    }

<<<<<<< HEAD
    int sqrtN = (int)sqrt((double)n);
=======
    int sqrtN = (int)sqrt(n);
>>>>>>> 98c87cb78a (data updated)
    for (int i = 2; i <= sqrtN; i++) {
        if (n % i == 0) {
            a[(*size)++] = i;
            a[(*size)++] = n / i;
        }
    }
    a[(*size)++] = n;
}

<<<<<<< HEAD
// Function to remove duplicates from an array
=======
// Remove duplicates from an array
>>>>>>> 98c87cb78a (data updated)
void removeDuplicate(int *a, int *size) {
    int m[MAX_SIZE] = {0};
    for (int i = 0; i < *size; i++) {
        m[a[i]] = 1;
    }
    *size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (m[i]) {
            a[(*size)++] = i;
        }
    }
}

<<<<<<< HEAD
// Function to calculate absolute value
=======
// Absolute value function
>>>>>>> 98c87cb78a (data updated)
int abs(int a) {
    return a > 0 ? a : -a;
}

<<<<<<< HEAD
// Function to calculate gcd
int gcd(int a, int b) {
    while (a != 0) {
        int t = b % a;
        b = a;
        a = t;
    }
    return b;
}

// Function to calculate power of 2 modulo
int power2mod(int n, int mod) {
    int res = 1, x = 2;
    while (n > 0) {
        if (n & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

// Function to calculate power of 2
int power2(int n) {
    return power2mod(n, MAGIC);
}
=======
>>>>>>> 98c87cb78a (data updated)
