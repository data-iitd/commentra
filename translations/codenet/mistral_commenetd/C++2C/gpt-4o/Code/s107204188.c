#include <stdio.h>
#include <math.h>

int main(void) {
    // Initialize minimum value of array A to a large number
    int minA = pow(10, 9) + 1;
    int num = 0;
    int f = 0; // Variable to store the previous difference

    // Read number of elements and time t from the standard input
    int n, t;
    scanf("%d %d", &n, &t);

    // Create an array A of size n to store the input elements
    int A[n];

    // Read each element of array A from the standard input
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        // Check if the current element is smaller than the minimum value
        if (minA > A[i]) {
            // Update the minimum value of array A
            minA = A[i];
        } else {
            // Calculate the difference between the current element and the minimum value
            int diff = A[i] - minA;

            // If the difference is equal to the previous difference, increment the count of similar differences
            if (f == diff) {
                num++;
            // If the difference is greater than the previous difference, reset the count to 1 and update the previous difference
            } else if (f < diff) {
                num = 1;
                f = diff;
            }
        }
    }

    // Print the count of similar differences on the standard output
    printf("%d\n", num);

    return 0;
}

// <END-OF-CODE>
