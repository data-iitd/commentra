#include<iostream>
// Include the standard input/output library

int main()
// Function main is the starting point of the program
{
	int x;
	// Declare an integer variable x

	std::cin>>x;
	// Read an integer value from the standard input and store it in variable x

	std::cout<<x*x*x<<std::endl;
	// Print the result of x cubed to the standard output

	return 0;
	// Indicate successful termination of the program
}
