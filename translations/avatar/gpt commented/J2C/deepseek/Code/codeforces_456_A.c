#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000 // Define a maximum number of pairs

int main() {
    int n;
    int a[MAX_N], b[MAX_N];
    int temp = 0;
    int q = 0;
    int w = 0;
    int e = 0;
    int f = 0;

    // Read the number of pairs
    scanf("%d", &n);

    // Loop to read pairs of integers
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);

        // Check if the current value in a is greater than the previous maximum
        if (temp < a[i]) {
            // If the current b value is less than the previous b value, set flag to 1
            if (q > b[i]) {
                f = 1;
            }
            // Update q and temp with current values
            q = b[i];
            temp = a[i];
        }
        // Check if the current value in a is less than the previous maximum
        if (temp > a[i]) {
            // If the current b value is greater than the previous b value, set flag to 1
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
            // If the current b value is less than the previous maximum b, set flag to 1
            if (b[i] < e) {
                f = 1;
            }
            e = b[i]; // Update corresponding value in b
        }
        // Check if the current value in a is less than the maximum value
        if (a[i] < w) {
            // If the current b value is greater than the previous maximum b, set flag to 1
            if (b[i] > e) {
                f = 1;
            }
        }
    }

    // Output the result based on the flag value
    if (f == 1) {
        printf("Happy Alex\n"); // Condition met for "Happy Alex"
    } else {
        printf("Poor Alex\n"); // Condition not met, output "Poor Alex"
    }

    return 0;
}
