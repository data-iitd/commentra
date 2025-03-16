#include <stdio.h>

long power(long a) {
    long res = 0;
    while (a > 0) {
        res++;
        a = a / 10;
    }
    return res;
}

long mult(long a) {
    long pow = power(a);
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

    res = mult(l) > res ? mult(l) : res;
    res = mult(r) > res ? mult(r) : res;
    temp = 0;

    for (int i = 0; i < 10; ++i) {
        temp = temp * 10 + 9;
        if (l <= temp / 2 && temp / 2 <= r) {
            res = maxxes[i] > res ? maxxes[i] : res;
        }
    }

    printf("%ld\n", res);
    return 0;
}

// <END-OF-CODE>
