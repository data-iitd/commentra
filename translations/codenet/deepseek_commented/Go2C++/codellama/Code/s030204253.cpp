#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; // Declare an integer variable to store the number of elements
	cin >> n; // Read the value of n from the standard input
	vector<double> a(n); // Create a vector of double with n elements
	for (int i = 0; i < n; i++) {
		cin >> a[i]; // Read n floating-point numbers from the standard input to populate the vector a
	}
	for (int i = 0; i+1 < n; i++) { // Enter a loop that continues until only one element remains in the vector a
		sort(a.begin(), a.end()); // Sort the vector a in ascending order
		vector<double> na; // Create a new vector na to store the updated elements
		for (int j = 2; j < a.size(); j++) { // Iterate over the vector a starting from the third element
			na.push_back(a[j]); // Append the elements from a to na, excluding the first two
		}
		na.push_back((a[0]+a[1])/2); // Append the average of the first two elements to na
		a = na; // Update the vector a with the new vector na
	}
	cout << a[0] << endl; // Print the single remaining element in the vector a
	return 0;
}


