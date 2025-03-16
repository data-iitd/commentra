
#include <stdio.h>

// Include the standard input/output library

int main()
{
    // Declare and initialize variables
    int i = 1; // Initialize counter variable i to 1
    int Input; // Declare variable to store user input

    while(1)
    {
        # Read user input and store it in the Input variable
        Input = int(input("Enter a number: "))

        # Check if user input is 0
        if(Input == 0)
        {
            # If user input is 0, break out of the loop
            break
        }

        # Print the case number and user input
        print("Case %d: %d" % (i,Input))

        # Increment the counter variable i
        i += 1

    # Return 0 to indicate successful execution of the program
    return 0
}

