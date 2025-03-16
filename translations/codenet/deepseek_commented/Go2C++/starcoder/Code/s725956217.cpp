#include <bits/stdc++.h>

using namespace std;

// Helper function to print output.
void out(const vector<int> &x) {
	for (int i = 0; i < x.size(); i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

// Helper function to read input.
int getInt() {
	int x;
	cin >> x;
	return x;
}

// Helper function to read a string.
string getString() {
	string s;
	cin >> s;
	return s;
}

// Helper function to return the maximum of two integers.
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Helper function to return the minimum of two integers.
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Helper function to return the absolute difference between two integers.
int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

// Helper function to return the absolute value of an integer.
int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

// Helper function to find the lower bound index of a value in a sorted array.
int lowerBound(vector<int> &a, int x) {
	int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
	return idx;
}

// Helper function to find the upper bound index of a value in a sorted array.
int upperBound(vector<int> &a, int x) {
	int idx = upper_bound(a.begin(), a.end(), x) - a.begin();
	return idx;
}

// Struct to represent a shop with its price and stock.
struct shop {
	int a, b;
};

// Main function to execute the program logic.
int main() {
	// Read the number of shops and the amount of items to buy.
	int N, M = getInt(), getInt();

	// Create a vector of shops and read each shop's price and stock.
	vector<shop> s(N);
	for (int i = 0; i < N; i++) {
		int a, b = getInt(), getInt();
		s[i] = shop{a, b};
	}

	// Sort the shops by price.
	sort(s.begin(), s.end(), [](shop a, shop b) {
		return a.a < b.a;
	});

	// Calculate the total cost of buying the required number of items.
	int total = 0;
	for (auto e : s) {
		// Determine the number of items to buy from the current shop.
		int n = min(e.b, M);
		// Update the total cost and the remaining items to buy.
		total += n * e.a;
		M -= n;
		// Break if all items are bought.
		if (M == 0) {
			break;
		}
	}

	// Print the total cost.
	out(total);
}

