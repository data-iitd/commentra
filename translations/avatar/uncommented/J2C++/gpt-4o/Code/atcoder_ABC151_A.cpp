#include <iostream>
#include <string>

class RemRing {
    long module;
public:
    RemRing(long module) : module(module) {}

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
            std::swap(a, b);
            std::swap(u, v);
        }
        u %= this->module;
        if (u < 0) u += this->module;
        return u;
    }
};

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << static_cast<char>(s[0] + 1);
    return 0;
}

// <END-OF-CODE>
