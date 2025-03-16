#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;  // Read the number of elements in the list
    std::vector<int> lst(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> lst[i];  // Read the list of integers
    }
    
    std::sort(lst.begin(), lst.end(), std::greater<int>());  // Sort the list in descending order

    // Initialize a counter for odd numbers
    int od = 0;
    for (int i = 0; i < n; ++i) {
        if (lst[i] & 1) {  // Check if the number is odd
            od++;
        }
    }

    // Initialize sum to accumulate the result
    int sum = 0;
    bool ok = false;  // Initialize a flag to track if an odd number has been added

    // Iterate through the list to process each number
    for (int i = 0; i < n; ++i) {
        if (lst[i] % 2 == 0) {  // Check if the number is even
            sum += lst[i];  // Add even numbers to sum
        } else {
            if (ok || od > 1) {  // Check if an odd number can be added
                sum += lst[i];  // Add odd number to sum
                od--;  // Decrement the count of odd numbers
                ok = !ok;  // Toggle the flag
            }
        }
    }

    std::cout << sum << std::endl;  // Print the final sum
    return 0;
}  // <END-OF-CODE>
