
#include <stdio.h> // Step 1: Include necessary headers

int main() // Step 2: Define the main function
{
	int a, b, mawari, menseki; // Step 3: Declare variables
	
	a, b = map(int, input().split()) # Step 4: Read input values
	mawari = 2 * (a + b) # Step 5: Calculate mawari
	menseki = a * b # Step 6: Calculate menseki
	print(menseki, mawari) # Step 7: Print the results
	return 0 # Step 8: Return 0
}


