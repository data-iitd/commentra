
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// out is a utility function to print output to the console.
void out(int x) {
	cout << x << endl;
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
int lowerBound(vector<int> a, int x) {
	int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
	return idx;
}

// upperBound returns the index of the first element in a that is greater than x.
int upperBound(vector<int> a, int x) {
	int idx = upper_bound(a.begin(), a.end(), x) - a.begin();
	return idx;
}

// shop represents a shop with a price (a) and available quantity (b).
struct shop {
	int a, b;
};

// Datas is a vector of shop, implementing sort.Interface.
struct Datas {
	vector<shop> a;

	int Len() {
		return a.size();
	}

	void Swap(int i, int j) {
		shop temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	bool Less(int i, int j) {
		return a[i].a < a[j].a; // Sort by price (a)
	}
};

// main is the entry point of the program.
int main() {
	// Read the number of shops (N) and the total quantity needed (M)
	int N, M = getInt(), getInt();
	Datas s; // Create a vector to hold the shops

	// Read the price and quantity for each shop
	for (int i = 0; i < N; i++) {
		int a, b = getInt(), getInt(); // Read price (a) and quantity (b)
		shop e = {a, b}; // Store the shop information
		s.a.push_back(e);
	}
	sort(s.a.begin(), s.a.end()); // Sort the shops by price

	int total = 0; // Initialize total cost
	// Calculate the total cost based on available quantities and prices
	for (int i = 0; i < s.Len(); i++) {
		int n = min(s.a[i].b, M); // Determine how much can be bought from this shop
		total += n * s.a[i].a; // Add to total cost
		M -= n; // Decrease the remaining quantity needed
		if (M == 0) {
			break; // Stop if the required quantity is met
		}
	}
	out(total); // Output the total cost

	return 0;
}

