
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long long a;
    long long b;
} pair;

pair maxProduct(pair a, pair b) {
    if (a.a * a.b > b.a * b.b) {
        return a;
    } else {
        return b;
    }
}

pair maxProduct(pair a, pair b, pair c) {
    return maxProduct(maxProduct(a, b), c);
}

pair maxProduct(pair a, pair b, pair c, pair d) {
    return maxProduct(maxProduct(a, b, c), d);
}

int main() {
    pair a, b, c, d;
    scanf("%lld %lld %lld %lld", &a.a, &a.b, &b.a, &b.b);
    scanf("%lld %lld %lld %lld", &c.a, &c.b, &d.a, &d.b);
    pair result = maxProduct(a, b, c, d);
    printf("%lld\n", result.a * result.b);
    return 0;
}

