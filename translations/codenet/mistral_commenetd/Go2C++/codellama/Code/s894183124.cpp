// Include the iostream header to enable input/output operations
#include <iostream>

// Include the string header to use the "Count" function
#include <string>

using namespace std;

int main() {
	// Declare and initialize two variables: n of type int and s of type string
	int n;
	string s;

	// Use the cin object to read input from the standard input
	cin >> n;
	cin >> s;

	// Use the cout object to compute and print the result
	cout << s.count("ABC") << endl;

	return 0;
}

// End of code 