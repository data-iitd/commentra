
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Function to read the next line of input as a string
string next() {
	string s;
	getline(cin, s);
	return s;
}

// Function to read the next line of input as an integer
int nextInt() {
	int i;
	string s = next();
	stringstream ss(s);
	ss >> i;
	return i;
}

// Function to read the next line of input as a float64
double nextFloat64() {
	double f;
	string s = next();
	stringstream ss(s);
	ss >> f;
	return f;
}

// Function to read 'n' integers from input and return them as a vector
vector<int> nextInts(int n) {
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = nextInt();
	}
	return a;
}

int main() {
	// Read two integers from input: n (number of elements) and k (some parameter)
	int n, k;
	cin >> n >> k;
	
	// Read 'n' integers into vector 'a'
	vector<int> a = nextInts(n);
	
	// Avoid unused variable error by assigning a value to the first element of 'a'
	a[0] = 0;

	// Initialize sum with the value of k and set ans to 1
	int sum = k;
	int ans = 1;
	
	// Loop to calculate how many times we can add k to the sum until it reaches or exceeds n
	while (sum < n) {
		sum = sum - 1 + k; // Update sum by subtracting 1 and adding k
		ans++; // Increment the answer counter
	}
	
	// Print the final answer
	cout << ans << endl;
	
	return 0;
}

