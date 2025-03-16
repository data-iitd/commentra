#include <stdio.h> // Including the standard input-output library

int main() {
    // Declare two integer variables to hold user input
    int a, b;
    
    // Read two integers from standard input
    scanf("%d %d", &a, &b);
    
    // Calculate and print the product of a and b, 
    // and also print the perimeter of a rectangle with sides a and b
    printf("%d %d\n", a * b, (a + b) * 2);
    
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
