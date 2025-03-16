
#include <iostream>

using namespace std;

int main() {
	// Initialize an array of size 3 with type int
	int a[3];

	// Read three integers from the standard input and store them in the array
	cin >> a[0] >> a[1] >> a[2];

	// Initialize two variables with zero value
	int five = 0, seven = 0;

	// Iterate through the array using a for loop
	for (int i = 0; i < 3; i++) {
		// Check if the current element of the array is equal to 5
		if (a[i] == 5) {
			// Increment the variable five by 1
			five++;
		}
		// Check if the current element of the array is equal to 7
		if (a[i] == 7) {
			// Increment the variable seven by 1
			seven++;
		}
	}

	// Check if the number of occurrences of 5 is equal to 2 and the number of occurrences of 7 is equal to 1
	if (five == 2 && seven == 1) {
		// Print the string "YES" if the condition is true
		cout << "YES" << endl;
	} else {
		// Print the string "NO" if the condition is false
		cout << "NO" << endl;
	}

	return 0;
}

