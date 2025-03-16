
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from standard input
int getInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// Function to read a string from standard input
char* getString() {
	char* s = (char*)malloc(100 * sizeof(char));
	scanf("%s", s);
	return s;
}

// Function to find the maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Function to find the minimum of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Function to find the absolute value of an integer
int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

// Main function
int main() {
	// Initialize variables: N, C, K, and array t
	int N, C, K, t[100000];

	// Read input: N, C, K
	N = getInt();
	C = getInt();
	K = getInt();

	// Read input: t[i] for i from 0 to N-1
	for (int i = 0; i < N; i++) {
		t[i] = getInt();
	}

	// Sort array t in ascending order
	qsort(t, N, sizeof(int), compare);

	// Initialize variables: answer counter ans, counter cnt, and end index end
	int ans = 1;
	int cnt = 1;
	int end = t[0] + K;

	// Iterate through array t from index 1 to N-1
	for (int i = 1; i < N; i++) {
		// If counter cnt is less than C and current element t[i] is within the range [end, end+K], increment counter cnt
		if (cnt < C && t[i] <= end) {
			cnt++;
		} else {
			// Reset counter cnt and update end index end to the current element t[i] plus K
			cnt = 1;
			end = t[i] + K;
			// Increment answer counter ans
			ans++;
		}
	}

	// Print the final answer
	printf("%d\n", ans);

	return 0;
}

// Function to compare two integers
int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

