#include <bits/stdc++.h>

using namespace std;

// Function to compute the minimum total distance to a median value
void solve() {
	// Read the number of elements
	int n = getInt();
	// Read the integer slice of size n
	vector<int> as = getIntSlice(n);

	// Create a new slice to store adjusted values
	vector<int> xs(n);
	for (int i = 0; i < n; i++) {
		// Adjust each element by subtracting its index and adding 1
		xs[i] = as[i] - i + 1;
	}
	// Sort the adjusted values
	sort(xs.begin(), xs.end());

	// Find the median value from the sorted slice
	int b = xs[n / 2];
	int ans = 0;
	// Calculate the total distance from each element to the median
	for (int x : xs) {
		ans += abs(x - b);
	}
	// Output the result
	printf("%d\n", ans);
}

// Function to return the absolute value of an integer
int abs(int n) {
	if (n < 0) {
		return -n;
	}
	return n;
}

// -----------------------------------------

const int inf = 1 << 60; // A constant representing infinity
// const int mod = 1000000007; // Uncomment if modular arithmetic is needed

// Input and output
#ifndef ONLINE_JUDGE
	// Redirecting inputs to input.txt and outputs to output.txt
	#define FILEIO
	#ifdef FILEIO
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
#endif

// Constants
#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vpii vector<pii>
#define vll vector<long long>
#define vvl vector<vll>
#define vvll vector<vll>
#define vvl vector<vvl>
#define vvpii vector<vpii>
#define vvvpii vector<vvpii>
#define vvvvpii vector<vvvpii>
#define vvvvvpii vector<vvvvpii>
#define vvvvvvpii vector<vvvvvpii>
#define vvvvvvvpii vector<vvvvvvpii>
#define vvvvvvvvpii vector<vvvvvvvpii>
#define vvvvvvvvvpii vector<vvvvvvvvpii>
#define vvvvvvvvvvpii vector<vvvvvvvvvpii>
#define vvvvvvvvvvvpii vector<vvvvvvvvvvpii>
#define vvvvvvvvvvvvpii vector<vvvvvvvvvvvpii>
#define vvvvvvvvvvvvvpii vector<vvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii vector<vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvpii>
#define vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv