
#include <iostream>
using namespace std;

int main() {
	int a; // Declare a variable 'a' of type int to store user input
	cin >> a; // Read an integer value from standard input and store it in 'a'
	
	// Calculate the expression a + a^2 + a^3 and print the result
	cout << a + a*a + a*a*a << endl;
	return 0;
}

