
#include<stdio.h>   // Include the standard input/output library for input and output operations

int main()
{
    int n;  // Declare an integer variable 'n' to store the number of sides of the polygon
    scanf("%d", &n);  // Read the number of sides from user input

    // Calculate the sum of the interior angles of a polygon with 'n' sides
    // The formula for the sum of interior angles is (n - 2) * 180
    printf("%d\n", (n - 2) * 180);  // Output the calculated sum of interior angles

    return 0;  // Return 0 to indicate successful completion of the program
}
