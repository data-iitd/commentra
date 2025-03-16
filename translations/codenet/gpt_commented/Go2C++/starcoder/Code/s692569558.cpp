#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	// Read the first line of input (not used)
	string s;
	getline(cin, s);

	// Read the second line of input which contains space-separated integers
	string ds;
	getline(cin, ds);

	// Split the input string into a vector of strings
	vector<string> dd;
	stringstream ss(ds);
	string d;
	while (getline(ss, d,'')) {
		dd.push_back(d);
	}

	// Convert each string in the vector to an integer
	vector<int> dn;
	for (int i = 0; i < dd.size(); i++) {
		dn.push_back(stoi(dd[i]));
	}

	// Initialize a variable to hold the sum of products
	int sum = 0;
	// Calculate the sum of products of all unique pairs of integers
	for (int i = 0; i < dn.size(); i++) {
		for (int j = i + 1; j < dn.size(); j++) {
			sum += dn[i] * dn[j]; // Multiply the pair and add to sum
		}
	}

	// Output the final sum of products
	cout << sum << endl;
}

