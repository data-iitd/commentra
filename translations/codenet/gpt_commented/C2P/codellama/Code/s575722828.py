#include <stdio.h>

int main()
{
    # Declare an integer variable to store the total seconds
    S = 0

    # Read the total seconds from user input
    scanf("%d", &S)

    # Calculate hours, minutes, and seconds from the total seconds
    # and print them in the format HH:MM:SS
    printf("%d:%d:%d\n", 
           (int)(S / 3600),                # Calculate hours
           (int)((S % 3600) / 60),        # Calculate minutes
           S % 60)                       # Calculate remaining seconds

    # Return 0 to indicate successful completion of the program
    return 0
}

