#include <stdio.h>  # Include the standard input/output library

int main()
{
    i = 1
    Input = 0
    # Start an infinite loop
    while True:
        scanf("%d", &Input)  # Read an integer from the user
        if Input == 0:       # Check if the input is 0
            break            # Exit the loop if the input is 0
        printf("Case %d: %d\n", i, Input)  # Print the current case number and input value
        i += 1                   # Increment the case number
    return 0  # Return 0 to indicate successful execution
}

