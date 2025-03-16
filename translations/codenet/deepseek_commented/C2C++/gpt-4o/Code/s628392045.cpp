#include <iostream> // Include iostream for input/output operations
#include <vector>   // Include vector for dynamic array management

int main() {
    int n; // Declare variable for number of elements
    std::cin >> n; // Read the number of elements from standard input

    std::vector<int> h(n); // Declare a vector to store heights of elements
    int max = -1; // Initialize max to -1 to store the maximum height found
    bool flag = false; // Initialize flag to false to indicate whether the condition is met

    // Loop to read heights and update the maximum height found
    for (int i = 0; i < n; i++) {
        std::cin >> h[i]; // Read the height of the i-th element
        if (max < h[i]) max = h[i]; // Update max if the current height is greater than max

        if (max - h[i] >= 2) flag = true; // Check if the difference between max and current height is at least 2
    }

    if (flag) std::cout << "No\n"; // Print "No" if the condition is met
    else std::cout << "Yes\n"; // Print "Yes" if the condition is not met

    return 0; // Return 0 to indicate successful execution
} // <END-OF-CODE>
