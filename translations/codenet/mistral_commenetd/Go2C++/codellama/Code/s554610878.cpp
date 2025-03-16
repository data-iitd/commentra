
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the absolute value of a number
int abs(int num) {
	return abs(num);
}

// Function to calculate the power of a number
int pow(int base, int exp) {
	return pow(base, exp);
}

// Function to find the minimum of given numbers
int min(int nums) {
	return min(nums);
}

// Function to find the maximum of given numbers
int max(int nums) {
	return max(nums);
}

// Function to check if a string is present in a slice of strings
bool strSearch(vector<string> slice, string str) {
	for (int i = 0; i < slice.size(); i++) {
		if (slice[i] == str) {
			return true;
		}
	}
	return false;
}

// Function to print an integer array
void printIntArray(vector<int> array) {
	cout << array << endl;
}

// Function to calculate the modulo of a number
int calcMod(int num) {
	return num % mod;
}

// Function to read a single line of input as string
string getString() {
	string s;
	cin >> s;
	return s;
}

// Function to read a single line of input as integer
int getInt() {
	int i;
	cin >> i;
	return i;
}

// Main function
int main() {
	// Initialize week array with 7 days of the week
	vector<string> week = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	// Read input string from scanner
	string s = getString();

	// Find index of the given day in week array
	int index = -1;
	for (int i = 0; i < week.size(); i++) {
		if (week[i] == s) {
			index = i;
			break;
		}
	}

	// If the given day is not present in the week array, panic with error message
	if (index == -1) {
		cout << "Invalid day of the week" << endl;
	}

	// Calculate the number of days between the given day and Sunday
	// and print the result
	int daysUntilSunday = 7 - index;
	cout << "The number of days until Sunday is: " << daysUntilSunday << endl;

	return 0;
}

