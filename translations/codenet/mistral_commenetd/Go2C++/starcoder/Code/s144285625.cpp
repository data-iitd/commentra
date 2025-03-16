
#include <bits/stdc++.h>

using namespace std;

// Initializing scanner for reading input from stdin
int main() {
	// Reading the number of elements in the array
	int n;
	cin >> n;

	// Allocating memory for the array
	int *ar = new int[3*n];

	// Reading elements of the array
	for (int i = 0; i < 3*n; i++) {
		// Reading next integer and storing it in the array
		cin >> ar[i];
	}

	// Sorting the array in ascending order
	sort(ar, ar+3*n);

	// Calculating the sum of elements at index 3n-2i-1 in the sorted array
	int sum = 0;
	for (int i = 0; i < n; i++) {
		// Adding the element at index 3n-2i-1 to the sum
		sum += ar[3*n-(i+1)*2];
	}

	// Printing the result
	cout << sum << endl;

	// Deallocating memory for the array
	delete[] ar;

	return 0;
}

