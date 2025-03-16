
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	// Create a new scanner to read from standard input
	string line;
	getline(cin, line);
	
	// Read the second line of input
	getline(cin, line);
	
	// Split the input string into a vector of strings
	stringstream ss(line);
	vector<string> dd;
	string d;
	while (ss >> d) {
		dd.push_back(d);
	}
	
	// Create a vector of integers to hold the converted values
	vector<int> dn(dd.size());
	
	// Convert each string in the vector to an integer
	for (int i = 0; i < dd.size(); i++) {
		dn[i] = stoi(dd[i]);
	}
	
	// Initialize the sum variable to hold the result
	int sum = 0;
	
	// Calculate the sum of the products of all pairs of integers in the vector
	for (int i = 0; i < dn.size(); i++) {
		for (int j = i + 1; j < dn.size(); j++) {
			sum += dn[i] * dn[j];
		}
	}
	
	// Print the result
	cout << sum << endl;
	
	return 0;
}

