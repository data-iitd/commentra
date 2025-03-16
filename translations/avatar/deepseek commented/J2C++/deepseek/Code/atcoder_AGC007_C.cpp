#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

int main() {
    double N, d, x;
    std::cin >> N >> d >> x;

    double ans = 0.0;

    while (N > 0.5) {
        double adnum = d + x * (N - 0.5);
        ans += adnum;

        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        x = (1.0 + (2.0 / N)) * x;

        --N;
    }

    std::cout << std::setprecision(20) << ans << std::endl;

    return 0;
}

