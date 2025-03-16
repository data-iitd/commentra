#include <iostream>
#include <algorithm> // Include the algorithm library for std::sort

// Function to compare two integers for sorting in descending order
bool compare(int a, int b) {
    return a > b; // Return true if a is greater than b
}

int main() {
    int array[10]; // Declare an array of 10 integers

    // Iterate through the array to read 10 integers
    for (int i = 0; i < 10; i++) {
        std::cin >> array[i]; // Read an integer from the user and store it in the array
    }

    // Sort the array using the sort algorithm and the compare function
    std::sort(array, array + 10, compare);

    // Iterate through the first three elements of the sorted array
    for (int i = 0; i < 3; i++) {
        std::cout << array[i] << std::endl; // Print the first three sorted integers
    }

    return 0; // Return 0 to indicate successful execution of the program
}

// <END-OF-CODE>
