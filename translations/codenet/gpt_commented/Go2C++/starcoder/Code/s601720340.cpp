#include <bits/stdc++.h>

using namespace std;

// Define a large prime number for modulo operations
const int magic = 1000000007;

// Command-line flags for CPU and memory profiling
string cpuprofile = "";
string memprofile = "";

int N;
int p[200000];

// Function to check if a number exists in the array p
int find(int n) {
	for (int i = 0; i < N; i++) {
		if (n == p[i]) {
			return 0; // Number found
		}
	}
	return 1; // Number not found
}

// Main solving function
void solve() {
	// PARSE HELPER SESSION
	// Read and log the input values
	int X = atoi(cin.get().c_str()); // Read an integer
	cout << X << endl; // Log the integer
	N = atoi(cin.get().c_str()); // Read the size of the array
	cout << N << endl; // Log the size
	for (int i = 0; i < N; i++) {
		p[i] = atoi(cin.get().c_str()); // Read integers into the array p
	}
	cout << "p " << p[0:10] << endl; // Log the first 10 elements of p

	// Check for numbers around X that are not in the array p
	for (int i = 0; i <= 100; i++) {
		if (find(X - i) == 1) { // Check X - i
			cout << X - i << endl; // Print the result
			return; // Exit the program
		}
		if (find(X + i) == 1) { // Check X + i
			cout << X + i << endl; // Print the result
			return; // Exit the program
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
	// vector<int> visited;
	// bfs(1, neighbor, [&visited](int node) {
	// 	visited.push_back(node);
	// });
	// cout << visited << endl;

	// DFS 2
	// vector<int> dp(2000000, 0);
	// map<int, vector<int>> nei;
	// nei[0] = {1, 2};
	// nei[1] = {0};
	// nei[2] = {0, 3};
	// nei[3] = {2};
	// dfs2(0, nei, [&dp](int n, int p) {
	// 	cout << p << " -> " << n << endl;
	// 	dp[n] = p;
	// }, [&dp](int n, int p) {
	// 	cout << n << " -> " << p << endl;
	// });
	// cout << dp[0:5] << endl;

	// COMBINATION
	// cout << N << " " << M << " " << max(N, M) << endl;
	// cout << "Lucas " << combMod(N, M, 13) << " " << combination(N, M) << endl;
}

// Main function to execute the program
int main(int argc, char* argv[]) {
	// Parse command-line flags
	for (int i = 1; i < argc; i++) {
		if (string(argv[i]) == "-cpuprofile") {
			cpuprofile = argv[i + 1]; // Set the CPU profile file
			i++; // Skip the next argument
		} else if (string(argv[i]) == "-memprofile") {
			memprofile = argv[i + 1]; // Set the memory profile file
			i++; // Skip the next argument
		}
	}

	if (cpuprofile!= "") {
		ofstream f(cpuprofile); // Create CPU profile file
		pprof::StartCPUProfile(&f); // Start CPU profiling
		atexit(pprof::StopCPUProfile); // Stop profiling when done
	}

	solve(); // Call the solve function

	if (memprofile!= "") {
		ofstream f(memprofile); // Create memory profile file
		pprof::WriteHeapProfile(&f); // Write memory profile to file
		f.close(); // Close the file when done
	}
}

// Libraries

// Io helps parsing inputs from standard input for programming contests.
struct Io {
	std::istream* reader;
	std::ostream* writer;
	std::vector<std::string> tokens;
	int nextToken;
};

// NewIo generates Io instance.
Io* NewIo() {
	return new Io{&cin, &cout, {}, 0}; // Initialize reader and writer
}

// Flush flushes buffer. Don't forget to do this when you call Io.Printf/Io.PrintLn for final output.
void Flush(Io* io) {
	io->writer->flush(); // Flush the writer buffer
}

// NextLine parses line as string.
string NextLine(Io* io) {
	string buffer;
	while (true) {
		string line;
		getline(*io->reader, line); // Read a line
		buffer += line; // Append line to buffer
		if (!io->reader->eof()) {
			break; // Break if not a prefix
		}
	}
	return buffer; // Return the complete line as string
}

// Next parse next word as string.
string Next(Io* io) {
	for (io->nextToken >= (int)io->tokens.size()) {
		string line = NextLine(io); // Read the next line
		io->tokens = split(line); // Split line into tokens
		io->nextToken = 0; // Reset token index
	}
	string r = io->tokens[io->nextToken]; // Get the next token
	io->nextToken++; // Move to the next token
	return r; // Return the token
}

// NextInt parse next word as Int.
int NextInt(Io* io) {
	int i = atoi(Next(io).c_str()); // Convert the next token to int
	return i; // Return the integer
}

// NextFloat parses next word as float64.
double NextFloat(Io* io) {
	double i = atof(Next(io).c_str()); // Convert the next token to float64
	return i; // Return the float
}

// PrintLn does buffer write with linefeed.
void PrintLn(Io* io,...) {
	va_list args;
	va_start(args, io);
	vprintf(io->writer, args); // Write to buffer with linefeed
	va_end(args);
	printf("\n");
}

// Printf does formatted buffer write.
void Printf(Io* io, const char* format,...) {
	va_list args;
	va_start(args, format);
	vprintf(io->writer, format, args); // Write formatted output to buffer
	va_end(args);
}

// PrintIntLn prints Int array in a single line.
void PrintIntLn(Io* io, int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]); // Print each integer
	}
	printf("\n");
}

