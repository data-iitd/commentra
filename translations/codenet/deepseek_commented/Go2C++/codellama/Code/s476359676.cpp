
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

// Reads the next string from the input
string nextStr() {
	string str;
	getline(cin, str);
	return str;
}

// Reads the next integer from the input
int nextInt() {
	int i;
	cin >> i;
	return i;
}

int main() {
	// Initialize the answer and the previous element in the sequence
	int ans = 0;
	int aPrev = 0;
	// Read the number of elements in the sequence
	int n = nextInt();
	// Loop through each element in the sequence
	for (int i = 0; i < n; i++) {
		// Read the current element
		int a = nextInt();
		// Check the conditions for the current element
		switch (true) {
		case a > i || a > aPrev + 1:
			// If the condition is met, print -1 and exit
			cout << -1 << endl;
			return 0;
		case a == aPrev + 1:
			// If the current element is one more than the previous, increment the answer
			ans++;
		default:
			// Otherwise, add the current element's value to the answer
			ans += a;
		}
		// Update the previous element to the current element
		aPrev = a;
	}
	// Print the final answer after processing all elements
	cout << ans << endl;
	return 0;
}

