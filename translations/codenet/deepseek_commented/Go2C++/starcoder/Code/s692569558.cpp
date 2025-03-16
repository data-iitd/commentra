
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
	// Read the first line of input (which we will ignore)
	string s;
	getline(cin, s);
	
	// Read the second line of input
	getline(cin, s);
	
	// Split the input string into a vector of strings
	vector<string> dd = split(s, " ");
	
	// Create a vector of integers to hold the converted values
	vector<int> dn(dd.size());
	
	// Convert each string in the vector to an integer
	for (int i = 0; i < dd.size(); i++) {
		dn[i] = atoi(dd[i].c_str());
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
}

