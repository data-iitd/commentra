#include <stdio.h>

# This is the main function where the program starts execution
int main(void)
{
    int x; # Declare an integer variable named x

    # Ask the user to input an integer value and read it into the variable x
    scanf("%d", &x);

    # Calculate the result of x cubed and print it to the console
    printf("%d\n", x*x*x);

	# Signal that the program has finished execution with a return value of 0
	return 0;
}
