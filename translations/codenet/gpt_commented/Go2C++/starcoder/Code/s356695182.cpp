#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to read a specified number of integers from standard input and return them as a vector
vector<int> scanNums(int len) {
	vector<int> nums;
	int num;
	for (int i = 0; i < len; i++) {
		cin >> num; // Read an integer from standard input
		nums.push_back(num); // Append the integer to the vector
	}
	return nums; // Return the vector of integers
}

// Function to calculate a specific pattern based on the first five integers in the vector
int pattern1(vector<int> l) {
	int n = (l[0]*l[3]) + (l[1]*l[4]); // Calculate the result based on the formula
	return n; // Return the calculated value
}

// Function to calculate another pattern based on the maximum of the last two integers
int pattern2(vector<int> l) {
	int n = 2 * l[2] * max(l[3], l[4]); // Calculate the result using the maximum value
	return n; // Return the calculated value
}

// Function to calculate a third pattern that combines the minimum value and a function call
int pattern3(vector<int> l) {
	int n = 2*l[2]*min(l[3], l[4]) + doch(l); // Calculate the result using the minimum value and doch function
	return n; // Return the calculated value
}

// Function to return the minimum value from a variable number of integer arguments
int min(int nums[], int len) {
	if (len == 0) {
		cout << "function min() requires at least one argument." << endl; // Print an error message if no arguments are provided
		exit(1); // Exit the program
	}
	int res = nums[0]; // Initialize the result with the first argument
	for (int i = 0; i < len; i++) {
		res = min(res, nums[i]); // Update the result to the minimum value
	}
	return res; // Return the minimum value
}

// Function to return the maximum value from a variable number of integer arguments
int max(int nums[], int len) {
	if (len == 0) {
		cout << "function max() requires at least one argument." << endl; // Print an error message if no arguments are provided
		exit(1); // Exit the program
	}
	int res = nums[0]; // Initialize the result with the first argument
	for (int i = 0; i < len; i++) {
		res = max(res, nums[i]); // Update the result to the maximum value
	}
	return res; // Return the maximum value
}

// Function to calculate a value based on the difference between the last two integers in the vector
int doch(vector<int> l) {
	if (l[3] > l[4]) {
		return l[0] * (l[3] - l[4]); // Return the product if the fourth integer is greater
	} else {
		return l[1] * (l[4] - l[3]); // Return the product if the fifth integer is greater
	}
}

// Main function where the program execution begins
int main() {
	int len = 5; // Define the number of integers to read
	vector<int> l = scanNums(len); // Read the integers into a vector
	// Print the minimum value from the three calculated patterns
	cout << min(pattern1(l), pattern2(l), pattern3(l)) << endl;
	return 0;
}

