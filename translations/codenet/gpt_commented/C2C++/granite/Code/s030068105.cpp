
#include <iostream>
#include <cstdlib>

int main() {
    // Declare variables for the number of elements and a pointer for dynamic array allocation
    int n;
    int *data;

    // Read the number of elements from user input
    std::cin >> n;

    // Allocate memory for 'n' integers
    data = (int*)malloc(sizeof(int) * n);

    // Read 'n' integers from user input into the allocated array
    for(int i = 0; i < n; i++) {
        std::cin >> data[i];
    }

    // Initialize variables to find the maximum value and its index
    int max = 0, index;

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
        if(i!= index) {
            a += data[i];
        }
    }

    // Compare the sum of the other elements with the maximum value and print the result
    if(a > max) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    // Free the allocated memory
    free(data);

    return 0;
}
