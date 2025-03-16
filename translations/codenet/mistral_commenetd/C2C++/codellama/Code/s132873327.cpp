#include <iostream>

// This is the main function where the program starts execution
int main()
{
    int x; // Declare an integer variable named x

    // Ask the user to input an integer value and read it into the variable x
    std::cin >> x;

    // Calculate the result of x cubed and print it to the console
    std::cout << x*x*x << std::endl;

	// Signal that the program has finished execution with a return value of 0
	return 0;
}

