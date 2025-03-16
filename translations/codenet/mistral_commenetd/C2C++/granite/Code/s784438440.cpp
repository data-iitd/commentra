
#include<iostream> // Include the standard input/output library

int main() // The entry point of the program
{
	int a, b; // Declare two integer variables 'a' and 'b'

	std::cin>>a>>b; // Read two integers from the standard input and store them in variables 'a' and 'b'

	std::cout<<((b-1)+(a-2))/(a-1)<<std::endl; // Print the result of the expression ((b-1)+(a-2))/(a-1) to the standard output

	return 0; // Indicate that the program has executed successfully
}

