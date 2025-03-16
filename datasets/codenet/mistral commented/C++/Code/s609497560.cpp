#include <iostream> // Include the iostream library for input/output operations

using namespace std; // Use the standard namespace for easier access to iostream functions

int main() // Begin the main function
{
	int a; // Declare an integer variable named 'a'

	cin >> a; // Read an integer value from the user and store it in variable 'a'

	// Calculate the value of the expression (a + (a * a) + (a * a * a)) and store it in the output buffer
	cout << (a + (a * a) + (a * a * a)) << endl;

	return 0; // Indicate successful execution of the program
}
