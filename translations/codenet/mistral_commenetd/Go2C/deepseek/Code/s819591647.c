#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define constMod 1000000007

int getInt() {
    int i;
    scanf("%d", &i);
    return i;
}

int* getIntSlice(int n) {
    int* ns = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }
    return ns;
}

char* getString() {
    char* line = NULL;
    size_t len = 0;
    if (getline(&line, &len, stdin) == -1) {
        free(line);
        return NULL;
    }
    return line;
}

char** getStringSlice(int n) {
    char** ss = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        ss[i] = getString();
    }
    return ss;
}

char*** getStringDoubleSlice(int m, int n) {
    char*** sds = (char***)malloc(m * sizeof(char**));
    for (int i = 0; i < m; i++) {
        sds[i] = getStringSlice(n);
    }
    return sds;
}

int* sortIntSlice(int* ns, int n) {
    qsort(ns, n, sizeof(int), (int (*)(const void*, const void*))compareInt);
    return ns;
}

int* sortIntReverseSlice(int* ns, int n) {
    qsort(ns, n, sizeof(int), (int (*)(const void*, const void*))reverseCompareInt);
    return ns;
}

int numAbs(int x) {
    return abs(x);
}

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
    int* frac = (int*)malloc((n + 1) * sizeof(int));
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

void solve() {
    int n = getInt();
    int m = getInt();
    int* a = getIntSlice(n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        double rate = (double)sum / (4 * m);
        if ((double)a[i] >= rate) {
            count++;
        }
    }

    if (count >= m) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    free(a);
}

int compareInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int reverseCompareInt(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    solve();
    return 0;
}

