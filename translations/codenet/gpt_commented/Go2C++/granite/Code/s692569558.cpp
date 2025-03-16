
#include <iostream> // Importing iostream for input/output
#include <string> // Importing string for string manipulation
#include <sstream> // Importing stringstream for string stream operations
#include <vector> // Importing vector for dynamic arrays
#include <algorithm> // Importing algorithm for sorting and other operations
#include <numeric> // Importing numeric for numeric operations

using namespace std;

int main() {
	// Create a string variable to hold the input string
	string input;
	// Read the first line of input (not used)
	getline(cin, input);
	// Read the second line of input which contains space-separated integers
	getline(cin, input);

	// Create a stringstream to read from the input string
	stringstream ss(input);
	// Create a vector of integers to hold the converted values
	vector<int> numbers;
	// Read each integer from the input string and push it to the vector
	int num;
	while (ss >> num) {
		numbers.push_back(num);
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
