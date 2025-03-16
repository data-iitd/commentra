
#include <stdio.h>

// Function declaration for finding the minimum number among given integers
int min(int n, int a, int b) {
    // Initializing the minimum value with the first integer
    int min = a;

    // If the second integer is less than the minimum value, update the minimum value
    if (b < min) {
        min = b;
    }

    // Returning the minimum value
    return min;
}

int main() {
    // Declaring three integer variables for reading input values
    int n, a, b;

    // Reading input values from the standard input using'scanf' function
    scanf("%d %d %d", &n, &a, &b);

    // Printing the minimum value between 'n*a' and 'b' using 'printf' function
    printf("%d\n", min(n*a, b));

    // End of the code
    return 0;
}

// End of the code