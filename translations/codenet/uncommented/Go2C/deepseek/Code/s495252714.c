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
        scanf("%d", &res[i]);
    }
    return res;
}

char* scanText() {
    char* buffer = (char*)malloc(100 * sizeof(char));
    scanf("%s", buffer);
    return buffer;
}

void printInts(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    int n = scanInt();
    int* c = scanInts(n);
    qsort(c, n, sizeof(int), compare);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + (n + 1 - i) * c[i] % MOD) % MOD;
    }

    printf("%lld\n", ans * modpow(4, n - 1) % MOD);

    free(c);
    return 0;
}

