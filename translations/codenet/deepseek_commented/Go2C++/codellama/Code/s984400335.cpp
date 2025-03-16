#include <iostream>

using namespace std;

int min(int nums[], int size) {
	int min = nums[0]; // Initialize min with the first element
	for (int i = 1; i < size; i++) {
		if (nums[i] < min) { // Compare each element with the current min
			min = nums[i]; // Update min if a smaller value is found
		}
	}
	return min; // Return the smallest value
}

int main() {
	int n, a, b;
	cin >> n >> a >> b; // Read three integers from input

	cout << min(&n*a, &b, 2) << endl; // Print the minimum of n*a and b

	return 0;
}

