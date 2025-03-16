

#include <iostream> // Include the necessary header files for input/output operations
#include <vector> // Include the necessary header file for vector operations
#include <algorithm> // Include the necessary header file for sorting operations

using namespace std; // Use the standard namespace for input/output operations

int main() {
	vector<int> ns(4); // Create a vector of integers with a length of 4
	for (int i = 0; i < 4; i++) { // Read four integers from the input and store them in the vector ns
		cin >> ns[i];
	}

	sort(ns.begin(), ns.end()); // Sort the vector ns in ascending order
	if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) { // Check if the sorted vector ns contains the numbers 1, 4, 7, and 9 in that order
		cout << "YES" << endl; // Print "YES" if the condition is true
	} else {
		cout << "NO" << endl; // Print "NO" if the condition is false
	}

	return 0; // Return 0 to indicate successful execution of the program
}

