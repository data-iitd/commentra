#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element

int main() {
    // Declare variables for the number of elements and a vector for dynamic array allocation
    int n;
    std::vector<int> data;

    // Read the number of elements from user input
    std::cin >> n;

    // Allocate memory for 'n' integers
    data.resize(n);

    // Read 'n' integers from user input into the allocated array
    for(int i = 0; i < n; i++) {
        std::cin >> data[i];
    }

    // Find the maximum value in the array and its index
    int max = *std::max_element(data.begin(), data.end());
    int index = std::distance(data.begin(), std::max_element(data.begin(), data.end()));

    // Initialize a variable to calculate the sum of all elements except the maximum
    int a = 0;

    // Calculate the sum of all elements excluding the maximum value
    for(int i = 0; i < n; i++) {
        if(i != index) {
            a += data[i];
        }
    }

    // Compare the sum of the other elements with the maximum value and print the result
    if(a > max) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
