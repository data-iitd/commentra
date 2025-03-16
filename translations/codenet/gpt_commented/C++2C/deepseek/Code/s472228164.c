#include <stdio.h>
#include <string.h>

// Function to check certain conditions based on input values x and y
char* check(int x, int y)
{
    static char result[3]; // Use a static array to hold the result

    // Check if y is an even number
    if(y % 2 == 0)
    {
        // Calculate t as half of y minus x
        int t = (int)(0.5*y) - x;
        
        // Check if t is non-negative and if (x - t) is also non-negative
        if(t >= 0 && (x-t) >= 0)
        {
            strcpy(result, "Yes"); // Set result to "Yes" if conditions are satisfied
            return result; // Return the result
        }
    }
    strcpy(result, "No"); // Set result to "No" if conditions are not satisfied
    return result; // Return the result
}

int main()
{
    int x, y; // Declare variables to hold input values
    scanf("%d %d", &x, &y); // Read input values for x and y

    // Call the check function and print the result
    printf("%s\n", check(x, y));
    return 0; // Indicate that the program ended successfully
}

