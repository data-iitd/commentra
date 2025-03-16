#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

int main() {
    // Read an integer input for the number of elements
    int n;
    std::cin >> n;

    // Read a line of space-separated floats and convert them to a vector of floats
    std::vector<double> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Calculate the fractional parts of the elements, excluding whole numbers
    std::vector<double> fractional_parts;
    for (double x : arr) {
        double fractional_part = x - static_cast<int>(x);
        if (fractional_part != 0) {
            fractional_parts.push_back(fractional_part);
        }
    }
    std::sort(fractional_parts.begin(), fractional_parts.end());

    // Calculate the number of whole numbers that can be added to the fractional parts
    int o = 2 * n - fractional_parts.size();

    // Calculate the sum of the fractional parts
    double arr_sum = 0;
    for (double x : fractional_parts) {
        arr_sum += x;
    }

    // Initialize the result with a large number
    double res = 2e9;

    // Iterate through possible counts of fractional parts used
    for (int i = 0; i <= n; ++i) {
        // Check if the current count of fractional parts plus whole numbers is sufficient
        if (i + o >= n) {
            // Update the result with the minimum difference found
            res = std::min(res, std::abs(i - arr_sum));
        }
    }

    // Print the result formatted to three decimal places
    std::cout << std::fixed << std::setprecision(3) << res << std::endl;

    return 0;
}

// <END-OF-CODE>
