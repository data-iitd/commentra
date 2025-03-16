#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read an integer input for the number of elements
    int n;
    std::cin >> n;

    // Read a list of integers from input
    std::vector<int> lst(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> lst[i];
    }

    // Sort the list in ascending order
    std::sort(lst.begin(), lst.end());

    // Reverse the list to get it in descending order
    std::reverse(lst.begin(), lst.end());

    // Initialize a counter for odd numbers
    int od = 0;

    // Count the number of odd integers in the list
    for (int i = 0; i < n; ++i) {
        if (lst[i] & 1) {  // Check if the number is odd using bitwise AND
            od++;  // Increment the odd counter
        }
    }

    // Initialize variables for sum and a flag to track even number inclusion
    int sum = 0;
    bool ok = false;

    // Iterate through the sorted list to calculate the desired sum
    for (int i = 0; i < n; ++i) {
        if (lst[i] % 2 == 0) {  // Check if the current number is even
            sum += lst[i];  // Add even numbers directly to the sum
        } else {
            // If we have already included an odd number or there is more than one odd number left
            if (ok || od > 1) {
                sum += lst[i];  // Add the odd number to the sum
                od--;  // Decrement the odd counter
                ok = !ok;  // Toggle the flag to indicate an odd number has been included
            }
        }
    }

    // Print the final calculated sum
    std::cout << sum << std::endl;

    return 0;
}

// <END-OF-CODE>
