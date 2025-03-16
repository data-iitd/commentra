#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 998244353
#define FAC_NUM 300001

// Math functions
int Pow(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        n = n >> 1;
    }
    return ans;
}

int Gcd(int a, int b) {
    if (a < b) {
        return Gcd(b, a);
    }
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

// Combination function
int combination(int n, int k, int* fac, int* ifac) {
    if (n < k || n < 0) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }
    int ans = ifac[k] * ifac[n-k] % MOD;
    return ans * fac[n] % MOD;
}

// Factorial function
void factorial(int* fac, int* ifac) {
    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i < FAC_NUM; i++) {
        fac[i] = fac[i-1] * i % MOD;
        ifac[i] = ifac[i-1] * Pow(i, MOD-2) % MOD;
    }
}

// Lower bound function
int lowerBound(int* vs, int v, int n) {
    int left = 0, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (vs[mid] < v) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

// IntSlice function
int* IntSlice(int n, int init) {
    int* r = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        r[i] = init;
    }
    return r;
}

// Main function
int main() {
    int N;
    scanf("%d", &N);

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 3 != 0 && i % 5 != 0) {
            sum += i;
        }
    }

    printf("%d\n", sum);
    return 0;
}
