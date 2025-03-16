#include <stdio.h>

#define N 368  // Initialize a constant N for the size of the arrays

int main() {
    // Create two arrays to track the values for 'M' and 'F'
    int m[N] = {0};  // Array to track 'M' values
    int f[N] = {0};  // Array to track 'F' values

    // Read the number of operations from input
    int operations;
    scanf("%d", &operations);
    getchar();  // Consume the newline character after the integer input

    for (int i = 0; i < operations; i++) {
        char x;
        int a, b;
        // Read the operation type and the indices a and b
        scanf(" %c %d %d", &x, &a, &b);
        b++;  // Increment b by 1 for range adjustment

        // Update the corresponding array based on the operation type
        if (x == 'M') {
            m[a] += 2;  // Increment the value at index a in the 'M' array
            m[b] -= 2;  // Decrement the value at index b in the 'M' array
        } else {
            f[a] += 2;  // Increment the value at index a in the 'F' array
            f[b] -= 2;  // Decrement the value at index b in the 'F' array
        }
    }

    // Initialize variables to track cumulative sums and the minimum value
    int cumulativeM = 0, cumulativeF = 0, minValue = 0;

    // Iterate through the range of N to calculate cumulative sums and find the minimum
    for (int i = 0; i < N; i++) {
        cumulativeM += m[i];  // Update cumulative sum for 'M'
        cumulativeF += f[i];  // Update cumulative sum for 'F'
        
        // Update the minimum value if the current minimum of cumulativeM and cumulativeF is greater than minValue
        if (cumulativeM < cumulativeF && cumulativeM > minValue) {
            minValue = cumulativeM;  // Set minValue to the new minimum value
        } else if (cumulativeF < cumulativeM && cumulativeF > minValue) {
            minValue = cumulativeF;  // Set minValue to the new minimum value
        }
    }

    // Print the final minimum value found
    printf("%d\n", minValue);

    return 0;
}
