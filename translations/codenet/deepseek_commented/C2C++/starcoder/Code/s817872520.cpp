#include <bits/stdc++.h>

using namespace std;

#define INF 0x5fffffff // Define the maximum possible integer value
int a[100002]; // Declare array 'a' to store integers
int b[100002]; // Declare array 'b' to store evacuation routes

char buf[700002], *p; // Buffer for reading input and pointer for parsing

// Function to read an integer from the input buffer
int getint()
{
	int n = 0;
	if (*p == '-') { // Check if the number is negative
		p++; while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf); // Parse the negative number
		return -n;
	}
	while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf); // Parse the positive number
	return n;
}

int main()
{
	int w, i, k, f, close, ans; // Declare variables to store input, indices, and results

	fgets(p=buf, 10, stdin), w = getint(); // Read the width of the array and store it in 'w'
	fgets(p=buf, sizeof(buf), stdin); // Read the input line into the buffer
	for (ans = 0, f = 0, i = 1; i <= w; i++) { // Initialize variables and start parsing the input
		a[i] = k = getint(), p++; // Read the next integer and store it in 'a[i]'
		if (!k) f |= 1; // Set flag if zero is found
		else if (k < 0) f |= 2; // Set flag if negative number is found
		else ans += k; // Add to the sum if positive number
	}
	if (!ans ||!(f & 1)) { puts("0"); return 0; } // If no positive numbers or zero found, output 0
	if (!(f & 2)) { printf("%d\n", ans); return 0; } // If no negative numbers, output the sum of positive numbers

	// Calculate the minimum evacuation routes
	for (close = 0, f = 0, i = 1; i <= w; i++) { // First pass from left to right
		if (!a[i]) close = INF, f = -1; // Reset if zero is found
		else if (a[i] < 0) {
			if (f < 0 || close - (i-f) > -a[i]) close = -a[i], f = i; // Update the closest negative number
		} else {
			if (f < 0) b[i] = INF; // If no negative number found yet, set to INF
			else {
				k = close - (i-f); if (k < 0) k = 0; // Calculate the evacuation route
				b[i] = k;
			}
		}
	}

	for (close = 0, f = w, i = w; i >= 1; i--) { // Second pass from right to left
		if (!a[i]) close = INF, f = -1; // Reset if zero is found
		else if (a[i] < 0) {
			if (f < 0 || close - (f-i) > -a[i]) close = -a[i], f = i; // Update the closest negative number
		} else {
			if (f < 0) b[i] = INF; // If no negative number found yet, set to INF
			else {
				k = close - (f-i); if (k < 0) k = 0; // Calculate the evacuation route
				if (k > b[i]) b[i] = k; // Update if a better route is found
			}
		}
	}

	for (ans = 0, i = 1; i <= w; i++) { // Calculate the total evacuation route
		if (a[i] > 0) {
			if (b[i] > a[i]) ans += a[i]; // Add the minimum of b[i] and a[i]
			else             ans += b[i];
		}
	}
	printf("%d\n", ans); // Output the final result
	return 0;
}

