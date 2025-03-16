
#include <stdio.h>

int main(void) {
    // Declare variables
    int n, a[100], b[100], sum = 0;

    // Read the number of elements
    scanf("%d", &n);

    // Input the first array 'a'
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    // Input the second array 'b' and calculate the sum of positive differences
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]); // Read each element of array 'b'
        
        // Check if the difference between corresponding elements of 'a' and 'b' is positive
        if (a[i] - b[i] > 0) {
            // If positive, add the difference to'sum'
            sum += a[i] - b[i];
        }
    }

    // Output the final sum of positive differences
    printf("%d\n", sum);

    return 0; // Indicate that the program ended successfully
}


