
#include <iostream>

int main() {
	int n, sum;
	
	// Step 4: Read input from the user
	std::cin >> n;
	
	// Step 5: Calculate the sum of the first n natural numbers
	sum = (n * (n + 1)) / 2;
	
	// Step 6: Print the result
	std::cout << sum << std::endl;
	
	// Step 7: Return from the main function
	return 0;
}

