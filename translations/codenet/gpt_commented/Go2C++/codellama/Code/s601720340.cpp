
#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// Define a large prime number for modulo operations
const int magic = 1000000007;

// Function to check if a number exists in the array p
bool find(int n, int p[], int N) {
	for (int i = 0; i < N; i++) {
		if (n == p[i]) {
			return false; // Number found
		}
	}
	return true; // Number not found
}

// Main solving function
void solve() {
	int X, N; // Declare variables
	cin >> X >> N; // Read and log the input values
	cout << X << " " << N << endl; // Log the input values
	int p[200000]; // Declare array p
	for (int i = 0; i < N; i++) {
		cin >> p[i]; // Read integers into the array p
	}
	cout << "p "; // Log the first 10 elements of p
	for (int i = 0; i < 10; i++) {
		cout << p[i] << " ";
	}
	cout << endl;

	// Check for numbers around X that are not in the array p
	for (int i = 0; i <= 100; i++) {
		if (find(X - i, p, N) == true) { // Check X - i
			cout << X - i << endl; // Print the result
			exit(0); // Exit the program
		}
		if (find(X + i, p, N) == true) { // Check X + i
			cout << X + i << endl; // Print the result
			exit(0); // Exit the program
		}
	}

	// OUTPUT GENERATION PART
	// ans := 0
	// cout << ans << endl;

	// if (ans > 0) {
	//   cout << "Yes" << endl;
	// } else {
	//   cout << "No" << endl;
	// }

	// BFS/DFS PART
	// visited := []int{}
	// bfs/dfs(1, neighbor, func(node int) {
	// 	visited = append(visited, node)
	// })
	// cout << visited << endl;

	// DFS 2
	// var dp [2000000]int
	// nei := make(map[int][]int)
	// nei[0] = []int{1, 2}
	// nei[1] = []int{0}
	// nei[2] = []int{0, 3}
	// nei[3] = []int{2}
	// dfs2(0, nei, func(n, p int) {
	// 	cout << p << " -> " << n << endl;
	// 	dp[n] = p
	// }, func(n, p int) {
	// 	cout << n << " -> " << p << endl;
	// })
	// cout << dp[0:5] << endl;

	// COMBINATION
	// cout << N << " " << M << " " << intMax(N, M) << endl;
	// cout << "Lucas " << combMod(N, M, 13) << " " << combination(N, M) << endl;
}

// Main function to execute the program
int main() {
	solve(); // Call the solve function
	return 0; // Return 0
}

// Libraries

// Helper functions for mathematical operations

