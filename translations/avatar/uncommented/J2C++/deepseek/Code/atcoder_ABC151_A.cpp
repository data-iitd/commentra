#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class RemRing {
    long long module;
public:
    RemRing(long long module) : module(module) {}
    long long sum(long long a, long long b) {
        return (a + b + module) % module;
    }
    long long sub(long long a, long long b) {
        return (a - b + module) % module;
    }
    long long prod(long long a, long long b) {
        return (a * b) % module;
    }
    long long div(long long a, long long b) {
        return (a * inv(b)) % module;
    }
    long long inv(long long a) {
        long long b = this->module;
        long long u = 1;
        long long v = 0;
        while (b > 0) {
            long long t = a / b;
            a -= t * b;
            u -= t * v;
            long long z = a;
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

int main() {
    std::string s;
    std::cin >> s;
    std::cout << char(s[0] + 1);
    return 0;
}

