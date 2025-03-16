
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	// Initialize a string variable ds to store the second line of input
	string ds;

	// Read the first two lines from standard input and store them in the string variable ds
	getline(cin, ds);
	getline(cin, ds);

	// Split the string ds into an array of strings dd using the stringstream class
	stringstream ss(ds);
	string d;
	vector<int> dd;
	while (ss >> d) {
		dd.push_back(stoi(d));
	}

	// Create a new vector dn of length len(dd) and initialize each element to 0 using the vector constructor
	vector<int> dn(dd.size(), 0);

	// Iterate through each element i in the vector dd
	for (int i = 0; i < dd.size(); i++) {
		// Iterate through each element j greater than i in the vector dd
		for (int j = i + 1; j < dd.size(); j++) {
			// Add the product of dd[i] and dd[j] to the sum variable
			dn[i] += dd[j] * dd[i];
		}
	}

	// Initialize sum variable to 0
	int sum = 0;

	// Iterate through each index i in the vector dn
	for (int i = 0; i < dn.size(); i++) {
		// Add the value of dn[i] to the sum variable
		sum += dn[i];
	}

	// Print the value of sum variable to the standard output using cout function
	cout << sum << endl;

	// End of code
	return 0;
}

