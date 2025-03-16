
// Package declaration for the main C++ program
#include <iostream>
#include <vector>
#include <algorithm>

// Initialize an integer variable 'n' and read its value from the standard input
int main() {
	int n;
	std::cin >> n;
}

// Create a vector 'a' of 'n' double elements
std::vector<double> a(n);

// Read 'n' double values from the standard input and assign them to the vector 'a'
for (int i = 0; i < n; i++) {
	std::cin >> a[i];
}

// Iterate through the vector 'a' 'n-1' times and sort it using the'std::sort' function
for (int i = 0; i+1 < n; i++) {
	std::sort(a.begin(), a.end());
}

// Initialize an empty vector 'na' of double
std::vector<double> na;

// Iterate through the vector 'a' starting from index 2 and append its elements to the vector 'na'
for (int j = 2; j < a.size(); j++) {
	na.push_back(a[j]);
}

// Reassign the value of the vector 'a' with the vector 'na' and the first two elements being the average of the first two elements of the original vector 'a'
na.push_back((a[0]+a[1])/2);
a = na;

// Print the first element of the sorted vector 'a' to the standard output
std::cout << a[0] << std::endl;

