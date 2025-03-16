#include <iostream>
#include <vector>

int main() {
    // Declare a variable for the number of elements and a vector for dynamic array allocation
    int n;
    std::vector<int> data;

    // Read the number of elements from user input
    std::cin >> n;

    // Resize the vector to hold 'n' integers
    data.resize(n);

    // Read 'n' integers from user input into the vector
    for(int i = 0; i < n; i++) {
        std::cin >> data[i];
    }

    // Initialize variables to find the maximum value and its index
    int max = 0, index = -1;

    // Find the maximum value in the array and its index
    for(int i = 0; i < n; i++) {
        if(data[i] > max) {
            max = data[i];
            index = i;
        }
    }

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

// <END-OF-CODE>
