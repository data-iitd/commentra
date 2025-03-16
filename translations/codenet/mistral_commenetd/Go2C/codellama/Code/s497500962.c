#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Main function is the entry point of the program
int main() {
	// Initialize variables R, G, B, and N with next integers
	int R = nextInt();
	int G = nextInt();
	int B = nextInt();
	int N = nextInt();

	// Initialize variable ans with zero
	int ans = 0;

	// Nested for loops to iterate through all possible combinations of x and y within the range of N
	for (int x = 0; x <= N; x++) {
		for (int y = 0; y <= N; y++) {
			// Calculate temporary variable tmp
			int tmp = N - R*x - G*y;

			// Check if tmp is non-negative and the remainder of tmp when divided by B is zero
			if (tmp >= 0 && tmp%B == 0) {
				// Increment the value of ans if the condition is true
				ans++;
			}
		}
	}

	// Print the value of ans
	printf("%d\n", ans);

	return 0;
}

// Input related functions
int nextInt() {
	// Read next word as string, convert it to integer, and return
	char str[100];
	scanf("%s", str);
	int i = atoi(str);
	return i;
}

int nextFloat() {
	// Read next word as string, convert it to float64, and return
	char str[100];
	scanf("%s", str);
	float f64 = atof(str);
	return f64;
}

char nextString() {
	// Read next word as string and return
	char str[100];
	scanf("%s", str);
	return str;
}

// Utility functions
int abs(int x) {
	// Return absolute value of x
	return (int)abs(x);
}

int min(int x, int y) {
	// Return minimum value of x and y
	return (int)min(x, y);
}

int max(int x, int y) {
	// Return maximum value of x and y
	return (int)max(x, y);
}

