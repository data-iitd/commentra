#include <iostream>

using namespace std;

int main() {
	// Declare two integer variables A and B
	int A, B;
	
	// Read two integers from the standard input and assign them to A and B
	cin >> A >> B;
	
	// Declare a variable to store the result
	int ans;
	
	// Check if A is between 6 and 12 inclusive
	if (6 <= A && A <= 12) {
		// Calculate the half of B and assign it to ans
		ans = B / 2;
	} else if (12 < A) {
		// Assign B to ans if A is greater than 12
		ans = B;
	}
	
	// Print the value of ans
	cout << ans << endl;
}

