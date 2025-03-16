#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int scanInt() {
    int a;
    scanf("%d", &a);
    return a;
}

long long scanInt64() {
    long long a;
    scanf("%lld", &a);
    return a;
}

int* scanInts(int n) {
    int* res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = scanInt();
    }
    return res;
}

void printInts(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void sortInts(int* a, int n) {
    qsort(a, n, sizeof(int), (int (*)(const void*, const void*))compare);
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

long long modpow(long long a, long long n) {
    long long res = 1;
    if (n == 0) return res;
    if (n == 1) return a;
    while (n > 1) {
        if (n % 2 == 1) {
            res = res * a % MOD;
            a = a * a % MOD;
            n /= 2;
            res = res * modpow(a, n) % MOD;
        } else {
            a = a * a % MOD;
            n /= 2;
            res = modpow(a, n) % MOD;
        }
    }
    return res;
}

int main() {
    int n = scanInt();
    int* c = scanInts(n);
    int ans = 0;

    sortInts(c, n);

    for (int i = 0; i < n; i++) {
        ans = (ans + (n + 1 - i) * c[i] % MOD) % MOD;
    }

    printf("%lld\n", (long long)ans * modpow(4, n - 1) % MOD);

    free(c);
    return 0;
}

