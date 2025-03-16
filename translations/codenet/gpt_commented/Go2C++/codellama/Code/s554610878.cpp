
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// Constants for buffer sizes
const int initialBufSize = 10000;
const int maxBufSize = 1000000;

// Global variables for scanner and modulus
int mod = 1e9 + 7; // Modulus value for calculations

// Function to read an integer from input
int getInt() {
	int i; // Initialize variable for input
	cin >> i; // Read input
	return i; // Return the input
}

// Function to read a string from input
string getString() {
	string s; // Initialize variable for input
	cin >> s; // Read input
	return s; // Return the input
}

// Function to compute the absolute value of an integer
int abs(int a) {
	return abs(a); // Use abs function to get the absolute value
}

// Function to compute p raised to the power of q
int pow(int p, int q) {
	return pow(p, q); // Use pow function for exponentiation
}

// Function to find the minimum value among given integers
int min(int nums[]) {
	int res = nums[0]; // Initialize result with the first number
	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
		res = min(res, nums[i]); // Update result with the minimum value
	}
	return res; // Return the minimum value
}

// Function to find the maximum value among given integers
int max(int nums[]) {
	int res = nums[0]; // Initialize result with the first number
	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
		res = max(res, nums[i]); // Update result with the maximum value
	}
	return res; // Return the maximum value
}

// Function to check if a string exists in a vector of strings
bool strSearch(vector<string> a, string b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b) {
			return true; // Return true if the string is found
		}
	}
	return false; // Return false if the string is not found
}

// Function to print an array of integers
void printIntArray(int array[]) {
	string strArray = to_string(array); // Convert the array to a string
	cout << strArray.substr(1, strArray.size() - 2) << endl; // Print the string representation without brackets
}

// Function to calculate the modulus of x with respect to the defined mod
int calcMod(int x) {
	return x % mod; // Return the result of x modulo mod
}

int main() {
	// Array representing the days of the week
	vector<string> week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	
	// Get the input day as a string
	string s = getString();
	int index = -1; // Initialize index to -1 to indicate not found

	// Search for the input day in the week array
	for (int i = 0; i < week.size(); i++) {
		if (s == week[i]) {
			index = i; // Update index if the day is found
			break;
		}
	}

	// Calculate and print the number of days until the next Sunday
	cout << 7 - index << endl;
	return 0;
}

