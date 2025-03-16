#include <stdio.h>

// Function to find the smallest number among the given arguments
int min(int x, int y) {
    return (x < y) ? x : y; // Return the smaller of the two numbers
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b); // Read three integers from input

    printf("%d\n", min(n * a, b)); // Print the minimum of n*a and b
<<<<<<< HEAD
    return 0; // Return 0 to indicate successful execution
=======
    return 0; // Return success
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
