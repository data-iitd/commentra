#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<double> arr(2 * n);
    double sum_before = 0, sum = 0;
    int non_int = 0;

    for (int i = 0; i < 2 * n; i++) {
        double num;
        std::cin >> num;
        sum_before += num;
        if (num != std::floor(num)) non_int++;
        sum += std::floor(num);
        arr[i] = num;
    }

    double max_sum = std::min(n, non_int) + sum;
    double min_sum = std::max(0.0, non_int - n) + sum;
    double ans;

    if (min_sum > sum_before) {
        ans = min_sum - sum_before;
    } else if (max_sum < sum_before) {
        ans = sum_before - max_sum;
    } else {
        double x = sum_before - std::floor(sum_before);
        ans = std::min(1 - x, x);
    }

    std::cout << std::fixed << std::setprecision(3) << ans << "\n";
    return 0;
}

// <END-OF-CODE>
