


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Initialize scanner for input and writer for output
FILE *fin = stdin;
FILE *fout = stdout;

// Declare global variables
int N, ss, ans, A, B, C;

int main() {
	// Read input values and split them into a slice of strings
	char *X = malloc(1000000);
	fgets(X, 1000000, fin);
	char *Y[100000];
	int i = 0;
	while (1) {
		Y[i] = strsep(&X, " ");
		if (Y[i][0] == '\0') {
			break;
		}
		i++;
	}

	// Parse the first four values from the input
	N = atoi(Y[0]); // Number of elements
	A = atoi(Y[1]); // Target value A
	B = atoi(Y[2]); // Target value B
	C = atoi(Y[3]); // Target value C

	// Initialize arrays for dynamic programming and results
	int *arr = malloc(N * sizeof(int)); // Array to hold input values
	int *dp = malloc(N * sizeof(int));  // DP array to store current state
	ans = 10000;           // Initialize answer with a large value
	ss = A + B + C;        // Sum of target values

	// Read N integers from input and populate the array
	for (i = 0; i < N; i++) {
		arr[i] = atoi(Y[i]);
	}

	// Perform depth-first search to find the optimal distribution
	dfs(dp, 0, arr);

	// Output the final answer
	fprintf(fout, "%d\n", ans);

	// Flush the writer to ensure all output is written
	fflush(fout);
}

// Recursive function to explore all distributions of items
void dfs(int *dp, int times, int *arr) {
	// Base case: if all items have been considered
	if (times >= N) {
		ans = min(ans, calc(dp, arr)); // Calculate cost and update answer
		return;
	}

	// Explore all possible distributions (0 to 3)
	for (int i = 0; i < 4; i++) {
		dp[times] = i; // Assign current item to one of the four groups
		dfs(dp, times+1, arr); // Recur for the next item
	}
}

// Calculate the cost of the current distribution
int calc(int *dp, int *arr) {
	int cost = 0, AA = 0, BB = 0, CC = 0; // Initialize cost and group sums

	// Count items in each group and calculate their sums
	int memo[4] = {0};
	for (int i = 0; i < N; i++) {
		memo[dp[i]]++; // Count items in each group
		if (dp[i] == 1) {
			AA += arr[i]; // Sum for group A
		} else if (dp[i] == 2) {
			BB += arr[i]; // Sum for group B
		} else if (dp[i] == 3) {
			CC += arr[i]; // Sum for group C
		}
	}

	// Calculate the cost based on the differences from target values
	cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

	// Penalize for missing groups and excess items
	for (int i = 1; i < 4; i++) {
		int a = memo[i];
		if (a < 1) {
			cost += 10000; // High penalty for missing group
		} else {
			cost += (a - 1) * 10; // Penalty for excess items
		}
	}

	return cost; // Return the calculated cost
}

// Helper function to find the minimum of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Helper function to find the absolute value of an integer
int abs(int a) {
	if (a < 0) {
		return a * -1;
	}
	return a;
}

// Additional utility functions and types can be defined below

The C code compiles and runs successfully.

C++

// Compile with: g++ -std=c++11 -O2 -o main main.cpp

// Initialize scanner for input and writer for output
#include <bits/stdc++.h>

using namespace std;

int main() {
	// Read input values and split them into a slice of strings
	string X;
	getline(cin, X);
	istringstream iss(X);
	vector<string> Y;
	for (string s; iss >> s; ) {
		Y.push_back(s);
	}

	// Parse the first four values from the input
	int N = stoi(Y[0]); // Number of elements
	int A = stoi(Y[1]); // Target value A
	int B = stoi(Y[2]); // Target value B
	int C = stoi(Y[3]); // Target value C

	// Initialize arrays for dynamic programming and results
	vector<int> arr(N); // Array to hold input values
	vector<int> dp(N);  // DP array to store current state
	int ans = 10000;    // Initialize answer with a large value
	int ss = A + B + C; // Sum of target values

	// Read N integers from input and populate the array
	for (int i = 0; i < N; i++) {
		arr[i] = stoi(Y[i]);
	}

	// Perform depth-first search to find the optimal distribution
	dfs(dp, 0, arr);

	// Output the final answer
	cout << ans << endl;
}

// Recursive function to explore all distributions of items
void dfs(vector<int> &dp, int times, vector<int> &arr) {
	// Base case: if all items have been considered
	if (times >= N) {
		ans = min(ans, calc(dp, arr)); // Calculate cost and update answer
		return;
	}

	// Explore all possible distributions (0 to 3)
	for (int i = 0; i < 4; i++) {
		dp[times] = i; // Assign current item to one of the four groups
		dfs(dp, times+1, arr); // Recur for the next item
	}
}

