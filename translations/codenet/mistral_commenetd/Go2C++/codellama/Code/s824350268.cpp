
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Constants definition
const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

// Variables definition and initialization
vector<string> sc;

// Main function
int main() {
	// Read the first integer from the standard input
	int N = getInt();

	// Calculate the square root of N
	int sqrtN = int(sqrt(N));

	// Initialize the minimum number with N
	int min = N;

	// Iterate through all numbers from 1 to the square root of N
	for (int i = 1; i <= sqrtN; i++) {
		// Check if N is divisible by i
		if (N % i != 0) {
			continue;
		}

		// Calculate the number of divisors of i and N
		int num = i + (N / i) - 2;

		// Update the minimum number if the current number is smaller
		if (num < min) {
			min = num;
		}
	}

	// Print the minimum number
	cout << min << endl;

	return 0;
}

// Define a Graph data structure
struct Graph {
	int n;
	vector<vector<int>> edges;
};

// Initialize a new Graph with n vertices
Graph* NewGraph(int n) {
	Graph* g = new Graph();
	g->n = n;
	g->edges = vector<vector<int>>(n);
	return g;
}

// Add an edge between two vertices in the Graph
void AddEdge(Graph* g, int u, int v) {
	g->edges[v].push_back(u);
	g->edges[u].push_back(v);
}

// Depth First Search function
void dfs(int c, vector<vector<int>>& edges, unordered_map<int, int>& visited) {
	// Mark the current vertex as visited
	visited[c] = 1;

	// Iterate through all neighbors of the current vertex
	for (int v : edges[c]) {
		// If the neighbor is already visited, skip it
		if (visited[v]) {
			continue;
		}

		// Recursively call DFS for the neighbor
		dfs(v, edges, visited);
	}
}

// Helper functions for reading integers and strings from the standard input
int getInt() {
	string s;
	getline(cin, s);
	return stoi(s);
}

string getString() {
	string s;
	getline(cin, s);
	return s;
}

// Helper functions for basic arithmetic operations
int abs(int a) {
	return abs(a);
}

int pow(int p, int q) {
	return pow(p, q);
}

int powMod(int n, int p) {
	// Base case: if p is 0, return 1
	if (p == 0) {
		return 1;
	} else if (p % 2 == 0) {
		// Recursive case: if p is even, square the base and recursively call powMod
		int t = powMod(n, p / 2);
		return t * t % mod;
	} else {
		// Recursive case: if p is odd, multiply the base with the result of recursively calling powMod with p-1
		return n * powMod(n, p - 1) % mod;
	}
}

// Helper functions for finding the minimum and maximum values
int min(vector<int> nums) {
	// Base case: if there are no numbers, panic
	if (nums.size() == 0) {
		panic("funciton min() requires at least one argument.");
	}

	// Initialize the minimum value with the first number
	int res = nums[0];

	// Iterate through all numbers and update the minimum value if necessary
	for (int i = 0; i < nums.size(); i++) {
		res = min(res, nums[i]);
	}

	// Return the minimum value
	return res;
}

int max(vector<int> nums) {
	// Base case: if there are no numbers, panic
	if (nums.size() == 0) {
		panic("funciton max() requires at least one argument.");
	}

	// Initialize the maximum value with the first number
	int res = nums[0];

	// Iterate through all numbers and update the maximum value if necessary
	for (int i = 0; i < nums.size(); i++) {
		res = max(res, nums[i]);
	}

	// Return the maximum value
	return res;
}

// Helper function for searching a string in an array of strings
bool strSearch(vector<string> a, string b) {
	// Iterate through all strings in the array and return true if the target string is found
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b) {
			return true;
		}
	}

	// If the target string is not found, return false
	return false;
}

// Helper function for printing an integer array
void printIntArray(vector<int> array) {
	// Convert the integer array to a string and print it without the brackets and the leading and trailing spaces
	string strArray = to_string(array);
	cout << strArray.substr(1, strArray.size() - 2) << endl;
}

// Helper function for calculating the modulo operation
int calcMod(int x) {
	// Calculate the modulo of x with the modulus constant
	return x % mod;
}

// Helper function for reversing a string
string reverse(string s) {
	// Create a slice of runes from the input string, reverse it in-place, and convert it back to a string
	vector<char> runes(s.begin(), s.end());
	reverse(runes.begin(), runes.end());
	return string(runes.begin(), runes.end());
}

// Helper function for checking if a number is prime
bool isPrime(int n) {
	// Base case: if n is less than 2, it is not prime
	if (n < 2) {
		return false;
	}

	// Base case: if n is 2, it is prime
	if (n == 2) {
		return true;
	}

	// Base case: if n is even, it is not prime
	if (n % 2 == 0) {
		return false;
	}

	// Calculate the square root of n and iterate through all odd numbers from 3 to the square root of n
	int sqrtN = int(sqrt(n));
	for (int i = 3; i <= sqrtN; i += 2) {
		// If n is divisible by i, it is not prime
		if (n % i == 0) {
			return false;
		}
	}

	// If we have reached here, n is prime
	return true;
}

