#include <stdio.h>

int main() {
    int a[100]; // Declare an array to store the integers
    int n = 0;  // Initialize a variable to store the number of integers
    char ch;    // Declare a character to read the input

    // Read the space-separated integers from the standard input
    while (scanf("%d%c", &a[n], &ch) == 2) {
        n++; // Increment the count of integers
        if (ch == ' ') {
            continue; // Continue reading the next integer
        } else {
            break; // Stop reading if the input ends
        }
    }

    // Iterate over the elements of the array using the index
    for (int i = 0; i < n; i++) {
        // Check if the current value is equal to zero
        if (a[i] == 0) {
            // Print the index of the first zero to the standard output
            printf("%d\n", i + 1);
            // Terminate the loop using the break statement
            break;
        }
    }

    return 0;
}
