#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    // Declare variables
    int n;          // Number of elements in the array
    double avg = 0; // Average of the elements in the array
    double s;       // Difference between the first element and the average
    int ans;        // Index of the element with the maximum difference from the average

    // Read the number of elements from the standard input
    scanf("%d", &n);
    int a[100];     // Declare an array of size 100

    // Calculate the average of the elements in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read an element from the standard input and store it in the array
        avg += a[i];        // Add the current element to the sum of all elements
    }

    // Calculate the average and divide it by the number of elements
    avg /= n;

    // Initialize the difference between the first element and the average
    s = fabs(a[0] - avg);

    // Initialize the index of the element with the maximum difference from the average
    ans = 0;

    // Find the index of the element with the maximum difference from the average
    for (int i = 1; i < n; i++) {
        if (s > fabs(a[i] - avg)) { // If the current difference is greater than the previous difference
            s = fabs(a[i] - avg);   // Update the difference
            ans = i;                // Update the index
        }
    }

    // Print the index of the element with the maximum difference from the average
    printf("%d\n", ans);

    // Terminate the program
    return 0;
}

// <END-OF-CODE>
