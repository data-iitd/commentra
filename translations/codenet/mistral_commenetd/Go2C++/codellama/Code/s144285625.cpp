
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to split input into words
void split(string data, vector<int> &ar) {
	// Creating a stringstream object
	stringstream ss(data);

	// Reading the next integer from the stringstream
	int i;
	while (ss >> i) {
		// Pushing the integer to the vector
		ar.push_back(i);
	}
}

// Function to read next integer from input
int nextInt() {
	// Reading next token as a string
	string data;
	cin >> data;

	// Creating a vector to store the integers
	vector<int> ar;

	// Splitting the string into words
	split(data, ar);

	// Returning the first integer
	return ar[0];
}

// Main function
int main() {
	// Reading the number of elements in the array
	int n = nextInt();

	// Allocating memory for the array
	vector<int> ar(3*n);

	// Reading elements of the array
	for (int i = 0; i < 3*n; i++) {
		// Reading next integer and storing it in the array
		ar[i] = nextInt();
	}

	// Sorting the array in ascending order
	sort(ar.begin(), ar.end());

	// Calculating the sum of elements at index 3n-2i-1 in the sorted array
	int sum = 0;
	for (int i = 0; i < n; i++) {
		// Adding the element at index 3n-2i-1 to the sum
		sum += ar[3*n-(i+1)*2];
	}

	// Printing the result
	cout << sum << endl;

	return 0;
}

