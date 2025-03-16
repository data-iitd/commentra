#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Create a variable to read input from the user
    int n;
    
    // Read the number of elements in the array
    std::cin >> n;
    
    // Initialize a vector to store the input values
    std::vector<int> a(n);
    
    // Loop to read n integers from the user and store them in the vector
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    // Sort the vector in ascending order
    std::sort(a.begin(), a.end());
    
    // Store the minimum value from the sorted vector
    int min = a[0];
    
    // Check if all elements in the vector are divisible by the minimum value
    for (int value : a) {
        if (value % min != 0) {
            // If any element is not divisible, print -1 and exit
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    
    // If all elements are divisible, print the minimum value
    std::cout << min << std::endl;
    
    return 0;
}

// <END-OF-CODE>
