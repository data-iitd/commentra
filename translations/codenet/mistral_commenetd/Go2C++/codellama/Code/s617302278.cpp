
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to read a line text from stdin and return its string
string NextLine() {
	// Initializing an empty string
	string str = "";
	// Reading a line text from stdin
	getline(cin, str);
	// Returning the line text
	return str;
}

// Function to read a line text, that consists of ONLY INTEGERS DELIMITED BY SPACES, from stdin
// And then returns integers slice
vector<int> NextIntsLine() {
	// Initializing an empty vector
	vector<int> ints;
	// Reading a line text from stdin
	string str = NextLine();
	// Splitting the line text by space
	stringstream ss(str);
	// Iterating through the split text and converting each string to integer
	// and appending it to the integers slice
	for (int i; ss >> i;) {
		ints.push_back(i);
		if (ss.peek() == ' ') {
			ss.ignore();
		}
	}
	// Returning the integers slice
	return ints;
}

// Function to read a line text, that consists of ONLY CHARACTERS ARRANGED CONTINUOUSLY, from stdin
// And then returns runes slice
vector<char> NextRunesLine() {
	// Returning the next line text as runes slice
	return vector<char>(NextLine().begin(), NextLine().end());
}

// Function to find the maximum integer among input integers
// This function needs at least 1 argument (no argument causes panic)
int Max(vector<int> ints) {
	// Initializing maximum integer as first integer
	int m = ints[0];
	// Iterating through the input integers
	for (int i = 0; i < ints.size(); i++) {
		// If current integer is greater than maximum integer, update maximum integer
		if (i == 0) {
			continue;
		}
		if (m < ints[i]) {
			m = ints[i];
		}
	}
	// Returning the maximum integer
	return m;
}

// Function to find the minimum integer among input integers
// This function needs at least 1 argument (no argument causes panic)
int Min(vector<int> ints) {
	// Initializing minimum integer as first integer
	int m = ints[0];
	// Iterating through the input integers
	for (int i = 0; i < ints.size(); i++) {
		// If current integer is smaller than minimum integer, update minimum integer
		if (i == 0) {
			continue;
		}
		if (m > ints[i]) {
			m = ints[i];
		}
	}
	// Returning the minimum integer
	return m;
}

// Function to calculate integer power
int PowInt(int a, int e) {
	// Checking for negative integers
	if (a < 0 || e < 0) {
		panic(errors.New("[argument error]: PowInt does not accept negative integers"));
	}
	// Converting base and exponent to float64
	float fa = a;
	float fe = e;
	// Calculating the power using math.Pow
	float fanswer = pow(fa, fe);
	// Converting the answer back to integer
	return int(fanswer);
}

// Function to calculate absolute value of an integer
int AbsInt(int a) {
	// Converting integer to float64
	float fa = a;
	// Calculating the absolute value using math.Abs
	float fanswer = abs(fa);
	// Converting the answer back to integer
	return int(fanswer);
}

// Function to delete an element from a slice
vector<int> DeleteElement(vector<int> s, int i) {
	// Checking for negative index or empty slice
	if (i < 0 || s.size() <= i) {
		panic(errors.New("[index error]"));
	}
	// Creating a new slice with zero capacity
	vector<int> n;
	// Appending elements before the index to the new slice
	for (int j = 0; j < i; j++) {
		n.push_back(s[j]);
	}
	// Appending elements after the index to the new slice
	for (int j = i + 1; j < s.size(); j++) {
		n.push_back(s[j]);
	}
	// Returning the new slice
	return n;
}

// Function to concatenate two slices
vector<char> Concat(vector<char> s, vector<char> t) {
	// Creating a new slice with zero capacity
	vector<char> n;
	// Appending elements of the first slice to the new slice
	for (int i = 0; i < s.size(); i++) {
		n.push_back(s[i]);
	}
	// Appending elements of the second slice to the new slice
	for (int i = 0; i < t.size(); i++) {
		n.push_back(t[i]);
	}
	// Returning the new slice
	return n;
}

// Function to sort a slice using sort package
//sort(s.begin(), s.end());
//sort(s.rbegin(), s.rend());
//sort(s.begin(), s.end(), greater<int>());
//sort(s.rbegin(), s.rend(), greater<int>());

// Function to copy elements from one slice to another
//a = {0, 1, 2};
//b = vector<int>(a.size());
//copy(a.begin(), a.end(), b.begin());

// Variable declaration and initialization
int x;

// Main function
int main() {
	// Reading integers from stdin as a line text
	vector<int> tmp = NextIntsLine();
	// Assigning the first integer to variable x
	x = tmp[0];
	// Initializing sum variable as zero
	int sum = 0;
	// Initializing index variable as one
	int i = 1;
	// Looping until the sum is greater than or equal to x
	while (true) {
		// Adding current index to sum
		sum += i;
		// Checking if sum is greater than or equal to x
		if (sum >= x) {
			// Breaking the loop
			break;
		}
		// Incrementing index
		i++;
	}
	// Printing the index
	cout << i << endl;
	return 0;
}

