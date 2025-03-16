#include <iostream>
#include <vector>

int main() {
    // Declare a vector to hold integers and variables for size and counters
    std::vector<int> a(1000);
    int n, d = 0;

    // Read the number of elements to be sorted
    std::cin >> n;

    // Read the elements into the vector
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    // Perform a bubble sort on the vector
    for (int i = 0; i < n; i++) {
        // Inner loop for comparing adjacent elements
        for (int j = n - 1; j >= i + 1; j--) {
            // If the current element is less than the previous one, swap them
            if (a[j] < a[j - 1]) {
                std::swap(a[j], a[j - 1]);
                d++; // Increment the swap counter
            }
        }
    }

    // Print the sorted vector
    std::cout << a[0]; // Print the first element
    for (int i = 1; i < n; i++) {
        std::cout << " " << a[i]; // Print the remaining elements
    }
    
    // Print the total number of swaps made during sorting
    std::cout << "\n" << d << "\n";
    
    return 0; // Return success
}

// <END-OF-CODE>
