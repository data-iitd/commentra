#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;  // Input the number of elements (n)
    std::vector<double> arr(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];  // Input the array elements
    }

    // Extract fractional parts and sort them
    std::vector<double> fractional_parts;
    for (const auto& x : arr) {
        double fractional = x - std::floor(x);
        if (fractional != 0) {
            fractional_parts.push_back(fractional);
        }
    }

    std::sort(fractional_parts.begin(), fractional_parts.end());

    // Calculate the number of elements to be added to make the total number of elements equal to 2 * n
    int o = 2 * n - fractional_parts.size();

    // Sum of the sorted fractional parts
    double arr_sum = 0.0;
    for (const auto& x : fractional_parts) {
        arr_sum += x;
    }

    // Initialize the result variable to a very large number
    double res = 2e9;

    // Iterate to find the best position
    for (int i = 0; i <= n; ++i) {
        if (i + o >= n) {
            res = std::min(res, std::abs(i - arr_sum));
        }
    }

    // Print the result with three decimal places
    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << res << std::endl;

    return 0;
}
