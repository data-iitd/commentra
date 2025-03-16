#include<iostream> // Including the iostream library for input/output operations

int main() // Declaring the main function
{
	int a, b, s; // Declaring three integer variables a, b, and s

	std::cin >> a >> b; // Reading two integers from the user and storing them in variables a and b

	s = (a*b) - (a + b) + 1; // Calculating the value of s by multiplying a and b, subtracting the sum of a and b, and adding 1

	// The following line prints the value of s to the console
	std::cout << s << std::endl;

	return 0; // Indicating that the program has run successfully
}
