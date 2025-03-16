#include <iostream>
#include <vector>

int main() {
    int n; // Declare an integer variable to store the size of the array
    std::cin >> n; // Read an integer value for n from the standard input

    std::vector<int> data(n); // Create a vector to store n integers

    // Read n integers from the standard input and store them in the vector
    for (int i = 0; i < n; i++) {
        std::cin >> data[i];
    }

    int max = 0, index = 0; // Initialize max to 0 and index to 0 (assuming the first element is the maximum initially)

    // Iterate through the vector to find the maximum value and its index
    for (int i = 0; i < n; i++) {
        if (data[i] > max) {
            max = data[i];
            index = i; // Update the index of the maximum value
        }
    }

    int a = 0; // Initialize a variable to store the sum of elements excluding the maximum value

    // Iterate through the vector again, excluding the element at the index of the maximum value, and sum up the remaining elements
    for (int i = 0; i < n; i++) {
        if (i != index) {
            a += data[i];
        }
    }

    // Compare the sum of the remaining elements (a) with the maximum value (max)
    if (a > max) {
        std::cout << "Yes" << std::endl; // Print "Yes" if the sum of remaining elements is greater than the maximum value
    } else {
        std::cout << "No" << std::endl; // Print "No" otherwise
    }

    return 0;
} // <END-OF-CODE>