// Returns the minimum of two integers
int intMin(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Returns the maximum of two integers
int intMax(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Direct calculation of combination
// n, m should be "small"
int combination(int n, int m) {
	if (m > n) {
		return 0; // Not possible to choose more than available
	} else if (m == n || m == 0) {
		return 1; // Only one way to choose all or none
	} else {
		int res = 1;
		for (int i = 0; i < m; i++) {
			res *= (n - i); // Calculate numerator
		}
		for (int i = 1; i <= m; i++) {
			res /= i; // Calculate denominator
		}
		return res; // Return the combination result
	}
}

// Calculate combination modulo based on Lucas theorem
int lucas(int n, int m, int p) {
	int ntemp = n;
	int mtemp = m;
	int res = 1;
	for (int i = 0; i < 100; i++) {
		int nreminder = ntemp % p; // Remainder of n
		ntemp = ntemp / p; // Update n
		int mreminder = mtemp % p; // Remainder of m
		mtemp = mtemp / p; // Update m
		res = res * (combination(nreminder, mreminder) % p); // Combine results
		if (ntemp == 0) {
			break; // Break if n is exhausted
		}
	}
	return res % p; // Return the result modulo p
}

// Wrapper function for combination modulo
int combMod(int n, int m, int p) {
	return lucas(n, m, p); // Call lucas function
}

// Breadth-First Search (BFS) implementation
void bfs(int start, map<int, vector<int>> nodes, function<void(int)> fn) {
	queue<int> frontier; // Initialize the frontier with the start node
	map<int, bool> visited; // Track visited nodes
	frontier.push(start);
	visited[start] = true;

	while (!frontier.empty()) {
		int next = frontier.front(); // Get the next node
		frontier.pop();
		fn(next); // Execute the provided function on the node
		for (int n : bfsFrontier(next, nodes, visited)) {
			if (!visited[n]) {
				frontier.push(n); // Add unvisited neighbors to the next frontier
			}
		}
	}
}

// Helper function to get unvisited neighbors for BFS
vector<int> bfsFrontier(int node, map<int, vector<int>> nodes, map<int, bool> visited) {
	vector<int> next;
	auto iter = [&](int n) { return !visited[n]; }; // Check if a node is unvisited
	for (int n : nodes[node]) {
		if (iter(n)) {
			next.push_back(n); // Add unvisited neighbor to the list
		}
	}
	return next; // Return the list of unvisited neighbors
}

// Depth-First Search (DFS) implementation
void dfs(int node, map<int, vector<int>> nodes, function<void(int)> fn) {
	dfsRecur(node, nodes, map<int, bool>(), fn); // Start the recursive DFS
}

// Recursive DFS helper function
void dfsRecur(int node, map<int, vector<int>> nodes, map<int, bool> v, function<void(int)> fn) {
	v[node] = true; // Mark the node as visited
	fn(node); // Execute the provided function on the node
	for (int n : nodes[node]) {
		if (!v[n]) {
			dfsRecur(n, nodes, v, fn); // Recursively visit unvisited neighbors
		}
	}
}

// DFS with two functions: one before entering child tree, and another after
void dfs2(int node, map<int, vector<int>> nodes, function<void(int, int)> fn1, function<void(int, int)> fn2) {
	dfs2Recur(node, -1, nodes, map<int, bool>(), fn1, fn2); // Start the recursive DFS with parent tracking
}

// Recursive DFS helper function with parent tracking
void dfs2Recur(int node, int parent, map<int, vector<int>> nodes, map<int, bool> v, function<void(int, int)> fn1, function<void(int, int)> fn2) {
	v[node] = true; // Mark the node as visited
	if (fn1 != nullptr) {
		fn1(node, parent); // Execute the first function
	}
	for (int n : nodes[node]) {
		if (!v[n]) {
			dfs2Recur(n, node, nodes, v, fn1, fn2); // Recursively visit unvisited neighbors
		}
	}
	if (fn2 != nullptr) {
		fn2(node, parent); // Execute the second function
	}
}

// Stack data structure implementation
struct Stack {
	struct Element {
		int value; // Value of the element
		Element *next; // Pointer to the next element
	};
	Element *top; // Pointer to the top element
	int size; // Size of the stack

	int Len() {
		return size; // Return the size of the stack
	}

	void Push(int value) {
		Element *e = new Element; // Create a new element
		e->value = value; // Set the value
		e->next = top; // Set the next pointer
		top = e; // Set the top pointer
		size++; // Increment the size
	}

	int Pop() {
		if (size > 0) {
			int value = top->value; // Get the top value
			Element *e = top; // Get the top pointer
			top = top->next; // Set the top pointer
			delete e; // Delete the element
			size--; // Decrement the size
			return value; // Return the value
		}
		return -1; // Return -1 if the stack is empty
	}
};

// Function to find divisors of a number
void findDivisors(int n, vector<int> *a) {
	if (n == 1) {
		return; // 1 has no divisors
	}

	int sqrt = int(sqrt(n)); // Calculate the square root of n
	for (int i = 2; i <= sqrt; i++) {
		if (n % i == 0) {
			a->push_back(i); // Append divisor i
			a->push_back(n / i); // Append corresponding divisor n/i
		}
	}
	a->push_back(n); // Append n itself as a divisor
}

// Function to remove duplicates from a vector
vector<int> removeDuplicate(vector<int> a) {
	map<int, bool> m; // Create a map to track unique values
	for (int i = 0; i < a.size(); i++) {
		m[a[i]] = true; // Mark each value as seen
	}
	vector<int> res;
	for (auto i : m) {
		res.push_back(i.first); // Append unique values to the result vector
	}
	return res; // Return the vector of unique values
}

// Function to calculate the absolute value
int abs(int a) {
	if (a > 0) {
		return a; // Return a if positive
	}
	return -a; // Return -a if negative
}

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
	while (a != 0) {
		a, b = b % a, a; // Euclidean algorithm
	}
	return b; // Return the GCD
}

// Function to calculate power of 2 modulo a given number
int power2mod(int n, int mod) {
	int res = 1, x = 2;
	for (; n > 0; n >>= 1) {
		if (n & 1) {
			res = res * x % mod; // Update result if the current bit is set
		}
		x = x * x % mod; // Square the base
	}
	return res; // Return the result
}

// Function to calculate power of 2 with modulo magic
int power2(int n) {
	return power2mod(n, magic); // Call power2mod with magic
}

