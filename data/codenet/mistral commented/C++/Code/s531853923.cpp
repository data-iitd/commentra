#include<iostream>  // Include the iostream library for input and output operations
#include<string>    // Include the string library for handling strings
#include<vector>     // Include the vector library for handling dynamic arrays
#include<algorithm>  // Include the algorithm library for standard algorithms
using namespace std;  // Use the standard namespace for easier access to library functions

int main()  // Declare the main function, which is the entry point of the program
{
	// Declare four integer variables to store input values
	int a, b, c, d;

	// Read input values from the user using cin
	cin >> a >> b >> c >> d;

	// Check if the condition is true
	if (a*b%2==1&&(c+d)%2==1)
	{
		// If the condition is true, print "No" to the output stream
		cout << "No" << endl;
	}
	// If the condition is false, print "Yes" to the output stream
	else
	{
		cout << "Yes" << endl;
	}
}
