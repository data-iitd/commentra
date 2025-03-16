
#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

// Define input variables and some auxiliary variables
int n, a[50], p, b = 0, c = 0;

// Function to calculate nPr (n choose r)
ll nPr(ll n, ll r) {
	// Initialize result to 1
	ll res = 1;
	// Iterate from 0 to r and multiply result with (n-i)
	for (int i = 0; i < r; i++) {
		res *= (n - i);
		// Add comment explaining what is being done
		// Multiply result with factorial of (n-i)
		// to get the value of nPr(n, r)
		//cout << "Calculating nPr(" << n << ", " << r << ") = " << res << endl;
	}

	// Return the result
	return res;
}

// Function to calculate nCr (n choose r)
ll nCr(ll n, ll r) {
	// Initialize result to 1
	double res = 1;
	// Iterate from 0 to r and multiply result with (n-i) and divide by (i+1)
	for (int i = 0; i < r; i++) {
		res *= (n - i);
		res /= (i+1);
		// Add comment explaining what is being done
		// Multiply result with factorial of (n-i) and divide by (i+1)
		// to get the value of nCr(n, r)
		//cout << "Calculating nCr(" << n << ", " << r << ") = " << res << endl;
	}
	// Convert the double result to long long and return it
	return (ll)res;
}

// Main function
int main() {
	// Read input values of n and p from the user
	cin >> n >> p;
	// Initialize b and c to count the number of even and odd elements in the array a
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			b++;
		}
		else {
			c++;
		}
		// Add comment explaining what is being done
		// Read an element from the array a and check if it is even or odd
		// Increment the corresponding counter (b for even and c for odd)
	}

	// Calculate the sum of 2^b and c
	ll bsum = 1, csum = 0;
	bsum = pow(2, b);

	// Calculate the sum of nCr(c, i) for i from 0 to c
	if (p == 0) {
		for (int i = 0; i <= c; i++) {
			if (i % 2 == 0) {
				csum += nCr(c, i);
			}
			// Add comment explaining what is being done
			// If i is even, add nCr(c, i) to csum
		}
	}
	else {
		for (int i = 0; i <= c; i++) {
			if (i % 2 == 1) {
				csum += nCr(c, i);
			}
			// Add comment explaining what is being done
			// If i is odd, add nCr(c, i) to csum
		}
	}

	// Multiply bsum and csum and store the result in ans
	ll ans = bsum * csum;
	// Add comment explaining what is being done
	// Multiply bsum and csum to get the final answer

	// Print the final answer
	cout << ans << endl;
}

