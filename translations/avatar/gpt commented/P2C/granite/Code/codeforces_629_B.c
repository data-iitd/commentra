
#include <stdio.h>

int main() {
    // Use readline for faster input reading
    char buf[1024];
    fgets(buf, sizeof(buf), stdin);

    // Initialize a constant N for the size of the arrays
    #define N 368

    // Create two arrays to track the values for 'M' and 'F'
    int m[N] = {0};  // Array to track 'M' values
    int f[N] = {0};  // Array to track 'F' values

    // Read the number of operations from input
    int t;
    sscanf(buf, "%d", &t);

    // Iterate through the number of operations
    for (int i = 0; i < t; i++) {
        // Read the operation type and the indices a and b
        fgets(buf, sizeof(buf), stdin);
        char x;
        int a, b;
        sscanf(buf, "%c %d %d", &x, &a, &b);

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
    int a = 0, b = 0, c = 0;

    // Iterate through the range of N to calculate cumulative sums and find the minimum
    for (int i = 0; i < N; i++) {
        a += m[i];  // Update cumulative sum for 'M'
        b += f[i];  // Update cumulative sum for 'F'

        // Update the minimum value if the current minimum of a and b is greater than c
        if (a < b) {
            if (a < c) {
                c = a;  // Set c to the new minimum value
            }
        } else {
            if (b < c) {
                c = b;  // Set c to the new minimum value
            }
        }
    }

    // Print the final minimum value found
    printf("%d\n", c);

    // End the program
    return 0;
}
