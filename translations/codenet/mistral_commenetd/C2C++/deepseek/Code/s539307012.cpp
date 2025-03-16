#include <iostream> // Including the standard input/output stream library

int main() { // The main function, which is the starting point of the program
	int n, x, min, m, i; // Declaring the variables n, x, min, m, and i

	std::cin >> n >> x >> min; // Reading three integers from the standard input and storing them in the variables n, x, and min

	x -= min; // Subtracting the minimum value from x

	for (i = 1; i < n; i++) { // Starting a for loop that iterates from 1 to n-1
		std::cin >> m; // Reading an integer from the standard input and storing it in the variable m

		x -= m; // Subtracting the current number from x

		if (min > m) { // Checking if the current number is smaller than the current minimum
			min = m; // Updating the minimum if it is
		}
	}

	std::cout << n + x / min << std::endl; // Printing the final result, which is the number of elements plus the quotient of the remaining difference and the minimum number

	return 0; // Indicating that the program has ended successfully
}
