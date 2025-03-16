
#include<bits/stdc++.h>
// Include the standard input/output library

using namespace std;
// Include the standard namespace

int main(){
	int n, m, i, j;
	// Declare variables n, m, i, and j for reading input and performing calculations

	long long a[100000];
	// Declare a long long array 'a' of size n for storing the input elements

	cin >> n >> m;
	// Read the number of elements n and the number of queries m from the standard input

	for(i = 0; i < n; i++) cin >> a[i];
	// Read the elements of the array 'a' from the standard input

	for(i = 0; i < n; i++) push(a[i]);
	// Add each element of the array 'a' to the heap using the 'push' function

	for(i = 0; i < m; i++){
		long long tm = pop();
		// Pop an element from the heap

		tm /= 2;
		// Divide the popped element by 2

		push(tm);
		// Add the divided element back to the heap using the 'push' function
	}
	// Perform m queries by popping an element from the heap, dividing it by 2, and adding it back to the heap

	long long ans = 0;
	// Initialize the variable ans to 0 for storing the sum of the elements in the heap

	for(i = 0; i < n; i++) ans += heap[i];
	// Calculate the sum of the elements in the heap using a loop

	cout << ans << endl;
	// Print the sum of the elements in the heap to the standard output

	return 0;
	// Return 0 to indicate the successful execution of the program
}

