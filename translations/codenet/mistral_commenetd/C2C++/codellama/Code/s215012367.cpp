#include<iostream> // Including the standard input/output library

using namespace std; // Using the standard namespace

int main() // Declaring the main function
{
	int a, b, s; // Declaring three integer variables a, b, and s

	cin >> a >> b; // Reading two integers from the user and storing them in variables a and b

	s = (a*b) - (a + b) + 1; // Calculating the value of s by multiplying a and b, subtracting the sum of a and b, and adding 1

	// The following line prints the value of s to the console
	cout << s << endl;

	return 0; // Indicating that the program has run successfully
}

