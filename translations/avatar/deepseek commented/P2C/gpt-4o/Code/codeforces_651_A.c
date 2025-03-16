#include <stdio.h>

int main() {
    // Step 1: Take two integers as input and assign them to x and y.
    int x, y;
    scanf("%d %d", &x, &y);

    // Step 2: Calculate the maximum value between x + y - 3 and 0, with an additional condition based on (y - x) % 3.
    int result = (x + y - 3) + ((y - x) % 3 > 0);
    if (result < 0) {
        result = 0;
    }
    printf("%d\n", result);

    // Step 3: Define functions for taking different types of inputs.
    // Note: In C, we typically don't use lambda functions like in Python.
    // Instead, we can define functions for different input types if needed.

    return 0;
}

// <END-OF-CODE>
