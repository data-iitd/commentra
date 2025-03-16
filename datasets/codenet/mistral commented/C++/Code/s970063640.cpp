
#include <iostream>
#include <algorithm> // Include the algorithm library for sorting the array
using namespace std;

int main(){
	// Declare and initialize variables
	int n; // Number of elements in the array
	cin >> n; // Read the number of elements from the user
	int a; // Size of the subarray to be summed
	cin >> a; // Read the size of the subarray from the user
	int sum = 0; // Initialize the sum variable to zero
	int s[n]; // Declare an array of size n to store the input elements

	// Read the elements of the array from the user
	for(int i=0;i<n;i++){
		cin >> s[i]; // Read the i-th element of the array
	}

	// Sort the array in ascending order
	sort(s,s+n); // Sort the array using the sort function from the algorithm library

	// Calculate the sum of the last 'a' elements of the sorted array
	for(int i=n-1;i>n-a-1;i--){
		sum += s[i]; // Add the current element to the sum
	}

	// Print the result
	cout << sum << endl; // Print the sum of the last 'a' elements
	return 0; // Indicate successful termination of the program
}