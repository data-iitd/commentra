
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// Helper function to print output.
void out(int x) {
	cout << x << endl;
}

// Function to return the maximum of two integers.
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Function to return the minimum of two integers.
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Function to return the absolute difference between two integers.
int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

// Function to return the absolute value of an integer.
int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

// Function to find the lower bound index of a value in a sorted array.
int lowerBound(vector<int> a, int x) {
	int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
	return idx;
}

// Function to find the upper bound index of a value in a sorted array.
int upperBound(vector<int> a, int x) {
	int idx = upper_bound(a.begin(), a.end(), x) - a.begin();
	return idx;
}

// Struct to represent a shop with its price and stock.
struct shop {
	int a, b;
};

// Slice of shops to implement sorting.
struct Datas {
	vector<shop> s;
};

// Implementing sort.Interface for Datas.
bool operator<(const shop& a, const shop& b) {
	return a.a < b.a;
}

// Main function to execute the program logic.
int main() {
	// Read the number of shops and the amount of items to buy.
	int N, M;
	cin >> N >> M;

	// Create a slice of shops and read each shop's price and stock.
	Datas s;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		s.s.push_back(shop{a, b});
	}

	// Sort the shops by price.
	sort(s.s.begin(), s.s.end());

	// Calculate the total cost of buying the required number of items.
	int total = 0;
	for (int i = 0; i < N; i++) {
		// Determine the number of items to buy from the current shop.
		int n = min(s.s[i].b, M);
		// Update the total cost and the remaining items to buy.
		total += n * s.s[i].a;
		M -= n;
		// Break if all items are bought.
		if (M == 0) {
			break;
		}
	}

	// Print the total cost.
	out(total);

	return 0;
}

