
#include <bits/stdc++.h>

using namespace std;

// Function out is used for printing output to the console
void out(const vector<int> &x) {
	for (int i = 0; i < x.size(); i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

// Function getInt is used for reading an integer value from the standard input
int getInt() {
	int x;
	cin >> x;
	return x;
}

// Function getString is used for reading a string value from the standard input
string getString() {
	string s;
	cin >> s;
	return s;
}

// Function max returns the maximum value between two integers
int max(int a, int b) {
	// If the first integer is greater than the second integer, return the first integer
	if (a > b) {
		return a;
	}
	// Otherwise, return the second integer
	return b;
}

// Function min returns the minimum value between two integers
int min(int a, int b) {
	// If the first integer is less than the second integer, return the first integer
	if (a < b) {
		return a;
	}
	// Otherwise, return the second integer
	return b;
}

// Function asub returns the absolute difference between two integers
int asub(int a, int b) {
	// If the first integer is greater than the second integer, return the difference
	if (a > b) {
		return a - b;
	}
	// Otherwise, return the negative difference
	return b - a;
}

// Function abs returns the absolute value of an integer
int abs(int a) {
	// If the integer is greater than or equal to zero, return the integer itself
	if (a >= 0) {
		return a;
	}
	// Otherwise, return the negative of the integer
	return -a;
}

// Function lowerBound returns the index of the first element in the slice that is greater than or equal to the given value
int lowerBound(vector<int> &a, int x) {
	// Use the sort.Search function to find the index
	int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
	// Return the index
	return idx;
}

// Function upperBound returns the index of the first element in the slice that is greater than the given value
int upperBound(vector<int> &a, int x) {
	// Use the sort.Search function to find the index
	int idx = upper_bound(a.begin(), a.end(), x) - a.begin();
	// Return the index
	return idx;
}

// Type shop represents a data structure for storing two integers
struct shop {
	int a, b;
};

// Type Datas is a slice of shop data structures
typedef vector<shop> Datas;

// Function Len returns the length of the Datas slice
int Len(Datas p) {
	return p.size();
}

// Function Swap swaps the positions of two elements in the Datas slice
void Swap(Datas &p, int i, int j) {
	shop t = p[i];
	p[i] = p[j];
	p[j] = t;
}

// Function Less compares two shop data structures and returns true if the first one should come before the second one in a sorted slice
bool Less(shop a, shop b) {
	// Compare the 'a' fields of the two shop structures
	return a.a < b.a;
}

// Main function is the entry point of the program
int main() {
	// Initialize the scanner for reading input from the standard input
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Read the number of shops N and the number of customers M from the standard input
	int N, M = getInt();
	// Initialize a slice of shop data structures named s with a length of N
	Datas s(N);
	// For each shop in the slice
	for (int i = 0; i < N; i++) {
		// Read the capacity 'a' and demand 'b' of the shop from the standard input
		int a, b = getInt();
		// Create a new shop data structure with the read values and assign it to the i-th position in the slice
		s[i] = shop{a, b};
	}
	// Sort the slice in ascending order based on the 'a' field of each shop
	sort(s.begin(), s.end(), Less);

	// Initialize a variable named total to store the total capacity used by the shops
	int total = 0;
	// For each shop in the sorted slice
	for (auto e : s) {
		// Calculate the minimum capacity that can be served by the shop without exceeding the maximum demand
		int n = min(e.b, M);
		// Add the capacity of the shop multiplied by the number of customers it can serve to the total capacity
		total += n * e.a;
		// Decrease the maximum demand by the number of customers served by the shop
		M -= n;
		// If the maximum demand becomes zero, break the loop
		if (M == 0) {
			break;
		}
	}
	// Print the total capacity used by the shops
	out(total);
}

