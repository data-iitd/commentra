#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Take the number of elements in the list as input
    int n;
    std::cin >> n;

    // Initialize a vector 'l' to store the input elements
    std::vector<int> l(n);

    // Read the list elements from the standard input
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];
    }

    // Initialize variables 'high' and 'tower' with initial values
    int high = 1;
    int tower = n;
    int maximum = 1; // Initialize maximum to 1

    // Iterate through the list starting from the second element
    for (int i = 1; i < n; ++i) {
        // If the current element is same as the previous one, decrement 'tower' and increment 'high'
        if (l[i] == l[i - 1]) {
            tower--;
            high++;
        } 
        // If the current element is different, check if 'high' is greater than the current maximum and update it if true
        else {
            if (high > maximum) {
                maximum = high;
            }
            high = 1; // Reset high for the new element
        }
    }

    // Check if the last 'high' value is greater than the current maximum and update it if true
    if (high > maximum) {
        maximum = high;
    }

    // Print the final result
    std::cout << maximum << " " << tower << std::endl;

    return 0;
}

// <END-OF-CODE>
