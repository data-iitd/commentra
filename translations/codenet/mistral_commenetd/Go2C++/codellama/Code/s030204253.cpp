// Include the iostream header for formatted I/O operations
#include <iostream>

// Include the vector header for dynamic arrays
#include <vector>

// Include the algorithm header for sorting
#include <algorithm>

// Define the main function
int main() {
	// Declare an integer variable 'n' and read its value from the standard input
	int n;
	std::cin >> n;

	// Declare an array 'a' of 'n' float64 elements
	std::vector<float> a(n);

	// Read 'n' float64 values from the standard input and assign them to the array 'a'
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	// Iterate through the array 'a' 'n-1' times and sort it using the 'std::sort' function
	for (int i = 0; i + 1 < n; i++) {
		std::sort(a.begin(), a.end());
	}

	// Declare an empty vector 'na' of float64
	std::vector<float> na;

	// Iterate through the vector 'a' starting from index 2 and append its elements to the vector 'na'
	for (int j = 2; j < a.size(); j++) {
		na.push_back(a[j]);
	}

	// Reassign the value of the vector 'a' with the vector 'na' and the first two elements being the average of the first two elements of the original vector 'a'
	na.push_back((a[0] + a[1]) / 2);
	a = na;

	// Print the first element of the sorted vector 'a' to the standard output
	std::cout << a[0] << std::endl;

	return 0;
}

