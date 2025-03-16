

#include <iostream>

// Function to calculate the maximum sum of elements to the left of a given index
int maxLeft(int n) {
    // Return the maximum left sum, which is the sum of elements from index 0 to the given index - 2
    return n > 2? n - 2 : 0;
}

int main() {
    int t; // Number of test cases
    std::cin >> t; // Read the number of test cases from the input

    while (t--) {
        int n; // Number of elements in the array
        std::cin >> n; // Read the number of elements in the array

        // Print the maximum left sum
        std::cout << maxLeft(n) << std::endl;
    }

    return 0;
}

