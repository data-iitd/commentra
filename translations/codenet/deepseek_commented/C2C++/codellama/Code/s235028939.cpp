#include <iostream>  // Include the standard input-output library

int main()
{
	int n, m; // Declare two integer variables to store input values
	std::cin >> n >> m; // Read two integers from the standard input and store them in n and m
	std::cout << (n - 1) * (m - 1) << std::endl; // Print the result of the expression (n - 1) * (m - 1)
	return 0; // Return 0 to indicate successful execution
}

