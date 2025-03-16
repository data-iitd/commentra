#include <iostream> // We include the iostream library to use input and output streams
using namespace std; // We use the standard namespace to avoid writing std:: before every standard library function

int main(void) { // The main function is the entry point of the program
	long long int a, b; // We declare two long long integers named a and b to store user input

	// We use the cin object to read user input and store it in variables a and b
	cin >> a >> b;

	if ((a + b) % 2 == 0) { // We check if the sum of a and b is even
		// If the sum is even, we print the result by dividing it by 2
		cout << (a + b) / 2 << "\n";
	} else { // If the sum is odd, we print "IMPOSSIBLE"
		cout << "IMPOSSIBLE\n";
	}
}

