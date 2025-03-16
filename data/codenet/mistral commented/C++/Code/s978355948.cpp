
#include <iostream>
#include <vector>

using namespace std;

// Main function starts here
int main(){
	// Initialize variables N and X with user input
	int N, X;
	cin >> N >> X;

	// Create a vector L of size N to store the elements
	vector<int> L(N);

	// Read elements of vector L from user input
	for(int i = 0; i < N; i++)
		cin >> L[i];

	// Initialize variable i and d to zero
	int i = 0, d = 0;

	// Loop through the vector L until the sum d exceeds X
	for(; i < N && d <= X; i++){
		// Add the current element of vector L to the sum d
		d += L[i];
	}

	// Print the index of the last element in the vector L that was added to the sum d
	cout << i+1 << endl;
}