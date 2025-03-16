#include <stdio.h>  // Include the standard input/output library

int main(){  // Define the main function
    int a, b;  // Declare two integer variables
    scanf("%d %d", &a, &b);  // Read two integers from the user
    printf("%d %d\n", a * b, 2 * (a + b));  // Perform calculations and print the results
    return 0;  // Return 0 to indicate successful execution
}
