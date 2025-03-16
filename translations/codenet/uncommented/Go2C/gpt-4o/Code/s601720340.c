#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAGIC 1000000007
#define MAX_N 200000

int N;
int p[MAX_N];

int find(int n) {
    for (int i = 0; i < N; i++) {
        if (n == p[i]) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    int X;
    scanf("%d", &X);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &p[i]);
    }

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

int main() {
    solve();
    return 0;
}

// Libraries

// Function to calculate the minimum of two integers
int intMin(int a, int b) {
    return (a < b) ? a : b;
}

// Function to calculate the maximum of two integers
int intMax(int a, int b) {
    return (a > b) ? a : b;
}

// Direct calculation of combination
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

// Calculate combination modulo based on Lucas theorem
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

int combMod(int n, int m, int p) {
    return lucas(n, m, p);
}

// Function to calculate the greatest common divisor
int gcd(int a, int b) {
    while (a != 0) {
        int temp = b % a;
        b = a;
        a = temp;
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

int power2(int n) {
    return power2mod(n, MAGIC);
}

// <END-OF-CODE>
