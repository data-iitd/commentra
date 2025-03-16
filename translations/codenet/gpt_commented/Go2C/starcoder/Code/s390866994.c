

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

// Function to print output to the console
void out(int x,...) {
	va_list args;
	va_start(args, x);
	vprintf(x, args);
	va_end(args);
}

// Function to read an integer from input
int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// Function to read a string from input
char* getString() {
	char* x = malloc(1000000);
	scanf("%s", x);
	return x;
}

// Basic utility functions for mathematical operations
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

int main() {
	// Read the number of elements (N), maximum count (C), and time limit (K)
	int N = getInt(), C = getInt(), K = getInt();
	int* t = malloc(N * sizeof(int));

	// Read N time values from input
	for (int i = 0; i < N; i++) {
		t[i] = getInt();
	}

	// Sort the time values in ascending order
	qsort(t, N, sizeof(int), NULL);

	// Initialize variables for counting groups and tracking the end time
	int ans = 1; // Start with one group
	int cnt = 1; // Count of elements in the current group
	int end = t[0] + K; // Calculate the end time for the first group

	// Iterate through the sorted time values
	for (int i = 1; i < N; i++) {
		// Check if we can add the current time to the current group
		if (cnt < C && t[i] <= end) {
			cnt++; // Increment the count of the current group
		} else {
			// Start a new group since the current time exceeds the end time
			cnt = 1; // Reset the count for the new group
			end = t[i] + K; // Update the end time for the new group
			ans++; // Increment the group count
		}
	}
	out("%d", ans); // Output the total number of groups formed
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

// Function to print output to the console
void out(int x,...) {
	va_list args;
	va_start(args, x);
	vprintf(x, args);
	va_end(args);
}

// Function to read an integer from input
int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// Function to read a string from input
char* getString() {
	char* x = malloc(1000000);
	scanf("%s", x);
	return x;
}

// Basic utility functions for mathematical operations
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

int main() {
	// Read the number of elements (N), maximum count (C), and time limit (K)
	int N = getInt(), C = getInt(), K = getInt();
	int* t = malloc(N * sizeof(int));

	// Read N time values from input
	for (int i = 0; i < N; i++) {
		t[i] = getInt();
	}

	// Sort the time values in ascending order
	qsort(t, N, sizeof(int), NULL);

	// Initialize variables for counting groups and tracking the end time
	int ans = 1; // Start with one group
	int cnt = 1; // Count of elements in the current group
	int end = t[0] + K; // Calculate the end time for the first group

	// Iterate through the sorted time values
	for (int i = 1; i < N; i++) {
		// Check if we can add the current time to the current group
		if (cnt < C && t[i] <= end) {
			cnt++; // Increment the count of the current group
		} else {
			// Start a new group since the current time exceeds the end time
			cnt = 1; // Reset the count for the new group
			end = t[i] + K; // Update the end time for the new group
			ans++; // Increment the group count
		}
	}
	out("%d", ans); // Output the total number of groups formed
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

// Function to print output to the console
void out(int x,...) {
	va_list args;
	va_start(args, x);
	vprintf(x, args);
	va_end(args);
}

// Function to read an integer from input
int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// Function to read a string from input
char* getString() {
	char* x = malloc(1000000);
	scanf("%s", x);
	return x;
}

// Basic utility functions for mathematical operations
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

int main() {
	// Read the number of elements (N), maximum count (C), and time limit (K)
	int N = getInt(), C = getInt(), K = getInt();
	int* t = malloc(N * sizeof(int));

	// Read N time values from input
	for (int i = 0; i < N; i++) {
		t[i] = getInt();
	}

	// Sort the time values in ascending order
	qsort(t, N, sizeof(int), NULL);

	// Initialize variables for counting groups and tracking the end time
	int ans = 1; // Start with one group
	int cnt = 1; // Count of elements in the current group
	int end = t[0] + K; // Calculate the end time for the first group

	// Iterate through the sorted time values
	for (int i = 1; i < N; i++) {
		// Check if we can add the current time to the current group
		if (cnt < C && t[i] <= end) {
			cnt++; // Increment the count of the current group
		} else {
			// Start a new group since the current time exceeds the end time
			cnt = 1; // Reset the count for the new group
			end = t[i] + K; // Update the end time for the new group
			ans++; // Increment the group count
		}
	}
	out("%d", ans); // Output the total number of groups formed
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

// Function to print output to the console
void out(int x,...) {
	va_list args;
	va_start(args, x);
	vprintf(x, args);
	va_end(args);
}

// Function to read an integer from input
int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// Function to read a string from input
char* getString() {
	char* x = malloc(1000000);
	scanf("%s", x);
	return x;
}

// Basic utility functions for mathematical operations
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

int main() {
	// Read the number of elements (N), maximum count (C), and time limit (K)
	int N = getInt(), C = getInt(), K = getInt();
	int* t = malloc(N * sizeof(int));

	// Read N time values from input
	for (int i = 0; i < N; i++) {
		t[i] = getInt();
	}

	// Sort the time values in ascending order
	qsort(t, N, sizeof(int), NULL);

	// Initialize variables for counting groups and tracking the end time
	int ans = 1; // Start with one group
	int cnt = 1; // Count of elements in the current group
	int end = t[0] + K; // Calculate the end time for the first group

	// Iterate through the sorted time values
	for (int i = 1; i < N; i++) {
		// Check if we can add the current time to the current group
		if (cnt < C && t[i] <= end) {
			cnt++; // Increment the count of the current group
		} else {
			// Start a new group since the current time exceeds the end time
			cnt = 1; // Reset the count for the new group
			end = t[i] + K; // Update the end time for the new group
			ans++; // Increment the group count
		}
	}
	out("%d", ans); // Output the total number of groups formed
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

// Function to print output to the console
void out(int x,...) {
	va_list args;
	va_start(args, x);
	vprintf(x, args);
	va_end(args);
}

// Function to read an integer from input
int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// Function to read a string from input
char* getString() {
	char* x = malloc(1000000);
	scanf("%s", x);
	return x;
}

// Basic utility functions for mathematical operations
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

int main() {
	// Read the number of elements (N), maximum count (C), and time limit (K)
	int N = getInt(), C = getInt(), K = getInt();
	int* t = malloc(N * sizeof(int));

	// Read N time values from input
	for (int i = 0; i < N; i++) {
		t[i] = getInt();
	}

	// Sort the time values in ascending order
	qsort(t, N, sizeof(int), NULL);

	// Initialize variables for counting groups and tracking the end time
	int ans = 1; // Start with one group
	int cnt = 1; // Count of elements in the current group
	int end = t[0] + K; // Calculate the end time for the first group

	// Iterate through the sorted time values
	for (int i = 1; i < N; i++) {
		// Check if we can add the current time to the current group
		if (cnt < C && t[i] <= end) {
			cnt++; // Increment the count of the current group
		} else {
			// Start a new group since the current time exceeds the end time
			cnt = 1; // Reset the count for the new group
			end = t[i] + K; // Update the end time for the new group
			ans++; // Increment the group count
		}
	}
	out("%d", ans); // Output the total number of groups formed
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

// Function to print output to the console
void out(int x,...) {
	va_list args;
	va_start(args, x);
	vprintf(x, args);
	va_end(args);
}

// Function to read an integer from input
int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// Function to read a string from input
char* getString() {
	char* x = malloc(1000000);
	scanf("%s", x);
	return x;
}

// Basic utility functions for mathematical operations
int max(int a, int b)