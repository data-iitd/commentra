#include <bits/stdc++.h>

using namespace std;

// Constants for buffer sizes
const int initialBufSize = 10000;
const int maxBufSize = 1000000;

// Global variables for scanner and modulus
int mod = 1e9 + 7; // Modulus value for calculations

// Function to read an integer from input
int getInt();

// Function to read a string from input
string getString();

// Function to compute the absolute value of an integer
int abs(int a);

// Function to compute p raised to the power of q
int pow(int p, int q);

// Function to find the minimum value among given integers
int min(int nums...);

// Function to find the maximum value among given integers
int max(int nums...);

// Function to check if a string exists in a slice of strings
bool strSearch(vector<string> a, string b);

// Function to print an array of integers
void printIntArray(vector<int> array);

// Function to calculate the modulus of x with respect to the defined mod
int calcMod(int x);

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
}

// Function to read an integer from input
int getInt() {
	int num;
	cin >> num;
	return num;
}

// Function to read a string from input
string getString() {
	string str;
	cin >> str;
	return str;
}

// Function to compute the absolute value of an integer
int abs(int a) {
	return a < 0? -a : a;
}

// Function to compute p raised to the power of q
int pow(int p, int q) {
	int res = 1;
	while (q > 0) {
		if (q & 1) {
			res = (res * p) % mod;
		}
		p = (p * p) % mod;
		q >>= 1;
	}
	return res;
}

// Function to find the minimum value among given integers
int min(int nums...) {
	if (nums.size() == 0) {
		throw invalid_argument("function min() requires at least one argument.");
	}
	int res = nums[0];
	for (int i = 0; i < nums.size(); i++) {
		res = min(res, nums[i]);
	}
	return res;
}

// Function to find the maximum value among given integers
int max(int nums...) {
	if (nums.size() == 0) {
		throw invalid_argument("function max() requires at least one argument.");
	}
	int res = nums[0];
	for (int i = 0; i < nums.size(); i++) {
		res = max(res, nums[i]);
	}
	return res;
}

// Function to check if a string exists in a slice of strings
bool strSearch(vector<string> a, string b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b) {
			return true;
		}
	}
	return false;
}

// Function to print an array of integers
void printIntArray(vector<int> array) {
	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

// Function to calculate the modulus of x with respect to the defined mod
int calcMod(int x) {
	return x % mod;
}

