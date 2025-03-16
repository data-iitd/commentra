#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

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
    char* line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);
    return line;
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

int modpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n = scanInt();
    int* c = scanInts(n);
    int ans = 0;

    sortInts(c, n);

    for (int i = 0; i < n; i++) {
        ans = (ans + (n + 1 - i) * c[i] % mod) % mod;
    }

    printf("%d\n", (ans * modpow(4, n - 1)) % mod);

    free(c);
    return 0;
}

