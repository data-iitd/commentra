#include <iostream>

using namespace std;

int main(void) {
    // Declare variables for input values and loop counters
    int n, r, p, c;
    int i, j, k, l;
    int a[51], b[51]; // Arrays to hold values

    // Infinite loop to continuously accept input until a termination condition is met
    while (1) {
        // Read the values of n (number of elements) and r (number of operations)
        cin >> n >> r;
        
        // Check for termination condition: if both n and r are zero, exit the loop
        if (!n &&!r)
            break;

        // Initialize array a with values from 1 to n
        for (i = 0; i < n; i++)
            a[i] = i + 1;

        // Process each operation
        for (i = 0; i < r; i++) {
            // Read the values of p (number of elements to move) and c (number of elements to copy)
            cin >> p >> c;

            // Temporary array b to hold the elements that will be moved
            for (j = 0; j < c; j++)
                b[j] = a[n - p - c + 1 + j]; // Copy elements from a to b

            // Shift elements in array a to make space for the new elements
            for (j = 0; j < p - 1; j++)
                a[n - p - c + 1 + j] = a[n - p + j + 1]; // Move elements to the left

            // Insert the copied elements from b back into array a
            for (j = n - p - c + 1 + j, k = 0; k < c; j++, k++) {
                a[j] = b[k]; // Place elements from b into the correct position in a
            }

            /*
            Uncomment the following lines to debug and print the current state of array a
            for (j = 0; j < n; j++)
                cout << a[j] << endl;
            cout << "---" << endl;
            */
        }

        // Print the last element of array a after all operations are completed
        cout << a[n - 1] << endl;
    }
    
    return 0; // End of the program
}
