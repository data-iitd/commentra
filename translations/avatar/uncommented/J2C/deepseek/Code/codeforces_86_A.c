#include <stdio.h>
#include <stdlib.h>

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

int main() {
    long l, r;
    scanf("%ld %ld", &l, &r);
    long res = 0;
    long maxxes[10];
    long temp = 0;
    for (int i = 0; i < 10; ++i) {
        temp = temp * 10 + 9;
        maxxes[i] = (temp / 2) * (temp - temp / 2);
    }
    res = (mult(l) > res) ? mult(l) : res;
    res = (mult(r) > res) ? mult(r) : res;
    temp = 0;
    for (int i = 0; i < 10; ++i) {
        temp = temp * 10 + 9;
        if (l <= temp / 2 && temp / 2 <= r) {
            res = (maxxes[i] > res) ? maxxes[i] : res;
        }
    }
    printf("%ld\n", res);
    return 0;
}

