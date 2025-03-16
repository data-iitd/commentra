
#include <iostream>
#include <cmath>

int main() {
	// Declare variables to store the number of successful and failed runs
	int n, m;
	
	// Read the number of successful and failed runs from the standard input
	std::cin >> n >> m;
	
	// Calculate the total time in milliseconds for the successful and failed runs
	int x = m*1900 + (n-m)*100;
	
	// Print the result of the expression (total time * 2^m)
	std::cout << x * pow(2, m) << std::endl;
	
	return 0;
}

