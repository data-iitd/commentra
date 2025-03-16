#include <iostream> // Step 1: Include necessary headers

using namespace std; // Step 2: Use namespace std

int main() // Step 3: Define the main function
{
	int a, b, mawari, menseki; // Step 4: Declare variables
	
	cin >> a >> b; // Step 5: Read input values
	mawari = 2 * (a + b); // Step 6: Calculate mawari
	menseki = a * b; // Step 7: Calculate menseki
	cout << menseki << " " << mawari << endl; // Step 8: Print the results
	return 0; // Step 9: Return 0
}

