#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables to store input values
int N, ss, ans, A, B, C;

// Function to read input
char* nextLine() {
	char* line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);
	return line;
}

// Function to calculate the cost based on the chosen combinations
int calc(int* dp, int* arr) {
	int cost = 0, AA = 0, BB = 0, CC = 0;
	int memo[4] = {0};

	// Create a memoization array to count the occurrences of each choice
	for (int i = 0; i < N; i++) {
		memo[dp[i]]++;
		if (dp[i] == 1) {
			AA += arr[i];
		} else if (dp[i] == 2) {
			BB += arr[i];
		} else if (dp[i] == 3) {
			CC += arr[i];
		}
	}
	cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

	// Add additional cost for each choice that appears more than once
	for (int i = 1; i < 4; i++) {
		int a = memo[i];
		if (a < 1) {
			cost += 10000;
		} else {
			cost += (a - 1) * 10;
		}
	}

	return cost;
}

// Function to explore different combinations of choices
void dfs(int* dp, int times, int* arr) {
	if (times >= N) {
		ans = min(ans, calc(dp, arr));
		return;
	}

	for (int i = 0; i < 4; i++) {
		dp[times] = i;
		dfs(dp, times + 1, arr);
	}
}

// Function to calculate the minimum cost
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Function to calculate the absolute value
int abs(int a) {
	if (a < 0) {
		return a * -1;
	}
	return a;
}

// Main function to execute the program
int main() {
	// Read the input values for N, A, B, and C
	char* line = nextLine();
	char* token = strtok(line, " ");
	N = atoi(token);
	token = strtok(NULL, " ");
	A = atoi(token);
	token = strtok(NULL, " ");
	B = atoi(token);
	token = strtok(NULL, " ");
	C = atoi(token);

	// Initialize the array to store the values and a dp array for choices
	int* arr = (int*)malloc(N * sizeof(int));
	int* dp = (int*)malloc(N * sizeof(int));
	ans = 10000;
	ss = A + B + C;

	// Read the array values from input
	for (int i = 0; i < N; i++) {
		line = nextLine();
		token = strtok(line, " ");
		arr[i] = atoi(token);
	}

	// Start the depth-first search to find the minimum cost
	dfs(dp, 0, arr);

	// Print the minimum cost found
	printf("%d\n", ans);
	return 0;
}

