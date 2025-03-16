#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    std::vector<double> arr;
    for (int i = 0; i < n; ++i) {
        double x;
        std::cin >> x;
        arr.push_back(x);
    }

    std::vector<double> fractional_part;
    for (double x : arr) {
        if (std::fmod(x, 1) != 0) {
            fractional_part.push_back(std::fmod(x, 1));
        }
    }

    std::sort(fractional_part.begin(), fractional_part.end());

    int o = 2 * n - fractional_part.size();
    double arr_sum = 0;
    for (double x : fractional_part) {
        arr_sum += x;
    }

    double res = 2e9;
    for (int i = 0; i <= n; ++i) {
        if (i + o >= n) {
            res = std::min(res, std::abs(i - arr_sum));
        }
    }

    std::cout << std::fixed << std::setprecision(3) << res << std::endl;

    return 0;
}
