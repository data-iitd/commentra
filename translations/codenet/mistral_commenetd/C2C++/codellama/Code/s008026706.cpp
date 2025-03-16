
#include<iostream> // Include the standard input/output library

using namespace std; // Use the standard namespace

int main(){ // Start of the main function
	int a, b, x, y; // Declare four integer variables: a, b, x, and y

	cin >> a >> b; // Read two integers from the standard input and store them in variables a and b
	// The >> operator is used to read integers, and the & symbol is used to pass the memory addresses of variables a and b to cin

	x = 2*a + 2*b; // Multiply variables a and b by 2, and then add the results together and store the result in variable x

	y = a*b; // Multiply variables a and b and store the result in variable y

	cout << y << " " << x << endl; // Print the values of variables y and x to the standard output, separated by a space and followed by a newline character

	return 0; // Indicate that the main function has run successfully and terminate the program
}

