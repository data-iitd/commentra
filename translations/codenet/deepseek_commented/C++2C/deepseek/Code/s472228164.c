#include <stdio.h>
#include <string.h>

// Function to check if a certain condition is met based on the values of x and y
char* check(int x, int y)
{
    static char result[3]; // Use a static array to hold the result

    // Check if y is even
    if(y % 2 == 0)
    {
        // Calculate t as half of y minus x
        int t = (int)(0.5*y) - x;
        // Check if t is non-negative and x minus t is also non-negative
        if(t >= 0 && (x-t) >= 0)
        {
            strcpy(result, "Yes");
            return result;
        }
    }
    // If the conditions are not met, set result to "No"
    strcpy(result, "No");
    return result;
}

int main()
{
    int x, y;
    // Read two integers x and y from the standard input
    scanf("%d %d", &x, &y);

    // Call the check function with x and y, and print the result
    printf("%s\n", check(x, y));
    return 0;
}

