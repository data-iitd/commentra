#include<stdio.h> # Include the standard input-output library

int main(void) # Main function where program execution begins
{
    int x; # Declare an integer variable x

    # Prompt the user for input and read an integer value into x
    scanf("%d", &x);

    # Calculate the cube of x and print the result
    printf("%d\n", x * x * x);

    return 0; # Return 0 to indicate successful execution
}
