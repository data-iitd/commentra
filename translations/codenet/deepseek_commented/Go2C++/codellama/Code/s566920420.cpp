#include <iostream>

int main() {
	// Declare an integer variable 'a' to store the user input
	int a;
	
	// Read an integer input from the user and store it in 'a'
	std::cin >> a;
	
	// Print the result of the expression 'a + a*a + a*a*a'
	std::cout << a + a*a + a*a*a << std::endl;
	
	return 0;
}

