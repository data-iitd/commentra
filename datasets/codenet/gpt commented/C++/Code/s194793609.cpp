#include <iostream>
#include <vector>

int main()
{
    // Read the number of elements
    int n;
    std::cin >> n;

    // Initialize a vector to store the input numbers
    std::vector<long long> a(n);
    // Read the input numbers into the vector
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Create a copy of the input vector to store absolute values
    std::vector<long long> abs_a = a;

    // Convert all elements in abs_a to their absolute values
    for (int i = 0; i < n; i++) {
        if (abs_a[i] < 0) {
            abs_a[i] = -abs_a[i];
        }
    }

    // Initialize variables to calculate the sum of absolute values and find the minimum absolute value
    long long ans = 0;
    long long min = abs_a[0];
    // Iterate through the absolute values to calculate the total sum and find the minimum
    for (auto e : abs_a) {
        ans += e; // Accumulate the sum of absolute values
        if (min > e) {
            min = e; // Update the minimum absolute value found
        }
    }

    // Count the number of negative numbers in the original array
    int num_negative = 0;
    for (auto e : a) {
        if (e < 0) {
            num_negative++; // Increment count for each negative number
        }
    }

    // If the count of negative numbers is odd, adjust the total sum
    if (num_negative % 2) {
        ans -= min * 2; // Subtract twice the minimum absolute value from the total sum
    }

    // Output the final result
    std::cout << ans << std::endl;
}
