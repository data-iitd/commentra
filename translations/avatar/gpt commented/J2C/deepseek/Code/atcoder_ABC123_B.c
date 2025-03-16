#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[5];
    int r[5];
    int b;
    int ans = 0;
    int idx = 0;

    // Read 5 integers from the user and calculate their remainders
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]); // Read input value
        r[i] = a[i] % 10; // Calculate remainder when divided by 10

        // Initialize adjustment value
        b = 10;
        // If the remainder is not zero, calculate the adjustment needed to make it a multiple of 10
        if (r[i] != 0) {
            b = 10 - r[i];
            // Store the adjustment and the original value in the TreeMap
            // Note: In C, we don't have a TreeMap, so we use a simple array to simulate it
            int adjustments[5] = {0};
            int values[5] = {0};
            int count = 0;
            int found = 0;

            for (int j = 0; j < count; j++) {
                if (adjustments[j] == b) {
                    values[j] = a[i];
                    found = 1;
                    break;
                }
            }
            if (!found) {
                adjustments[count] = b;
                values[count] = a[i];
                count++;
            }
        }
    }

    // If no adjustments are needed, sum all input values
    int needAdjustment = 0;
    for (int i = 0; i < 5; i++) {
        if (r[i] != 0) {
            needAdjustment = 1;
            break;
        }
    }
    if (!needAdjustment) {
        for (int i = 0; i < 5; i++) {
            ans += a[i]; // Add all values to the answer
        }
        printf("%d\n", ans); // Print the result
        return 0; // Exit the program
    }

    // Get the last key (largest adjustment) from the TreeMap
    int lastAdjustment = 0;
    int lastValue = 0;

    for (int i = 0; i < 5; i++) {
        if (r[i] != 0) {
            lastAdjustment = 10 - r[i];
            lastValue = a[i];
            break;
        }
    }

    // Find the index of the last value in the original array
    for (int i = 0; i < 5; i++) {
        if (a[i] == lastValue) {
            idx = i; // Store the index of the last value
        }
    }

    // Calculate the final answer by adding values, adjusting as necessary
    for (int i = 0; i < 5; i++) {
        if (i != idx) { // Skip the last value
            if (a[i] % 10 == 0) {
                ans += a[i]; // If already a multiple of 10, add directly
            } else {
                ans += a[i] + (10 - r[i]); // Adjust to the next multiple of 10
            }
        }
    }

    // Add the last value to the answer
    ans += lastValue;

    // Print the final calculated answer
    printf("%d\n", ans);

    return 0;
}
