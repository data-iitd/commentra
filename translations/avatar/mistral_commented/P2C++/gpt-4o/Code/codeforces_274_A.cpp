#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    // Take the first line of input which are two integers 'num' and 'k'
    int num, k;
    std::cin >> num >> k;

    // Comment: Initialize 'num' and 'k' with the values from user input

    // Take the second line of input which is a list 'arr' of integers
    std::vector<int> arr(num);
    for (int i = 0; i < num; ++i) {
        std::cin >> arr[i];
    }

    // Comment: Initialize an empty list 'arr' to store the input integers

    // Create an empty set 'different' to store unique integers
    std::set<int> different;

    // Comment: Initialize an empty set 'different' to store unique integers

    // Sort the list 'arr' in ascending order
    std::sort(arr.begin(), arr.end());

    // Comment: Sort the list 'arr' in ascending order for easier comparison

    // Initialize a variable to keep track of the maximum length of 'different'
    int temp = 0;

    // Iterate through each integer 'x' in the sorted list 'arr'
    for (int x : arr) {
        // Check if 'x' is not divisible by 'k' or if its quotient is not already in 'different'
        if (x % k != 0 || different.find(x / k) == different.end()) {
            // If the condition is true, add 'x' to the set 'different'
            different.insert(x);

            // Comment: If 'x' is not divisible by 'k' or its quotient is not already in 'different', add it to 'different'
        }

        // Update the maximum length of 'different' seen so far
        temp = std::max(static_cast<int>(different.size()), temp);
    }

    // Comment: After the loop, 'temp' stores the maximum length of 'different' seen during the iteration

    // Print the maximum length of 'different'
    std::cout << temp << std::endl;

    // Comment: Finally, print the maximum length of 'different'
    return 0;
}

// <END-OF-CODE>
