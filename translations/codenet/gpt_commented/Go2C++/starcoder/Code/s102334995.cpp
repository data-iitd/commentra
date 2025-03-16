#include <iostream>

using namespace std;

int main() {
	// Declare two integer variables to hold user input
	int a, b;
	
	// Read two integers from standard input
	cin >> a >> b;
	
	// Calculate and print the product of a and b, 
	// and also print the perimeter of a rectangle with sides a and b
	cout << a*b << " " << (a+b)*2 << endl;
}

