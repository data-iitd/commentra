
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#define ll long long int
using namespace std;

// Initialize arrays h and w of size 6
int h[6], w[6];

int main() {
	int x, ans = 0; // Initialize x and ans to zero

	// Read input value of x from the user
	cin >> x;

	// Calculate the answer using the given formula
	ans = x + x*x + x*x*x;

	// Output the answer to the user
	cout << ans << endl;

	return 0;
}