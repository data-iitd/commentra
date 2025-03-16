#include <stdio.h> // Include the standard input/output library

int main(void) // Declare the main function with no arguments and no return value
{

    int x, kotae; // Declare two integer variables, x and kotae


    # Ask the user to input an integer value for x
    print("Enter an integer value for x: ");
    x = input()


    # Calculate the cube of the input integer x and store the result in the variable kotae
    kotae = x*x*x ;


    # Print the result (the cube of the input integer) to the console
    print("The cube of %d is %d." % (x, kotae))


    # Return 0 to indicate successful execution of the program
    return 0

}

