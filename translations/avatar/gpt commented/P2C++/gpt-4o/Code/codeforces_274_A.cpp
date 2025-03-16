#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    // Read two integers from input: num (number of elements) and k (the divisor)
    int num, k;
    std::cin >> num >> k;

    // Read the array of integers from input
    std::vector<int> arr(num);
    for (int i = 0; i < num; ++i) {
        std::cin >> arr[i];
    }

    // Initialize a set to keep track of unique elements that meet the criteria
    std::set<int> different;

    // Initialize a variable to keep track of the maximum size of the 'different' set
    int temp = 0;

    // Sort the array to process elements in ascending order
    std::sort(arr.begin(), arr.end());

    // Iterate through each element in the sorted array
    for (int x : arr) {
        // Check if the element is not divisible by k or if its quotient is not already in the 'different' set
        if (x % k != 0 || different.find(x / k) == different.end()) {
            // Add the element to the 'different' set since it meets the criteria
            different.insert(x);
        }

        // Update the maximum size of the 'different' set if the current size is larger
        temp = std::max(static_cast<int>(different.size()), temp);
    }

    // Print the maximum size of the 'different' set found
    std::cout << temp << std::endl;

    return 0;
}

// <END-OF-CODE>
