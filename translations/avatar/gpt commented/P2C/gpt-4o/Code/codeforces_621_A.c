#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a; // Sort in descending order
}

int main() {
    // Read an integer input for the number of elements
    int n;
    scanf("%d", &n);

    // Read a list of integers from input
    int *lst = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &lst[i]);
    }

    // Sort the list in descending order
    qsort(lst, n, sizeof(int), compare);

    // Initialize a counter for odd numbers
    int od = 0;

    // Count the number of odd integers in the list
    for (int i = 0; i < n; i++) {
        if (lst[i] & 1) {  // Check if the number is odd using bitwise AND
            od++;  // Increment the odd counter
        }
    }

    // Initialize variables for sum and a flag to track even number inclusion
    int sum = 0;
    int ok = 0;

    // Iterate through the sorted list to calculate the desired sum
    for (int i = 0; i < n; i++) {
        if (lst[i] % 2 == 0) {  // Check if the current number is even
            sum += lst[i];  // Add even numbers directly to the sum
        } else {
            // If we have already included an odd number or there is more than one odd number left
            if (ok || od > 1) {
                sum += lst[i];  // Add the odd number to the sum
                od--;  // Decrement the odd counter
                ok = !ok;  // Toggle the flag to indicate an odd number has been included
            }
        }
    }

    // Print the final calculated sum
    printf("%d\n", sum);

    // Free allocated memory
    free(lst);

    return 0;
}

// <END-OF-CODE>
