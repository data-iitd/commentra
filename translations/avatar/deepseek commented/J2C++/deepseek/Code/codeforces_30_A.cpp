#include <iostream>
#include <cmath>

int main() {
    int A, B, n;
    std::cin >> A >> B >> n;

    // Step 1: Handling Special Case A == 0
    if (A == 0) {
        if (B == 0)
            std::cout << 1 << std::endl;
        else
            std::cout << "No solution" << std::endl;
        return 0;
    }

    // Step 2: Checking Divisibility
    if (B % A != 0) {
        std::cout << "No solution" << std::endl;
        return 0;
    }

    // Step 3: Normalizing B
    B /= A;
    bool neg = B < 0;
    if (neg && n % 2 == 0) {
        std::cout << "No solution" << std::endl;
        return 0;
    }
    if (neg)
        B = -B;

    // Step 4: Iterating to Find Solution
    for (int x = 0; x <= B; x++) {
        if (std::pow(x, n) == B) {
            std::cout << (neg ? -x : x) << std::endl;
            return 0;
        }
    }

    // Step 5: No Solution Found
    std::cout << "No solution" << std::endl;
    return 0;
}

