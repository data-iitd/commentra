#include <iostream>
#include <vector>
#include <limits>

int main() {
    // Declare variables
    std::vector<int> a;
    int n, min = std::numeric_limits<int>::max(), max = std::numeric_limits<int>::min();
    long long sum = 0;

    // Read the number of elements in the array
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    // Resize the vector to hold n elements
    a.resize(n);

    // Initialize a for loop to read elements into the array and calculate sum
    for(int i = 0; i < n; i++) {
        // Read each element into the array
        std::cout << "Enter element " << (i + 1) << ": ";
        std::cin >> a[i];

        // Add the current element to the sum
        sum += a[i];
    }

    // Initialize a for loop to find minimum and maximum elements in the array
    for(int i = 0; i < n; i++) {
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
    }

    // Print the minimum, maximum, and sum
    std::cout << "Minimum element is " << min << std::endl;
    std::cout << "Maximum element is " << max << std::endl;
    std::cout << "Sum of all elements is " << sum << std::endl;

    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
