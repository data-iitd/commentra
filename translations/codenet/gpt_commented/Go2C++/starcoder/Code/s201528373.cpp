#include <iostream>
#include <vector>

using namespace std;

int main() {
	// Declare variables for the number of elements (n), the threshold value (x), and a vector to hold the integers (l)
	int n, x;
	vector<int> l;
	
	// Read the number of elements (n) from standard input
	cin >> n;
	// Read the threshold value (x) from standard input
	cin >> x;
	
	// Loop to read n integers from standard input and append them to the vector l
	for (int i = 0; i < n; i++) {
		int tmpL;
		// Read each integer and store it in tmpL
		cin >> tmpL;
		// Append the read integer to the vector l
		l.push_back(tmpL);
	}
	
	// Initialize variables to keep track of the cumulative sum (tmpSum) and the result (rs)
	int tmpSum = 0;
	int rs = 0;
	
	// Loop through the vector l to calculate the cumulative sum and determine the result
	for (int i = 0; i < l.size(); i++) {
		// Add the current value to the cumulative sum
		tmpSum += l[i];
		
		// Check if the index exceeds the number of elements
		if (i >= n) {
			rs = n; // Set result to n if index exceeds n
			break;
		}
		
		// If the cumulative sum is less than or equal to x, update the result
		if (tmpSum <= x) {
			rs = i + 2; // Update result to the current index + 2
		} else if (tmpSum > x) {
			break; // Exit the loop if the cumulative sum exceeds x
		}
	}
	
	// Print the final result
	cout << rs << endl;
}

