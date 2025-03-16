
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	// Create a string to hold the input
	string input;
	// Read the first line of input (not used)
	getline(cin, input);
	// Read the second line of input which contains space-separated integers
	getline(cin, input);

	// Create a stringstream to parse the input string
	stringstream ss(input);
	// Create a vector to hold the integers
	vector<int> numbers;
	// Read the integers from the stringstream and add them to the vector
	int number;
	while (ss >> number) {
		numbers.push_back(number);
	}

	// Initialize a variable to hold the sum of products
	int sum = 0;
	// Calculate the sum of products of all unique pairs of integers
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			sum += numbers[i] * numbers[j]; // Multiply the pair and add to sum
		}
	}

	// Output the final sum of products
	cout << sum << endl;

	return 0;
}

