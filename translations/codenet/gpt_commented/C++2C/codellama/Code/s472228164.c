#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check certain conditions based on input values x and y
char* check(int x, int y)
{
    // Check if y is an even number
    if(y % 2 == 0)
    {
        // Calculate t as half of y minus x
        int t = (int)(0.5*y) - x;
        
        // Check if t is non-negative and if (x - t) is also non-negative
        if(t >= 0 && (x-t) >= 0)
            return "Yes"; // Return "Yes" if both conditions are satisfied
    }
    return "No"; // Return "No" if y is odd or conditions are not satisfied
}

int main()
{
    int x, y; // Declare variables to hold input values
    scanf("%d %d", &x, &y); // Read input values for x and y

    // Call the check function and print the result
    printf("%s\n", check(x, y));
    return 0; // Indicate that the program ended successfully
}

