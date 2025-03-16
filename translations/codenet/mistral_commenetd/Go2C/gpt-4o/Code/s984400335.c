// Including standard input/output library
#include <stdio.h>

// Function declaration for finding the minimum number among given integers
int min(int nums[], int size) {
    // Initializing the minimum value with the first integer
    int min = nums[0];

    // Iterating through the array 'nums' to find the minimum value
    for (int i = 1; i < size; i++) {
        // If the current value is less than the minimum value, update the minimum value
        if (nums[i] < min) {
            min = nums[i];
        }
    }

    // Returning the minimum value
    return min;
}

// Main function declaration
int main() {
    // Declaring three integer variables for reading input values
    int n, a, b;

    // Reading input values from the standard input using 'scanf' function
    scanf("%d %d %d", &n, &a, &b);

    // Declaring an array to hold the values for comparison
    int values[2] = {n * a, b};

    // Printing the minimum value between 'n*a' and 'b' using 'printf' function
    printf("%d\n", min(values, 2));

    return 0;
}

// <END-OF-CODE>
