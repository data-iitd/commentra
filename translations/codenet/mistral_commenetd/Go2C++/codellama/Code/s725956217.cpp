
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// Function getInt is used for reading an integer value from the standard input
int getInt() {
	int x;
	cin >> x;
	return x;
}

// Function getString is used for reading a string value from the standard input
string getString() {
	string x;
	cin >> x;
	return x;
}

// Function max returns the maximum value between two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Function min returns the minimum value between two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Function asub returns the absolute difference between two integers
int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

// Function abs returns the absolute value of an integer
int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

// Function lowerBound returns the index of the first element in the vector that is greater than or equal to the given value
int lowerBound(vector<int> a, int x) {
	int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
	return idx;
}

// Function upperBound returns the index of the first element in the vector that is greater than the given value
int upperBound(vector<int> a, int x) {
	int idx = upper_bound(a.begin(), a.end(), x) - a.begin();
	return idx;
}

// Structure shop represents a data structure for storing two integers
struct shop {
	int a, b;
};

// Function compareShops is used for comparing two shop structures
bool compareShops(shop a, shop b) {
	return a.a < b.a;
}

// Function solve is used for solving the problem
int solve() {
	// Read the number of shops N and the number of customers M from the standard input
	int N, M;
	cin >> N >> M;
	// Initialize a vector of shop structures named s with a length of N
	vector<shop> s(N);
	// For each shop in the vector
	for (int i = 0; i < N; i++) {
		// Read the capacity 'a' and demand 'b' of the shop from the standard input
		int a, b;
		cin >> a >> b;
		// Create a new shop structure with the read values and assign it to the i-th position in the vector
		s[i] = shop{a, b};
	}
	// Sort the vector in ascending order based on the 'a' field of each shop
	sort(s.begin(), s.end(), compareShops);

	// Initialize a variable named total to store the total capacity used by the shops
	int total = 0;
	// For each shop in the sorted vector
	for (int i = 0; i < N; i++) {
		// Calculate the minimum capacity that can be served by the shop without exceeding the maximum demand
		int n = min(s[i].b, M);
		// Add the capacity of the shop multiplied by the number of customers it can serve to the total capacity
		total += n * s[i].a;
		// Decrease the maximum demand by the number of customers served by the shop
		M -= n;
		// If the maximum demand becomes zero, break the loop
		if (M == 0) {
			break;
		}
	}
	// Return the total capacity used by the shops
	return total;
}

int main() {
	// Print the total capacity used by the shops
	cout << solve() << endl;
	return 0;
}

