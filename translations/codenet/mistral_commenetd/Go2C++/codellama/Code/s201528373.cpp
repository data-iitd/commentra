
#include <iostream>
#include <vector>

using namespace std;

int main() {
	// Initialize variables
	int n, x;
	vector<int> l;

	// Read input values for n and x
	cout << "Enter the number of arrays: ";
	cin >> n;
	cout << "Enter the sum of elements in an array that should not exceed: ";
	cin >> x;

	// Initialize an empty vector l to store the arrays
	l.clear();

	// Read input values for each array and append them to the vector l
	for (int i = 0; i < n; i++) {
		// Read the length of the current array
		int tmpL;
		cout << "Enter the length of array number " << i + 1 << ": ";
		cin >> tmpL;

		// Append the length of the current array to the vector l
		l.push_back(tmpL);
	}

	// Initialize variables for sum and result vector index
	int tmpSum = 0;
	int rs = 0;

	// Iterate through the vector l to find the index of the last array whose sum is less than or equal to x
	for (int i = 0; i < l.size(); i++) {
		// Initialize a variable tmpSum to store the sum of elements in the current array
		tmpSum = 0;

		// Calculate the sum of elements in the current array
		for (int j = 0; j < l[i]; j++) {
			// Read the value of the current element and add it to the sum
			int tmp;
			cout << "Enter the value of element number " << j + 1 << " in array number " << i + 1 << ": ";
			cin >> tmp;
			tmpSum += tmp;
		}

		// Check if the sum of elements in the current array is greater than x
		if (tmpSum > x) {
			// If yes, break the loop as we don't need to check further arrays
			break;
		}

		// If the sum of elements in the current array is less than or equal to x, update the result vector index
		rs = i + 1;
	}

	// Print the result vector index
	cout << "The last array index whose sum of elements is less than or equal to " << x << " is: " << rs << endl;

	return 0;
}