// PrintStringLn prints string array in a single line.
void PrintStringLn(Io* io, string* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s ", a[i].c_str()); // Print each string
	}
	printf("\n");
}

// Log print single value to standard output (contest server ignores this so you don't have to remove when finishing)
void Log(const char* name, int value) {
	printf("%s=%d\n", name, value); // Log the value to stderr
}

// Logf print formatted output to standard output (contest server ignores this so you don't have to remove when finishing)
void Logf(const char* format,...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args); // Log formatted output to stderr
	va_end(args);
}

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
	frontier.push(start); // Push the start node to the queue
	map<int, bool> visited; // Track visited nodes

	while (!frontier.empty()) {
		int node = frontier.front(); // Get the front node
		frontier.pop(); // Pop the front node
		if (!visited[node]) { // Check if the node is visited
			visited[node] = true; // Mark the node as visited
			fn(node); // Execute the provided function on the node
			for (int n : bfsFrontier(node, nodes, visited)) {
				frontier.push(n); // Add unvisited neighbors to the frontier
			}
		}
	}
}

// Helper function to get unvisited neighbors for BFS
vector<int> bfsFrontier(int node, map<int, vector<int>> nodes, map<int, bool> visited) {
	vector<int> next;
	for (int n : nodes[node]) {
		if (!visited[n]) {
			next.push_back(n); // Add unvisited neighbor to the list
		}
	}
	return next; // Return the list of unvisited neighbors
}

// Depth-First Search (DFS) implementation
void dfs(int node, map<int, vector<int>> nodes, function<void(int)> fn) {
	dfsRecur(node, nodes, map<int, bool>{}, fn); // Start the recursive DFS
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
	dfs2Recur(node, -1, nodes, map<int, bool>{}, fn1, fn2); // Start the recursive DFS with parent tracking
}

// Recursive DFS helper function with parent tracking
void dfs2Recur(int node, int parent, map<int, vector<int>> nodes, map<int, bool> v, function<void(int, int)> fn1, function<void(int, int)> fn2) {
	v[node] = true; // Mark the node as visited
	if (fn1) {
		fn1(node, parent); // Execute the first function
	}
	for (int n : nodes[node]) {
		if (!v[n]) {
			dfs2Recur(n, node, nodes, v, fn1, fn2); // Recursively visit unvisited neighbors
		}
	}
	if (fn2) {
		fn2(node, parent); // Execute the second function
	}
}

// Stack data structure implementation
struct Stack {
	Element* top; // Pointer to the top element
	int size; // Size of the stack
};

// Element is a struct for stack element
struct Element {
	int value; // Value of the element
	Element* next; // Pointer to the next element
};

// Len returns stack height
int Len(Stack* s) {
	return s->size; // Return the size of the stack
}

// Push puts an element on the stack.
void Push(St