#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<double> arr;
    for (int i = 0; i < n; ++i) {
        double num;
        std::cin >> num;
        arr.push_back(num);
    }

    std::vector<double> filtered_arr;
    for (const auto& num : arr) {
        if (std::fmod(num, 1) != 0) {
            filtered_arr.push_back(std::fmod(num, 1));
        }
    }

    std::sort(filtered_arr.begin(), filtered_arr.end());

    int o = 2 * n - filtered_arr.size();

    double arr_sum = 0;
    for (const auto& num : filtered_arr) {
        arr_sum += num;
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

