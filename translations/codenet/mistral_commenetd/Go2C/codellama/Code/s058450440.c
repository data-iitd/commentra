
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining global variables
int a[1000000];
int ans = 0;

// Function to perform Depth First Search (DFS) algorithm
void dfs(int left, int i, int res) {
	if (left == 0) {
		ans += res;
		return;
	}

	for (int j = i; j < 1000000; j++) {
		dfs(left - 1, j + 1, res * a[j]);
	}
}

// Main function definition
int main() {
	// Initializing an io object for input/output handling
	char c;
	int n, i, j, left, res;
	int dic[1000000];

	// Reading the number of test cases
	scanf("%d", &n);

	// Initializing an empty map to store the frequency of each character
	for (i = 0; i < 1000000; i++) {
		dic[i] = 0;
	}

	// Reading strings and updating the map
	for (i = 0; i < n; i++) {
		scanf("%c", &c);
		switch (c) {
		case 'M':
		case 'A':
		case 'R':
		case 'C':
		case 'H':
			dic[c]++;
		}
	}

	// Converting map values to integers and appending them to the 'a' slice
	for (i = 0; i < 1000000; i++) {
		if (dic[i] != 0) {
			a[i] = dic[i];
		}
	}

	// Calling the 'dfs' function with initial arguments
	dfs(3, 0, 1);

	// Printing the answer
	printf("%d\n", ans);

	return 0;
}

// 