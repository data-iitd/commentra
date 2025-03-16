#include <iostream>
#include <string>
#include <sstream>

int main() {
    long long A, B, K;
    long long x, y;

    std::cin >> A >> B >> K;

    x = A;
    y = B;
    x = A - K;
    if (x < 0) {
        y = B + x;
        x = 0;
        if (y < 0) {
            y = 0;
        }
    }

    std::cout << x << " " << y << std::endl;

    return 0;
}

