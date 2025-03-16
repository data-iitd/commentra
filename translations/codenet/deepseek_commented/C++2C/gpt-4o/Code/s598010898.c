#include <stdio.h>  // For printf and scanf

int main(void) {
    int n, a[100], b[100], sum = 0;
    scanf("%d", &n); // Read the number of elements

    // Read n integers into array a
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Read n integers into array b
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        if (a[i] - b[i] > 0) { // Check if a[i] is greater than b[i]
            sum += a[i] - b[i]; // Add the difference to sum
        }
    }

    // Output the sum
    printf("%d\n", sum);
    return 0;
}

// <END-OF-CODE>
