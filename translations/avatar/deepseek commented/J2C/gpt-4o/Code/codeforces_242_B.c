#include <stdio.h> // Including standard input-output library
#include <limits.h> // Including limits.h for INT_MAX

int main() {
    int n; // Declaring variable n to store the number of elements
    scanf("%d", &n); // Reading the integer value of n

    // Initializing arrays to store the elements
    int a[n], b[n];

    // Initializing variables to track the minimum and maximum values
    int left = INT_MAX, right = 0;

    // Looping through n elements to read and update the arrays and variables
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Reading element into array a
        scanf("%d", &b[i]); // Reading element into array b
        if (a[i] < left) left = a[i]; // Updating left with the minimum value
        if (b[i] > right) right = b[i]; // Updating right with the maximum value
    }

    // Looping through the arrays to find the target element
    for (int i = 0; i < n; i++) {
        if (left == a[i] && right == b[i]) {
            printf("%d\n", i + 1); // Printing the 1-based index of the target element
            return 0; // Returning from the method after finding the target
        }
    }

    // If no such element is found, print -1
    printf("-1\n");
    return 0; // Returning from the main function
}

// <END-OF-CODE>
