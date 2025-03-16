
#include<iostream> // Including the standard input/output library

using namespace std; // Using the standard namespace

int main() // Declaring the main function
{
	int a, b; // Declaring two integer variables a and b
	cin >> a >> b; // Reading two integers from the standard input and storing them in variables a and b

	// Logical block to check if 500 times the value of variable 'a' is greater than or equal to the value of variable 'b'
	if(500*a >= b)
	{
		cout << "Yes" << endl; // If the condition is true, print 'Yes' to the standard output
	}
	else
	{
		cout << "No" << endl; // If the condition is false, print 'No' to the standard output
	}

	return 0; // Indicating successful termination of the program
}

