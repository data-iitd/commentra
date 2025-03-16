#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int power(long a) {
    int res = 0;
    while (a > 0) {
        res++;
        a = a / 10;
    }
    return res;
}

long mult(long a) {
    int pow = power(a);
    long max = 0;
    for (int j = 0; j < pow; ++j) {
        max = max * 10 + 9;
    }
    return a * (max - a);
}

int main(int argc, char **argv) {
    long l, r, res = 0, temp = 0;
    long maxxes[10];
    for (int i = 0; i < 10; ++i) {
        temp = temp * 10 + 9;
        maxxes[i] = temp / 2 * (temp - temp / 2);
    }
    scanf("%ld %ld", &l, &r);
    res = l > r? l : r;
    res = mult(res) > res? mult(res) : res;
    for (int i = 0; i < 10; ++i) {
        temp = temp * 10 + 9;
        if (l <= temp / 2 && temp / 2 <= r) {
            res = maxxes[i] > res? maxxes[i] : res;
        }
    }
    printf("%ld\n", res);
    return 0;
}

