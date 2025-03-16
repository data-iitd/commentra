
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	// Initialize variables and read input
	// Code for A - Initialize variables and read input
	int N;
	cout << "Enter the number of elements in the array: ";
	cin >> N;

	int A[N];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	// Sort the array in ascending order
	// Code for C - Sort the array
	sort(A, A + N);

	// Calculate the answer
	// Code for D - Calculate the answer
	int ans = 0;
	cout << "Calculating the answer... ";
	for (int i = 1; i < N; i++) {
		ans += A[i] - A[i-1];
	}

	// Print the answer
	// Code for E - Print the answer
	cout << "The answer is: " << ans << endl;

	return 0;
}

