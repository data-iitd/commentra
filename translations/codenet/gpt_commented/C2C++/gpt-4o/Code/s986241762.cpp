#include <iostream>
#include <vector>

int main() {
    // Declare variables
    int n; // Number of elements in the array
    long sum = 0; // Variable to store the total sum of differences

    // Read the number of elements from user input
    std::cin >> n;
    
    // Declare a vector of size n
    std::vector<int> a(n);

    // Read n elements into the vector from user input
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Iterate through the vector to calculate the sum of differences
    for (int i = 1; i < n; i++) {
        // Check if the previous element is greater than the current element
        if (a[i - 1] > a[i]) {
            // Calculate the difference and add it to the sum
            sum += a[i - 1] - a[i];
            // Update the current element to be equal to the previous element
            a[i] = a[i - 1];
        }
    }

    // Print the total sum of differences
    std::cout << sum << std::endl;

    return 0;
}

// <END-OF-CODE>
