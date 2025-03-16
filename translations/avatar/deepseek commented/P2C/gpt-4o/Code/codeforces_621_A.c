#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a;  // Sort in descending order
}

int main() {
    int n;
    scanf("%d", &n);  // Read the number of elements in the list
    int *lst = (int *)malloc(n * sizeof(int));  // Allocate memory for the list

    for (int i = 0; i < n; i++) {
        scanf("%d", &lst[i]);  // Read the list of integers
    }

    qsort(lst, n, sizeof(int), compare);  // Sort the list in descending order

    // Initialize a counter for odd numbers
    int od = 0;
    for (int i = 0; i < n; i++) {
        if (lst[i] % 2 != 0) {  // Check if the number is odd
            od++;
        }
    }

    // Initialize sum to accumulate the result
    int sum = 0;
    int ok = 0;  // Initialize a flag to track if an odd number has been added

    // Iterate through the list to process each number
    for (int i = 0; i < n; i++) {
        if (lst[i] % 2 == 0) {  // Check if the number is even
            sum += lst[i];  // Add even numbers to sum
        } else {
            if (ok || od > 1) {  // Check if an odd number can be added
                sum += lst[i];  // Add odd number to sum
                od--;  // Decrement the count of odd numbers
                ok = !ok;  // Toggle the flag
            }
        }
    }

    printf("%d\n", sum);  // Print the final sum

    free(lst);  // Free the allocated memory
    return 0;
}  // <END-OF-CODE>
