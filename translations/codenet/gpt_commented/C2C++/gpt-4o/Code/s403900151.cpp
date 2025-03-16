#include <iostream>
#include <vector>

int main() {
    // Declare variables for input values and loop counters
    int n, r, p, c;

    // Infinite loop to continuously accept input until a termination condition is met
    while (true) {
        // Read the values of n (number of elements) and r (number of operations)
        std::cin >> n >> r;

        // Check for termination condition: if both n and r are zero, exit the loop
        if (n == 0 && r == 0)
            break;

        // Initialize vector a with values from 1 to n
        std::vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = i + 1;

        // Process each operation
        for (int i = 0; i < r; i++) {
            // Read the values of p (number of elements to move) and c (number of elements to copy)
            std::cin >> p >> c;

            // Temporary vector b to hold the elements that will be moved
            std::vector<int> b(c);
            for (int j = 0; j < c; j++)
                b[j] = a[n - p - c + 1 + j]; // Copy elements from a to b

            // Shift elements in vector a to make space for the new elements
            for (int j = 0; j < p - 1; j++)
                a[n - p - c + 1 + j] = a[n - p + j + 1]; // Move elements to the left

            // Insert the copied elements from b back into vector a
            for (int j = n - p - c + 1 + p - 1, k = 0; k < c; j++, k++) {
                a[j] = b[k]; // Place elements from b into the correct position in a
            }

            /*
            Uncomment the following lines to debug and print the current state of vector a
            for (int j = 0; j < n; j++)
                std::cout << a[j] << std::endl;
            std::cout << "---" << std::endl;
            */
        }

        // Print the last element of vector a after all operations are completed
        std::cout << a[n - 1] << std::endl;
    }

    return 0; // End of the program
}

// <END-OF-CODE>