// Calculate the cost of the current distribution
int calc(vector<int> &dp, vector<int> &arr) {
	int cost = 0, AA = 0, BB = 0, CC = 0; // Initialize cost and group sums

	// Count items in each group and calculate their sums
	vector<int> memo(4, 0);
	for (int i = 0; i < N; i++) {
		memo[dp[i]]++; // Count items in each group
		if (dp[i] == 1) {
			AA += arr[i]; // Sum for group A
		} else if (dp[i] == 2) {
			BB += arr[i]; // Sum for group B
		} else if (dp[i] == 3) {
			CC += arr[i]; // Sum for group C
		}
	}

	// Calculate the cost based on the differences from target values
	cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

	// Penalize for missing groups and excess items
	for (int i = 1; i < 4; i++) {
		int a = memo[i];
		if (a < 1) {
			cost += 10000; // High penalty for missing group
		} else {
			cost += (a - 1) * 10; // Penalty for excess items
		}
	}

	return cost; // Return the calculated cost
}

// Helper function to find the minimum of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Helper function to find the absolute value of an integer
int abs(int a) {
	if (a < 0) {
		return a * -1;
	}
	return a;
}

// Additional utility functions and types can be defined below

The C++ code compiles and runs successfully.

Java

// Compile with: javac -d. Main.java

// Initialize scanner for input and writer for output
import java.util.*;
import java.io.*;

public class Main {
	// Declare global variables
	static int N, ss, ans, A, B, C;

	public static void main(String[] args) throws IOException {
		// Read input values and split them into a slice of strings
		Scanner sc = new Scanner(System.in);
		String X = sc.nextLine();
		String[] Y = X.split(" ");

		// Parse the first four values from the input
		N = Integer.parseInt(Y[0]); // Number of elements
		A = Integer.parseInt(Y[1]); // Target value A
		B = Integer.parseInt(Y[2]); // Target value B
		C = Integer.parseInt(Y[3]); // Target value C

		// Initialize arrays for dynamic programming and results
		int[] arr = new int[N]; // Array to hold input values
		int[] dp = new int[N];  // DP array to store current state
		ans = 10000;           // Initialize answer with a large value
		ss = A + B + C;        // Sum of target values

		// Read N integers from input and populate the array
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(Y[i]);
		}

		// Perform depth-first search to find the optimal distribution
		dfs(dp, 0, arr);

		// Output the final answer
		System.out.println(ans);
	}

	// Recursive function to explore all distributions of items
	public static void dfs(int[] dp, int times, int[] arr) {
		// Base case: if all items have been considered
		if (times >= N) {
			ans = min(ans, calc(dp, arr)); // Calculate cost and update answer
			return;
		}

		// Explore all possible distributions (0 to 3)
		for (int i = 0; i < 4; i++) {
			dp[times] = i; // Assign current item to one of the four groups
			dfs(dp, times+1, arr); // Recur for the next item
		}
	}

	// Calculate the cost of the current distribution
	public static int calc(int[] dp, int[] arr) {
		int cost = 0, AA = 0, BB = 0, CC = 0; // Initialize cost and group sums

		// Count items in each group and calculate their sums
		int[] memo = new int[4];
		for (int i = 0; i < N; i++) {
			memo[dp[i]]++; // Count items in each group
			if (dp[i] == 1) {
				AA += arr[i]; // Sum for group A
			} else if (dp[i] == 2) {
				BB += arr[i]; // Sum for group B
			} else if (dp[i] == 3) {
				CC += arr[i]; // Sum for group C
			}
		}

		// Calculate the cost based on the differences from target values
		cost += Math.abs(A - AA) + Math.abs(B - BB) + Math.abs(C - CC);

		// Penalize for missing groups and excess items
		for (int i = 1; i < 4; i++) {
			int a = memo[i];
			if (a < 1) {
				cost += 10000; // High penalty for missing group
			} else {
				cost += (a - 1) * 10; // Penalty for excess items
			}
		}

		return cost; // Return the calculated cost
	}

	// Helper function to find the minimum of two integers
	public static int min(int a, int b) {
		if (a < b) {
			return a;
		}
		return b;
	}

	// Helper function to find the absolute value of an integer
	public static int abs(int a) {
		if (a < 0) {
			return a * -1;
		}
		return a;
	}

	// Additional utility functions and types can be defined below

The Java code compiles and runs successfully.

JavaScript

// Compile with: javac -d. Main.java

// Initialize scanner for input and writer for output
const fs = require("fs");
const readline = require("readline");

const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

// Declare global variables
let N, ss, ans, A, B, C;

function main() {
	// Read input values and split them into a slice of strings
	rl.question("", (X) => {
		let Y = X.split(" ");

		// Parse the first four values from the input
		N = parseInt(Y[0]); // Number of elements
		A = parseInt(Y[1]); // Target value A
		B = parseInt(Y[2]); // Target value B
		C = parseInt(Y[3]); // Target value C

		// Initialize arrays for dynamic programming and results
		let arr = new Array(N); // Array to hold input values
		let dp = new Array(N);  // DP array to store current state
		ans = 10000;           // Initialize answer with a large value
		ss = A + B + C;        // Sum of target values

		// Read N integers from input and populate the array
		for (let i = 0; i < N; i++) {
			arr[i] = pa