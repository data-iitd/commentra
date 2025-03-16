
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, high, tower, maximum;
    int *l;

    // Read the number of elements from user input
    scanf("%d", &n);

    // Allocate memory for the list of integers
    l = (int*)malloc(n * sizeof(int));

    // Read the list of integers from user input and store them in the allocated memory
    for (i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Initialize variables to track the height of the current tower and the total number of towers
    high = 1;
    tower = n;

    // Initialize the maximum height variable
    maximum = 1;

    // Sort the list of integers to facilitate grouping of identical values
    qsort(l, n, sizeof(int));

    // Iterate through the sorted list starting from the second element
    for (i = 1; i < n; i++) {
        // Check if the current element is the same as the previous one
        if (l[i] == l[i - 1]) {
            // If they are the same, increment the height of the current tower and decrease the tower count
            tower--;
            high++;
        } else {
            // If they are different, check if the current tower's height is greater than the maximum found so far
            if (high > maximum) {
                maximum = high;
            }
            // Reset the height for the new tower
            high = 1;
        }
    }

    // After the loop, check again if the last tower's height is greater than the maximum found
    if (high > maximum) {
        maximum = high;
    }

    // Print the maximum height of the towers and the total number of towers
    printf("%d %d\n", maximum, tower);

    // Free the allocated memory
    free(l);

    return 0;
}
