
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RemRing {
    long module;
} RemRing;

RemRing* RemRing_new(long module) {
    RemRing* ring = (RemRing*)malloc(sizeof(RemRing));
    ring->module = module;
    return ring;
}

long RemRing_sum(RemRing* ring, long a, long b) {
    return (a + b + ring->module) % ring->module;
}

long RemRing_sub(RemRing* ring, long a, long b) {
    return (a - b + ring->module) % ring->module;
}

long RemRing_prod(RemRing* ring, long a, long b) {
    return (a * b) % ring->module;
}

long RemRing_div(RemRing* ring, long a, long b) {
    return (a * RemRing_inv(ring, b)) % ring->module;
}

long RemRing_inv(RemRing* ring, long a) {
    long b = ring->module;
    long u = 1;
    long v = 0;
    while (b > 0) {
        long t = a / b;
        a -= t * b;
        u -= t * v;
        long z = a;
        a = b;
        b = z;
        z = u;
        u = v;
        v = z;
    }
    u %= ring->module;
    if (u < 0) u += ring->module;
    return u;
}

int main() {
    char c;
    scanf("%c", &c);
    RemRing* ring = RemRing_new(256);
    printf("%c\n", (char)RemRing_sum(ring, c, 1));
    return 0;
}
// END-OF-CODE