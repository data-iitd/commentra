#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Step 1: Reading Input
    int n;
    cin >> n; // Read the integer n
    vector<double> arr(2 * n); // Array to store the floating-point numbers
    double sum_before = 0, sum = 0; // Variables to store the sum of all numbers and the sum of their integer parts
    int non_int = 0; // Counter for non-integer values

    for (int i = 0; i < 2 * n; i++) {
        double num;
        cin >> num; // Read each number
        sum_before += num; // Add to the sum of all numbers
        if (num != floor(num)) non_int++; // Increment counter if the number is not an integer
        sum += floor(num); // Add the integer part of the number to the sum of integer parts
        arr[i] = num; // Store the number in the array
    }

    // Step 3: Calculating Results
    double max_sum = min(n, non_int) + sum; // Calculate the maximum possible sum
    double min_sum = max(0.0, non_int - n) + sum; // Calculate the minimum possible sum
    double ans; // Variable to store the result

    if (min_sum > sum_before)
        ans = (min_sum - sum_before); // If the minimum sum is greater than the actual sum
    else if (max_sum < sum_before)
        ans = (sum_before - max_sum); // If the maximum sum is less than the actual sum
    else {
        double x = sum_before - floor(sum_before); // Calculate the fractional part of the sum
        ans = min(1 - x, x); // Find the smallest difference to 0 or 1
    }

    // Step 4: Output
    cout << fixed << setprecision(3) << ans; // Print the result with a precision of three decimal places

    return 0;
}

// <END-OF-CODE>
