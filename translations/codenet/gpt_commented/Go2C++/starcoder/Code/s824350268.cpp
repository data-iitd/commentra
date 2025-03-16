#include <bits/stdc++.h>

using namespace std;

// Constants for buffer sizes and modulo value
const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

// Function to read an integer from input
int getInt() {
	int num;
	cin >> num;
	return num;
}

// Function to read a string from input
string getString() {
	string str;
	cin >> str;
	return str;
}

// Function to return the absolute value of an integer
int abs(int a) {
	return a < 0? -a : a;
}

// Function to compute p raised to the power of q
int pow(int p, int q) {
	int res = 1;
	while (q > 0) {
		if (q & 1) {
			res = (res * p) % mod;
		}
		p = (p * p) % mod;
		q >>= 1;
	}
	return res;
}

// Function to compute (n^p) % mod using exponentiation by squaring
int powMod(int n, int p) {
	if (p == 0) {
		return 1;
	} else if (p % 2 == 0) {
		int t = powMod(n, p / 2);
		return (t * t) % mod;
	} else {
		return (n * powMod(n, p - 1)) % mod;
	}
}

// Function to find the minimum value among a variable number of integers
int min(int nums[], int n) {
	if (n == 0) {
		return INT_MAX;
	}
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		res = min(res, nums[i]);
	}
	return res;
}

// Function to find the maximum value among a variable number of integers
int max(int nums[], int n) {
	if (n == 0) {
		return INT_MIN;
	}
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		res = max(res, nums[i]);
	}
	return res;
}

// Function to check if a string exists in a slice of strings
bool strSearch(string arr[], int n, string str) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == str) {
			return true;
		}
	}
	return false;
}

// Function to print an integer array in a formatted way
void printIntArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Function to calculate x % mod
int calcMod(int x) {
	return (x % mod + mod) % mod;
}

// Function to reverse a string
string reverse(string s) {
	int n = s.length();
	string rev = "";
	for (int i = n - 1; i >= 0; i--) {
		rev += s[i];
	}
	return rev;
}

// Function to check if a number is prime
bool isPrime(int n) {
	if (n < 2) {
		return false;
	} else if (n == 2) {
		return true;
	} else if (n % 2 == 0) {
		return false;
	}

	// Check for factors from 3 to the square root of n
	int sqrtN = sqrt(n);
	for (int i = 3; i <= sqrtN; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

// Graph structure to represent a graph with n nodes
struct Graph {
	int n;
	vector<int> *edges;
};

// Function to create a new graph with n nodes
Graph* newGraph(int n) {
	Graph* g = new Graph;
	g->n = n;
	g->edges = new vector<int>[n];
	return g;
}

// Function to add an undirected edge between nodes u and v
void addEdge(Graph* g, int u, int v) {
	g->edges[v].push_back(u);
	g->edges[u].push_back(v);
}

// Depth-first search (DFS) algorithm to traverse the graph
void dfs(int c, vector<int> edges[], map<int, bool> &visited) {
	// Mark the current node as visited
	visited[c] = true;

	// Recursively visit all adjacent nodes
	for (int v : edges[c]) {
		if (visited[v]) {
			continue;
		}
		dfs(v, edges, visited);
	}
}

// Main function
int main() {
	// Read an integer N from input
	int N = getInt();
	// Calculate the integer square root of N
	int sqrtN = sqrt(N);

	// Initialize min to N, which will hold the minimum value found
	int min = N;
	// Iterate through all possible divisors of N
	for (int i = 1; i <= sqrtN; i++) {
		// If i is not a divisor of N, skip to the next iteration
		if (N % i!= 0) {
			continue;
		}

		// Calculate the value based on the divisor and its complement
		int num = i + (N / i) - 2;
		// Update min if the new value is smaller
		if (num < min) {
			min = num;
		}
	}

	// Print the minimum value found
	cout << min << endl;
	return 0;
}

