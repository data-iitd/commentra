#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize an array to hold the input values and their remainders
    int a[5];
    int r[5];
    
    // Create an array to store the adjustments and their corresponding values
    int adjustments[5];
    int values[5];
    int adjustmentCount = 0;

    // Read 5 integers from the user and calculate their remainders
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]); // Read input value
        r[i] = a[i] % 10; // Calculate remainder when divided by 10
        
        // Initialize adjustment value
        int b = 10;
        // If the remainder is not zero, calculate the adjustment needed to make it a multiple of 10
        if (r[i] != 0) {
            b = 10 - r[i];
            // Store the adjustment and the original value
            adjustments[adjustmentCount] = b;
            values[adjustmentCount] = a[i];
            adjustmentCount++;
        }
    }

    // Initialize the answer variable to accumulate the result
    int ans = 0;

    // If no adjustments are needed (adjustmentCount is zero), sum all input values
    if (adjustmentCount == 0) {
        for (int i = 0; i < 5; i++) {
            ans += a[i]; // Add all values to the answer
        }
        printf("%d\n", ans); // Print the result
        return 0; // Exit the program
    }

    // Find the largest adjustment and its corresponding value
    int maxAdjustmentIndex = 0;
    for (int i = 1; i < adjustmentCount; i++) {
        if (adjustments[i] > adjustments[maxAdjustmentIndex]) {
            maxAdjustmentIndex = i;
        }
    }
    int last = values[maxAdjustmentIndex];
    
    // Calculate the final answer by adding values, adjusting as necessary
    for (int i = 0; i < 5; i++) {
        if (a[i] != last) { // Skip the last value
            if (a[i] % 10 == 0) {
                ans += a[i]; // If already a multiple of 10, add directly
            } else {
                ans += a[i] + (10 - r[i]); // Adjust to the next multiple of 10
            }
        }
    }

    // Add the last value to the answer
    ans += last;

    // Print the final calculated answer
    printf("%d\n", ans);
    
    return 0;
}

// <END-OF-CODE>
