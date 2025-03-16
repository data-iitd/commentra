#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

int main() {
    int N, d, x;
    std::cin >> N >> d >> x;

    auto main_func = [&](int N, int d, int x) -> int {
        int ret = 0;
        while (N > 0) {
            ret += d + (N - 0.5) * x;
            d = d + (d / N) + (5 * x) / (2 * N);
            x += 2 * x / N;
            N -= 1;
        }
        return ret;
    };

    std::cout << main_func(N, d, x) << std::endl;
    return 0;
}
