#include <iostream>
#include <vector>

int main() {
    // Declare variables
    int len;
    std::vector<int> a(101);

    // Read the length of the array from the user
    std::cout << "Enter the length of the array: ";
    std::cin >> len;

    // Read the elements of the array from the user
    std::cout << "Enter " << len << " integers: ";
    for (int i = 0; i < len; i++) {
        std::cin >> a[i];
    }

    // Sort the array using insertion sort algorithm
    for (int j = 1; j < len; j++) {
        // Print the current state of the array
        for (int i = 0; i < len; i++) {
            if (i != 0) std::cout << " ";
            std::cout << a[i];
        }
        std::cout << std::endl;

        // Set the current key to the next element
        int key = a[j];

        // Swap the current key with the previous element if it is greater
        int i = j - 1;
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i--;
        }

        // Place the current key in its correct position
        a[i + 1] = key;
    }

    // Print the sorted array
    for (int i = 0; i < len; i++) {
        if (i != 0) std::cout << " ";
        std::cout << a[i];
    }
    std::cout << std::endl;

    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
