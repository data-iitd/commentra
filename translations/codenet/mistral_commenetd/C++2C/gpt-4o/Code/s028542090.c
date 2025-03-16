#include <stdio.h>

unsigned long a[100100]; // An array of size 100100 to store input numbers

int main(void) {
    int k; // Variable to store the number of input numbers
    unsigned long min, max; // Variables to store the minimum and maximum values respectively

    scanf("%d", &k); // Read the number of input numbers from the standard input

    for (int i = 0; i < k; i++) { // Iterate through each input number and read it into the array
        scanf("%lu", &a[i]);
    }

    // Check if the last number in the array is 2
    if (a[k - 1] != 2) {
        printf("-1\n"); // If not, print -1 and exit the program
        return 0;
    }

    // Initialize minimum and maximum values
    max = 3, min = 2;

    // Iterate through the array from the second last number to the first number
    for (int i = k - 2; i >= 0; i--) {
        // If the current number is greater than the maximum value, print -1 and exit the program
        if (a[i] > max) {
            printf("-1\n");
            return 0;
        } else {
            // Update the maximum value based on the current number
            max = ((max / a[i]) + 1) * a[i] - 1;

            // If the current number does not divide the minimum value evenly, update the minimum value
            if (min % a[i] != 0) {
                min = ((min / a[i]) + 1) * a[i];
            }
        }

        // Check if the minimum value is less than or equal to the maximum value
        if (max <= min) {
            printf("-1\n"); // If so, print -1 and exit the program
            return 0;
        }
    }

    // Print the minimum and maximum values
    printf("%lu %lu\n", min, max);

    return 0;
}

// <END-OF-CODE>
