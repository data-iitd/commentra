
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables and arrays
    int n, a[100000], b[100000], temp = 0, q = 0, w = 0, e = 0, i;
    int f = 0; // Flag to determine if the condition for "Happy Alex" is met

    // Read the number of pairs (n)
    scanf("%d", &n);

    // Loop to read pairs of integers into arrays a and b
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);

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
