
#include <iostream> // Step 1: Include necessary headers

int main() // Step 2: Define the main function
{
	int a, b, mawari, menseki; // Step 3: Declare variables
	
	std::cin >> a >> b; // Step 4: Read input values
	mawari = 2 * (a + b); // Step 5: Calculate mawari
	menseki = a * b; // Step 6: Calculate menseki
	std::cout << menseki << " " << mawari << std::endl; // Step 7: Print the results
	return 0; // Step 8: Return 0
}
