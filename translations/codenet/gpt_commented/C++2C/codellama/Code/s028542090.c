#include <stdio.h>

int main(void)
{
    int k; // Variable to hold the number of elements
    unsigned long min, max; // Variables to hold the minimum and maximum values
    scanf("%d", &k); // Read the number of elements

    // Declare an array to hold the input values
    unsigned long a[100100];

    // Read the input values into the array
    for (int i = 0; i < k; i++)
        scanf("%ld", &a[i]);

    // Initialize max and min values
    max = 3; 
    min = 2;

    // Check if the last element is not equal to 2
    if (a[k - 1] != 2) {
        printf("%ld\n", -1); // Output -1 if the condition is met
        return 0; // Exit the program
    }

    // Iterate through the array from the second last element to the first
    for (int i = k - 2; i >= 0; i--) {
        // If the current element is greater than max, output -1
        if (a[i] > max) {
            printf("%ld\n", -1); // Output -1 if the condition is met
            return 0; // Exit the program
        } else {
            // Update max based on the current element
            max = ((max / a[i]) + 1) * a[i] - 1;
            // Adjust min to be a multiple of the current element if necessary
            if (min % a[i] != 0) {
                min = ((min / a[i]) + 1) * a[i];
            }
        }

        // Check if the updated max is less than or equal to min
        if (max <= min) {
            printf("%ld\n", -1); // Output -1 if the condition is met
            return 0; // Exit the program
        }
    }

    // Output the final min and max values
    printf("%ld %ld\n", min, max);

    return 0; // Exit the program successfully
}

