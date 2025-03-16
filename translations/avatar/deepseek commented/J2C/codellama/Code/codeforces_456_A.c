
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n; // Declare variable 'n' to store the number of elements
    int *a; // Declare pointer 'a' to store the first set of values
    int *b; // Declare pointer 'b' to store the second set of values
    int temp = 0; // Declare variable 'temp' to temporarily store a value
    int q = 0; // Declare variable 'q' to store a value for comparison
    int w = 0; // Declare variable 'w' to store the maximum value of 'a'
    int e = 0; // Declare variable 'e' to store a value for comparison
    bool f = false; // Declare boolean variable 'f' to determine the output

    // Read the number of elements
    scanf("%d", &n);

    // Initialize array 'a' to store first set of values
    a = (int *) malloc(n * sizeof(int));

    // Initialize array 'b' to store second set of values
    b = (int *) malloc(n * sizeof(int));

    // Loop through each element
    for (int i = 0; i < n; i++) {
        // Read the value for array 'a'
        scanf("%d", &a[i]);

        // Read the value for array 'b'
        scanf("%d", &b[i]);

        // Check if the current 'a' value is greater than the stored 'temp' value
        if (temp < a[i]) {
            // Check if the stored 'q' value is greater than the current 'b' value
            if (q > b[i]) {
                // Set 'f' to true if the condition is met
                f = true;
            }
            // Update 'q' with the current 'b' value
            q = b[i];
            // Update 'temp' with the current 'a' value
            temp = a[i];
        }

        // Check if the current 'a' value is less than the stored 'temp' value
        if (temp > a[i]) {
            // Check if the stored 'q' value is less than the current 'b' value
            if (q < b[i]) {
                // Set 'f' to true if the condition is met
                f = true;
            }
            // Update 'q' with the current 'b' value
            q = b[i];
            // Update 'temp' with the current 'a' value
            temp = a[i];
        }

        // Check if the current 'a' value is greater than the stored 'w' value
        if (a[i] > w) {
            // Update 'w' with the current 'a' value
            w = a[i];
            // Check if the current 'b' value is less than the stored 'e' value
            if (b[i] < e) {
                // Set 'f' to true if the condition is met
                f = true;
            }
            // Update 'e' with the current 'b' value
            e = b[i];
        }

        // Check if the current 'a' value is less than the stored 'w' value
        if (a[i] < w) {
            // Check if the current 'b' value is greater than the stored 'e' value
            if (b[i] > e) {
                // Set 'f' to true if the condition is met
                f = true;
            }
        }
    }

    // Determine and print the output based on the value of 'f'
    if (f == true) {
        printf("Happy Alex\n"); // Print "Happy Alex" if 'f' is true
    } else {
        printf("Poor Alex\n"); // Print "Poor Alex" if 'f' is false
    }

    // Free the memory allocated for arrays 'a' and 'b'
    free(a);
    free(b);

    return 0;
}

