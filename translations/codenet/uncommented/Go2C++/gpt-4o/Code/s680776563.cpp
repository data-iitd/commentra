#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>

class FastScanner {
public:
    FastScanner() : buffer("") {}

    int NextInt() {
        int value;
        std::cin >> value;
        return value;
    }

    std::string Next() {
        std::string value;
        std::cin >> value;
        return value;
    }

    std::string NextLine() {
        std::string line;
        std::getline(std::cin, line);
        return line;
    }

private:
    std::string buffer;
};

int IntMax(int a, int b) {
    return std::max(a, b);
}

int IntMin(int a, int b) {
    return std::min(a, b);
}

int IntGcd(int a, int b) {
    if (b == 0) return a;
    return IntGcd(b, a % b);
}

int IntAbs(int a) {
    return std::abs(a);
}

int main() {
    FastScanner fsc;
    int A = fsc.NextInt();
    int B = fsc.NextInt();
    int C = fsc.NextInt();
    
    if (B - A == C - B) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

//<END-OF-CODE>
