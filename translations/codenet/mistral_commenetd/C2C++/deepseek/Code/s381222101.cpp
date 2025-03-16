#include <iostream> // Include the iostream library for input and output operations

using namespace std; // Use the standard namespace

int main() // Declare the main function
{
	int a, b, h; // Declare three integer variables: a, b, and h

	cout << "Enter the values of a, b, and h: "; // Print a message asking for user input
	cin >> a >> b >> h; // Read three integers from the user and store them in variables a, b, and h

	// Calculate the area of the rectangle using the formula: area = length * width
	cout << (a+b)*h/2 << endl; // Print the result, which is the area of the rectangle

	return 0; // Indicate that the program has run successfully
}

