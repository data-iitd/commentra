
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define constMod 1000000007

int numAbs(int x) {
    if (x < 0) {
        return -x;
    }

    return x;
}

int numModPow(int a, int n, int m) {
    int result = 1;

    for (n > 0; n > 0; n >>= 1) {
        if (n % 2 == 1) {
            result = (result * a) % m;
        }

        a = (a * a) % m;
    }

    return result;
}

int numGcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return numGcd(b, a % b);
}

int numLcm(int a, int b) {
    return a * b / numGcd(a, b);
}

int numModInv(int a, int p) {
    if (a == 1) {
        return 1;
    }

    return p - numModInv(p % a, p) * (p / a) % p;
}

int* numModFrac(int n) {
    int* frac = (int*)malloc(sizeof(int) * (n + 1));
    frac[0] = 1;

    for (int i = 1; i <= n; i++) {
        frac[i] = i * frac[i - 1] % constMod;
    }

    return frac;
}

int numModConb(int n, int r) {
    int* frac = numModFrac(n);

    return (frac[n] / ((frac[n - r] * frac[r]) % constMod)) % constMod;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* a = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        float rate = (float)sum / (4 * m);
        if ((float)a[i] >= rate) {
            count++;
        }
    }

    if (count >= m) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    free(a);
    free(frac);

    return 0;
}

