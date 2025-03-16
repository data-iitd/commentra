#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<double> arr;
    double x;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        if (std::floor(x) != x) {
            arr.push_back(x - std::floor(x));
        }
    }

    std::sort(arr.begin(), arr.end());

    int o = 2 * n - arr.size();

    double arr_sum = 0.0;
    for (double x : arr) {
        arr_sum += x;
    }

    double res = 2e9;

    for (int i = 0; i <= n; ++i) {
        if (i + o >= n) {
            res = std::min(res, std::abs(i - arr_sum));
        }
    }

    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << res << std::endl;

    return 0;
}
