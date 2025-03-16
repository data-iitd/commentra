#include <stdio.h> // Include the standard input-output library

int main()
{
    int a, b; // Declare two integer variables a and b
    scanf("%d %d", &a, &b); // Read two integer inputs from the user

    // Check if both a and b are less than or equal to 8
    if (a <= 8 && b <= 8) 
        printf("Yay!\n"); // If true, print "Yay!"
    else 
        printf(":("); // If false, print ":("

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
