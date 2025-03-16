#include<stdio.h>   // Include the header file for input and output operations
#include<stdlib.h>  // Include the header file for various operations (not used in this code)
#include<string.h>  // Include the header file for string manipulations (not used in this code)
#include<stdbool.h> // Include the header file for using the bool data type (not used in this code)
#include<math.h>    // Include the header file for mathematical operations (not used in this code)

int main()
{
    int n;  // Declare an integer variable 'n' to store the number of sides of the polygon
    scanf("%d", &n);  // Read the number of sides from user input

    // Calculate the sum of the interior angles of a polygon with 'n' sides
    // The formula for the sum of interior angles is (n - 2) * 180
    printf("%d\n", (n - 2) * 180);  // Output the calculated sum of interior angles

    return 0;  // Return 0 to indicate successful completion of the program
}

