#include <iostream>
#include <vector>

int main() {
    int n; // Declare an integer variable 'n' to store the number of elements in the array

    // Read the number of elements from the user
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    // Allocate a vector to store the elements
    std::vector<int> data(n);

    // Read each element of the array from the user
    for(int i = 0; i < n; i++) {
        std::cout << "Enter element " << (i + 1) << ": ";
        std::cin >> data[i];
    }

    int max = 0; // Initialize 'max' variable to store the maximum element
    int index; // Initialize 'index' variable to store the index of the maximum element

    // Find the maximum element and its index
    for(int i = 0; i < n; i++) {
        if(data[i] > max) {
            max = data[i];
            index = i;
        }
    }

    int a = 0; // Initialize 'a' variable to store the sum of all elements except the maximum

    // Calculate the sum of all elements except the maximum
    for(int i = 0; i < n; i++) {
        if(i != index) a += data[i];
    }

    // Check if the sum of all elements except the maximum is greater than the maximum
    if(a > max) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
