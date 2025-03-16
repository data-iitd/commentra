#include <iostream>
#include <string>
#include <cstdlib>

class RemRing {
private:
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
        long long quotient = a * inv(b);
        return quotient % module;
    }

    long long inv(long long a) {
        long long b = module;
        long long u = 1;
        long long v = 0;

        while (b > 0) {
            long long t = a / b;
            long long z = a;
            a = b;
            b = z % module;
            long long temp = u;
            u = v;
            v = temp - t * v;
        }

        if (u < 0) u += module;

        return u;
    }
};

int main() {
    std::string s;
    std::getline(std::cin, s);
    char result = s[0] + 1;
    std::cout << result << std::endl;

    return 0;
}

