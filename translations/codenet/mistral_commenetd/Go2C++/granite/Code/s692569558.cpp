

#include <iostream> // Include iostream library for input/output operations
#include <string> // Include string library for string manipulation
#include <vector> // Include vector library for dynamic arrays
#include <sstream> // Include stringstream library for string stream operations

using namespace std;

int main() {
	// Initialize a string variable ds to store the input from the user
	string ds;

	// Read the first two lines from standard input and store them in the string variable ds
	getline(cin, ds);
	getline(cin, ds);

	// Create a stringstream object s to read from the string variable ds
	stringstream s(ds);

	// Create a vector of integers dn to store the values read from the string variable ds
	vector<int> dn;

	// Read the values from the string variable ds and store them in the vector dn
	int d;
	while (s >> d) {
		dn.push_back(d);
	}

	// Initialize sum variable to 0
	int sum = 0;

	// Iterate through each index i in the vector dn
	for (int i = 0; i < dn.size(); i++) {
		// Iterate through each index j greater than i in the vector dn
		for (int j = i + 1; j < dn.size(); j++) {
			// Add the product of dn[i] and dn[j] to the sum variable
			sum += dn[i] * dn[j];
		}
	}

	// Print the value of sum variable to the standard output using cout
	cout << sum << endl;

	// End of code
}

