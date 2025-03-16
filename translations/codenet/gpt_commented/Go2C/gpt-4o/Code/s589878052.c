#include <stdio.h> // Including the standard input-output library

int main() {
    // Declare variables to hold the lengths of the two bases and the height
    int a, b, h;
    
    // Read input values for the two bases (a and b) and the height (h) from the user
    scanf("%d %d %d", &a, &b, &h);

    // Calculate the area of the trapezoid using the formula: Area = (a + b) * h / 2
    // and print the result to the console
    printf("%d\n", (a + b) * h / 2);

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
