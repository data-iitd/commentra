
#include <stdio.h>

// min function takes a variable number of integer arguments and returns the minimum value among them.
int min(int n,...) {
    // Initialize min with the first element of nums
    int min = n;
    // Get the variable number of arguments
    va_list args;
    va_start(args, n);
    // Iterate over each value in nums to find the minimum
    for (int i = 0; i < n; i++) {
        int v = va_arg(args, int);
        // Update min if the current value is less than the current min
        if (v < min) {
            min = v;
        }
    }
    // Return the minimum value found
    return min;
}

int main() {
    // Declare variables to hold input values
    int n, a, b;
    // Read three integers from standard input
    scanf("%d %d %d", &n, &a, &b);

    // Calculate the minimum of n*a and b, and print the result
    printf("%d\n", min(n*a, b));
    return 0;
}
