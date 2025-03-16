#include <stdio.h>

int main(void)
{
    // Declare an integer variable to hold the input value
    int x;

    // Read an integer value from the user and store it in variable x
    scanf("%d", &x);

    // Calculate the cube of the input value and print the result
    printf("%d\n", x*x*x);

    // Return 0 to indicate that the program finished successfully
    return 0;
}
