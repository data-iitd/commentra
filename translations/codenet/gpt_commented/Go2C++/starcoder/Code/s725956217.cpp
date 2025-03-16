#include <bits/stdc++.h>

using namespace std;

// out is a utility function to print output to the console.
void out(const vector<int>& v) {
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
}

// sc is a scanner for reading input from standard input.
istream& operator>>(istream& is, vector<int>& v) {
	for (int& x : v) {
		is >> x;
	}
	return is;
}

// getInt reads an integer from input and returns it.
int getInt() {
	int x;
	cin >> x;
	return x;
}

// max returns the maximum of two integers.
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// min returns the minimum of two integers.
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// asub returns the absolute difference between two integers.
int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

// abs returns the absolute value of an integer.
int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

// lowerBound returns the index of the first element in a that is not less than x.
int lowerBound(vector<int>& a, int x) {
	int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
	return idx;
}

// upperBound returns the index of the first element in a that is greater than x.
int upperBound(vector<int>& a, int x) {
	int idx = upper_bound(a.begin(), a.end(), x) - a.begin();
	return idx;
}

// shop represents a shop with a price (a) and available quantity (b).
struct shop {
	int a, b;
};

// Datas is a slice of shop, implementing sort.Interface.
struct Datas : public vector<shop> {
	bool operator()(const shop& a, const shop& b) {
		return a.a < b.a; // Sort by price (a)
	}
};

// main is the entry point of the program.
int main() {
	int N, M;
	cin >> N >> M;
	Datas s(N); // Create a slice to hold the shops
	cin >> s; // Read the price and quantity for each shop
	sort(s.begin(), s.end()); // Sort the shops by price

	int total = 0; // Initialize total cost
	// Calculate the total cost based on available quantities and prices
	for (auto e : s) {
		int n = min(e.b, M); // Determine how much can be bought from this shop
		total += n * e.a; // Add to total cost
		M -= n; // Decrease the remaining quantity needed
		if (M == 0) {
			break; // Stop if the required quantity is met
		}
	}
	out(total); // Output the total cost
}

