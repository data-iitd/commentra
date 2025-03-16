
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    long first;
    long second;
} pair;

pair* createPair(long first, long second) {
    pair* p = (pair*)malloc(sizeof(pair));
    p->first = first;
    p->second = second;
    return p;
}

long modPower(long x, long y, long mod) {
    long res = 1;
    x %= mod;

    if (x == 0) return 0;

    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

int main() {
    long a[4];
    for (int i = 0; i < 4; i++) {
        scanf("%ld", &a[i]);
    }

    long result = max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2])));

    printf("%ld\n", result);
    return 0;
}

