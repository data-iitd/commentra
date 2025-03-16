
#include <bits/stdc++.h>

using namespace std;

// Function to read a line text from stdin and return its string
string NextLine() {
	// Creating an input stream
	cin.sync_with_stdio(0);
	// Creating a string variable to hold the input stream
	string s;
	// Getting a line of input from stdin
	getline(cin, s);
	// Returning the string
	return s;
}

// Function to read a line text, that consists of ONLY INTEGERS DELIMITED BY SPACES, from stdin
// And then returns integers slice
vector<int> NextIntsLine() {
	// Creating an input stream
	cin.sync_with_stdio(0);
	// Creating a string variable to hold the input stream
	string s;
	// Getting a line of input from stdin
	getline(cin, s);
	// Creating an empty vector to hold the integers
	vector<int> v;
	// Splitting the line text by space
	stringstream ss(s);
	// Iterating through the split text and converting each string to integer
	// and appending it to the integers vector
	for (int i = 0; ss >> i;) {
		v.push_back(i);
		if (ss.peek() =='') {
			ss.ignore();
		}
	}
	// Returning the integers vector
	return v;
}

// Function to read a line text, that consists of ONLY CHARACTERS ARRANGED CONTINUOUSLY, from stdin
// And then returns runes slice
vector<char> NextRunesLine() {
	// Creating an input stream
	cin.sync_with_stdio(0);
	// Creating a string variable to hold the input stream
	string s;
	// Getting a line of input from stdin
	getline(cin, s);
	// Creating an empty vector to hold the runes
	vector<char> v;
	// Iterating through the line text and appending each character to the runes vector
	for (char c : s) {
		v.push_back(c);
	}
	// Returning the runes vector
	return v;
}

// Function to find the maximum integer among input integers
// This function needs at least 1 argument (no argument causes panic)
int Max(int integers[]) {
	// Initializing maximum integer as first integer
	int m = integers[0];
	// Iterating through the input integers
	for (int i = 1; i < sizeof(integers) / sizeof(int); i++) {
		// If current integer is greater than maximum integer, update maximum integer
		if (m < integers[i]) {
			m = integers[i];
		}
	}
	// Returning the maximum integer
	return m;
}

// Function to find the minimum integer among input integers
// This function needs at least 1 argument (no argument causes panic)
int Min(int integers[]) {
	// Initializing minimum integer as first integer
	int m = integers[0];
	// Iterating through the input integers
	for (int i = 1; i < sizeof(integers) / sizeof(int); i++) {
		// If current integer is smaller than minimum integer, update minimum integer
		if (m > integers[i]) {
			m = integers[i];
		}
	}
	// Returning the minimum integer
	return m;
}

// Function to calculate integer power
int PowInt(int a, int e) {
	// Checking for negative integers
	if (a < 0 || e < 0) {
		cerr << "[argument error]: PowInt does not accept negative integers" << endl;
		return -1;
	}
	// Converting base and exponent to float64
	float fa = (float)a;
	float fe = (float)e;
	// Calculating the power using pow
	float fanswer = pow(fa, fe);
	// Converting the answer back to integer
	return (int)fanswer;
}

// Function to calculate absolute value of an integer
int AbsInt(int a) {
	// Converting integer to float64
	float fa = (float)a;
	// Calculating the absolute value using abs
	float fanswer = abs(fa);
	// Converting the answer back to integer
	return (int)fanswer;
}

// Function to delete an element from a slice
vector<int> DeleteElement(vector<int> s, int i) {
	// Checking for negative index or empty slice
	if (i < 0 || s.size() <= i) {
		cerr << "[index error]" << endl;
		return s;
	}
	// Creating a new vector with zero capacity
	vector<int> n;
	// Appending elements before the index to the new vector
	for (int j = 0; j < i; j++) {
		n.push_back(s[j]);
	}
	// Appending elements after the index to the new vector
	for (int j = i + 1; j < s.size(); j++) {
		n.push_back(s[j]);
	}
	// Returning the new vector
	return n;
}

// Function to concatenate two slices
vector<char> Concat(vector<char> s, vector<char> t) {
	// Creating a new vector with zero capacity
	vector<char> n;
	// Appending elements of the first vector to the new vector
	for (char c : s) {
		n.push_back(c);
	}
	// Appending elements of the second vector to the new vector
	for (char c : t) {
		n.push_back(c);
	}
	// Returning the new vector
	return n;
}

// Function to sort a slice using sort package
//sort(s.begin(), s.end());
//sort(s.rbegin(), s.rend());
//sort(s.begin(), s.end(), greater<int>());
//sort(s.begin(), s.end(), [](int a, int b) { return a < b; });

// Function to copy elements from one slice to another
//a = []int{0, 1, 2}
//b = make([]int, len(a))
//copy(b, a)

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
}

