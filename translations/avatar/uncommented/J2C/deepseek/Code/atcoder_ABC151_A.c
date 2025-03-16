#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);
    printf("%c", s[0] + 1);
    return 0;
}

class RemRing {
    long module;
public:
    RemRing(long module) {
        this->module = module;
    }
    long sum(long a, long b) {
        return (a + b + module) % module;
    }
    long sub(long a, long b) {
        return (a - b + module) % module;
    }
    long prod(long a, long b) {
        return (a * b) % module;
    }
    long div(long a, long b) {
        return (a * inv(b)) % module;
    }
    long inv(long a) {
        long b = this->module;
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
        u %= this->module;
        if (u < 0) u += this->module;
        return u;
    }
};
