#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare a static arrayList to hold some data (not used in this code)
    int md[1000000];

    // Create a Scanner object for input
    int n;
    scanf("%d", &n);

    // Initialize two arrays to hold the pairs of integers
    int a[n];
    int b[n];

    // Temporary variables for processing
    int temp = 0; // To track the current maximum value in array a
    int q = 0;    // To track the corresponding value in array b
    int w = 0;    // To track the maximum value in array a
    int e = 0;    // To track the corresponding value in array b
    int f = 0;    // Flag to determine if the condition for "Happy Alex" is met

    // Loop to read pairs of integers into arrays a and b
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read value for array a
        scanf("%d", &b[i]); // Read value for array b

        // Check if the current value in a is greater than the previous maximum
        if (temp < a[i]) {
            // If the current b value is less than the previous b value, set flag to true
            if (q > b[i]) {
                f = 1;
            }
            // Update q and temp with current values
            q = b[i];
            temp = a[i];
        }
        // Check if the current value in a is less than the previous maximum
        if (temp > a[i]) {
            // If the current b value is greater than the previous b value, set flag to true
            if (q < b[i]) {
                f = 1;
            }
            // Update q and temp with current values
            q = b[i];
            temp = a[i];
        }
        // Update the maximum value in a and check conditions for b
        if (a[i] > w) {
            w = a[i]; // Update maximum value in a
            // If the current b value is less than the previous maximum b, set flag to true
            if (b[i] < e) {
                f = 1;
            }
            e = b[i]; // Update corresponding value in b
        }
        // Check if the current value in a is less than the maximum value
        if (a[i] < w) {
            // If the current b value is greater than the previous maximum b, set flag to true
            if (b[i] > e) {
                f = 1;
            }
        }
    }

    // Output the result based on the flag value
    if (f == 1) {
        printf("Happy Alex"); // Condition met for "Happy Alex"
    } else {
        printf("Poor Alex");   // Condition not met, output "Poor Alex"
    }

    return 0;
}

