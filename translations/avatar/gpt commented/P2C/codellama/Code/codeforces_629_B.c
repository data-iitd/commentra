
#include <stdio.h>

// Use readline for faster input reading
#define input(x) scanf("%d", &x)

// Initialize a constant N for the size of the arrays
#define N 368

// Create two lists to track the values for 'M' and 'F'
int m[N];  // List to track 'M' values
int f[N];  // List to track 'F' values

// Read the number of operations from input
int i, a, b;
for (i = 0; i < input(); i++) {
    // Read the operation type and the indices a and b
    char x[2];
    scanf("%s", x);
    input(a);
    input(b);
    b++;  // Increment by 1 for range adjustment

    // Update the corresponding list based on the operation type
    if (x[0] == 'M') {
        m[a] += 2;  // Increment the value at index a in the 'M' list
        m[b] -= 2;  // Decrement the value at index b in the 'M' list
    } else {
        f[a] += 2;  // Increment the value at index a in the 'F' list
        f[b] -= 2;  // Decrement the value at index b in the 'F' list
    }
}

// Initialize variables to track cumulative sums and the minimum value
int a = 0, b = 0, c = 0;

// Iterate through the range of N to calculate cumulative sums and find the minimum
for (i = 0; i < N; i++) {
    a += m[i];  // Update cumulative sum for 'M'
    b += f[i];  // Update cumulative sum for 'F'
    
    // Update the minimum value if the current minimum of a and b is greater than c
    if (min(a, b) > c) {
        c = min(a, b);  // Set c to the new minimum value
    }
}

// Print the final minimum value found
printf("%d\n", c);

