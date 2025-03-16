
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RemRing {
    long module;
};

struct RemRing *RemRing_new(long module) {
    struct RemRing *self = malloc(sizeof(struct RemRing));
    self->module = module;
    return self;
}

long RemRing_sum(struct RemRing *self, long a, long b) {
    return (a + b + self->module) % self->module;
}

long RemRing_sub(struct RemRing *self, long a, long b) {
    return (a - b + self->module) % self->module;
}

long RemRing_prod(struct RemRing *self, long a, long b) {
    return (a * b) % self->module;
}

long RemRing_div(struct RemRing *self, long a, long b) {
    return (a * RemRing_inv(self, b)) % self->module;
}

long RemRing_inv(struct RemRing *self, long a) {
    long b = self->module;
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
    u %= self->module;
    if (u < 0) u += self->module;
    return u;
}

int main(int argc, char *argv[]) {
    struct RemRing *ring = RemRing_new(1000000007);
    char *s = malloc(1000000);
    fgets(s, 1000000, stdin);
    char *sl[1000000];
    sl[0] = strtok(s, " ");
    printf("%c", RemRing_sum(ring, sl[0][0], 1));
    return 0;
}

