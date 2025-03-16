#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

int main() {
    // Take an integer input 'n' from the user
    int n;
    std::cin >> n;

    // Take 'n' floating point numbers as input and store them in a vector 'arr'
    std::vector<double> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Filter out the integers from the vector 'arr' and store the remaining floating point numbers
    std::vector<double> filtered;
    for (double x : arr) {
        double fractional_part = x - static_cast<int>(x);
        if (fractional_part != 0) {
            filtered.push_back(fractional_part);
        }
    }

    // Sort the filtered vector
    std::sort(filtered.begin(), filtered.end());

    // Calculate the length of the filtered vector and assign it to the variable 'o'
    int o = 2 * n - filtered.size();

    // Calculate the sum of all the floating point numbers in the vector 'filtered'
    double arr_sum = 0;
    for (double x : filtered) {
        arr_sum += x;
    }

    // Initialize the variable 'res' with a large integer value
    double res = 2e9;

    // Iterate through the range from 0 to n+1
    for (int i = 0; i <= n; ++i) {
        // Check if the index 'i' plus the offset 'o' is greater than or equal to 'n'
        if (i + o >= n) {
            // Update the minimum value of 'res' with the absolute difference between 'i' and 'arr_sum'
            res = std::min(res, std::abs(i - arr_sum));
        }
    }

    // Print the result with three decimal places
    std::cout << std::fixed << std::setprecision(3) << res << std::endl;

    return 0;
}

// <END-OF-CODE>
