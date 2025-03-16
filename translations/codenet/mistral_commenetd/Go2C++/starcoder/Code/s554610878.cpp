
#include <bits/stdc++.h>

using namespace std;

// Function to calculate the absolute value of a number
int abs(int num) {
	return num < 0? -num : num;
}

// Function to calculate the power of a number
int pow(int base, int exp) {
	int result = 1;
	while (exp > 0) {
		if (exp & 1) {
			result *= base;
		}
		base *= base;
		exp >>= 1;
	}
	return result;
}

// Function to find the minimum of given numbers
int min(int nums[], int n) {
	if (n == 0) {
		return INT_MAX;
	}
	int min = nums[0];
	for (int i = 1; i < n; i++) {
		if (nums[i] < min) {
			min = nums[i];
		}
	}
	return min;
}

// Function to find the maximum of given numbers
int max(int nums[], int n) {
	if (n == 0) {
		return INT_MIN;
	}
	int max = nums[0];
	for (int i = 1; i < n; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
	}
	return max;
}

// Function to check if a string is present in a slice of strings
bool strSearch(string arr[], int n, string str) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == str) {
			return true;
		}
	}
	return false;
}

// Function to print an integer array
void printIntArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Function to calculate the modulo of a number
int calcMod(int num) {
	return num % 1000000007;
}

// Function to read a single line of input as string
string getString() {
	string str;
	getline(cin, str);
	return str;
}

// Function to read a single line of input as integer
int getInt() {
	string str;
	getline(cin, str);
	return stoi(str);
}

// Main function
int main() {
	// Initialize week array with 7 days of the week
	string week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	// Read input string from scanner
	string s = getString();

	// Find index of the given day in week array
	int index = -1;
	for (int i = 0; i < 7; i++) {
		if (s == week[i]) {
			index = i;
			break;
		}
	}

	// If the given day is not present in the week array, panic with error message
	if (index == -1) {
		cout << "Invalid day of the week" << endl;
		return 0;
	}

	// Calculate the number of days between the given day and Sunday
	// and print the result
	int daysUntilSunday = 7 - index;
	cout << "The number of days until Sunday is: " << daysUntilSunday << endl;
}

// 