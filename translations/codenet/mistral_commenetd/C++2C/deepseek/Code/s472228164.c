#include <stdio.h> // Include stdio library for input and output operations
#include <string.h> // Include string library for handling strings

char* check(int x, int y) // Function declaration: check takes two integer arguments and returns a string
{
    if(y % 2 == 0) // Check if y is even
    {
        int t = (int)(0.5*y) - x; // Calculate t as half of y minus x

        if(t >= 0 && (x-t) >= 0) // Check if t is greater than or equal to zero and if x - t is also greater than or equal to zero
        {
            return "Yes"; // If both conditions are true, return "Yes"
        }
    }

    return "No"; // If y is not even, return "No"
}

int main() // Main function declaration
{
    int x, y; // Declare two integer variables x and y

    scanf("%d %d", &x, &y); // Read input values for x and y from standard input

    printf("%s\n", check(x, y)); // Call check function with input values and print its return value to standard output

    return 0; // Program ends with a return statement with a value of zero
}
