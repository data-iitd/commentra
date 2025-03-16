#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

const double inf = 10000000000.0;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arrA(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arrA[i];
    }

    std::vector<int> cumSumA(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cumSumA[i + 1] = cumSumA[i] + arrA[i];
    }

    double ans = inf;
    for (int i = 1; i < n; i++) {
        double diff = std::abs(cumSumA[n] - (cumSumA[i] * 2));
        if (diff < ans) {
            ans = diff;
        }
    }

    std::cout << static_cast<int>(ans) << std::endl;

    return 0;
}

// <END-OF-CODE>
