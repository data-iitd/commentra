#include <iostream> // Include the iostream library for input and output operations

using namespace std; // Use the standard namespace to avoid prefixing standard library names with 'std::'

int main()
{
	int a; // Declare an integer variable 'a'
	cin >> a; // Read a value from the user and store it in 'a'
	cout << (a + (a * a) + (a * a * a)) << endl; // Calculate and print the sum of 'a', 'a^2', and 'a^3'

	return 0; // Return 0 to indicate successful execution
}
