#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[100002]; // Declare array 'a' to store integers
int b[100002]; // Declare array 'b' to store evacuation routes

char buf[700002]; // Buffer for reading input

// Function to read an integer from the input buffer
int getint()
{
	int n = 0;
	if (buf[0] == '-') { // Check if the number is negative
		n = -atoi(buf+1); // Parse the negative number
		buf += strlen(buf+1)+1; // Skip the negative number
		return n;
	}
	n = atoi(buf); // Parse the positive number
	buf += strlen(buf)+1; // Skip the positive number
	return n;
}

int main()
{
	int w, i, k, f, close, ans; // Declare variables to store input, indices, and results

	scanf("%d", &w); // Read the width of the array and store it in 'w'
	scanf("%s", buf); // Read the input line into the buffer
	for (ans = 0, f = 0, i = 1; i <= w; i++) { // Initialize variables and start parsing the input
		a[i] = k = getint(); // Read the next integer and store it in 'a[i]'
		if (!k) f |= 1; // Set flag if zero is found
		else if (k < 0) f |= 2; // Set flag if negative number is found
		else ans += k; // Add to the sum if positive number
	}
	if (!ans || !(f & 1)) { printf("0\n"); return 0; } // If no positive numbers or zero found, output 0
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

