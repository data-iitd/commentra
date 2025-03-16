

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Define a large prime number for modulo operations
#define magic 1000000007

// Command-line flags for CPU and memory profiling
char *cpuprofile = NULL;
char *memprofile = NULL;

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
	int X = atoi(fgets(NULL, 0, stdin)); // Read an integer
	printf("%d\n", X); // Log the integer
	N = atoi(fgets(NULL, 0, stdin)); // Read the size of the array
	printf("%d\n", N); // Log the size
	for (int i = 0; i < N; i++) {
		p[i] = atoi(fgets(NULL, 0, stdin)); // Read integers into the array p
	}
	printf("p %d\n", p[0]); // Log the first element of p

	// Check for numbers around X that are not in the array p
	for (int i = 0; i <= 100; i++) {
		if (find(X - i) == 1) { // Check X - i
			printf("%d\n", X - i); // Print the result
			return; // Exit the program
		}
		if (find(X + i) == 1) { // Check X + i
			printf("%d\n", X + i); // Print the result
			return; // Exit the program
		}
	}

	// OUTPUT GENERATION PART
	// ans := 0
	// printf("%d\n", ans);

	// if (ans > 0) {
	//   printf("Yes\n");
	// } else {
	//   printf("No\n");
	// }

	// BFS/DFS PART
	// visited := []int{}
	// bfs/dfs(1, neighbor, func(node int) {
	// 	visited = append(visited, node)
	// })
	// printf("%d\n", visited);

	// DFS 2
	// var dp [2000000]int
	// nei := make(map[int][]int)
	// nei[0] = []int{1, 2}
	// nei[1] = []int{0}
	// nei[2] = []int{0, 3}
	// nei[3] = []int{2}
	// dfs2(0, nei, func(n, p int) {
	// 	printf("%d -> %d\n", p, n)
	// 	dp[n] = p
	// }, func(n, p int) {
	// 	printf("%d -> %d\n", n, p)
	// })
	// printf("%d\n", dp[0]);

	// COMBINATION
	// printf("%d %d %d\n", N, M, intMax(N, M));
	// printf("Lucas %d %d\n", combMod(N, M, 13), combination(N, M));
}

// Main function to execute the program
int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-cpuprofile") == 0) {
			cpuprofile = argv[i + 1];
		} else if (strcmp(argv[i], "-memprofile") == 0) {
			memprofile = argv[i + 1];
		}
	}

	if (cpuprofile!= NULL) {
		FILE *f = fopen(cpuprofile, "w"); // Create CPU profile file
		if (f == NULL) {
			fprintf(stderr, "could not create CPU profile: %s\n", cpuprofile);
			exit(1);
		}
		fclose(f);
		pprof_start(); // Start CPU profiling
	}

	solve(); // Call the solve function

	if (memprofile!= NULL) {
		FILE *f = fopen(memprofile, "w"); // Create memory profile file
		if (f == NULL) {
			fprintf(stderr, "could not create memory profile: %s\n", memprofile);
			exit(1);
		}
		fclose(f);
		pprof_stop(); // Stop profiling when done
	}
}

// Libraries

// Io helps parsing inputs from standard input for programming contests.
typedef struct {
	FILE *reader;
	FILE *writer;
	char *tokens[100000];
	int nextToken;
} Io;

// NewIo generates Io instance.
Io *NewIo() {
	Io *io = malloc(sizeof(Io)); // Allocate memory for the Io struct
	io->reader = stdin; // Initialize reader
	io->writer = stdout; // Initialize writer
	io->nextToken = 0; // Reset token index
	return io; // Return the Io struct
}

// Flush flushes buffer. Don't forget to do this when you call Io.Printf/Io.PrintLn for final output.
void Flush(Io *io) {
	fflush(io->writer); // Flush the writer buffer
}

// NextLine parses line as string.
char *NextLine(Io *io) {
	char *buffer = malloc(100000); // Allocate memory for the buffer
	char *line = fgets(buffer, 100000, io->reader); // Read a line
	if (line == NULL) {
		free(buffer); // Free the buffer
		return NULL; // Return NULL if EOF
	}
	return buffer; // Return the complete line as string
}

// Next parse next word as string.
char *Next(Io *io) {
	if (io->nextToken >= sizeof(io->tokens)) {
		char *line = NextLine(io); // Read the next line
		if (line == NULL) {
			return NULL; // Return NULL if EOF
		}
		int i = 0;
		while (line[i]!= '\0') {
			if (line[i] =='' || line[i] == '\n') {
				line[i] = '\0'; // Replace spaces and newlines with null characters
			}
			i++;
		}
		int j = 0;
		int k = 0;
		while (line[j]!= '\0') {
			if (line[j]!= '\0') {
				io->tokens[k] = &line[j]; // Copy the token to the tokens array
				k++; // Increment the token index
			}
			j++;
		}
		io->nextToken = 0; // Reset token index
	}
	char *r = io->tokens[io->nextToken]; // Get the next token
	io->nextToken++; // Move to the next token
	return r; // Return the token
}

// NextInt parse next word as Int.
int NextInt(Io *io) {
	char *s = Next(io); // Get the next token
	if (s == NULL) {
		return 0; // Return 0 if EOF
	}
	int i = atoi(s); // Convert the next token to int
	return i; // Return the integer
}

// NextFloat parses next word as float64.
float NextFloat(Io *io) {
	char *s = Next(io); // Get the next token
	if (s == NULL) {
		return 0; // Return 0 if EOF
	}
	float i = atof(s); // Convert the next token to float64
	return i; // Return the float
}

// PrintLn does buffer write with linefeed.
void PrintLn(Io *io,...) {
	va_list args;
	va_start(args, io); // Initialize the argument list
	vprintf(io->writer, args); // Write to buffer with linefeed
	va_end(args); // End the argument list
	printf("\n");
}

// Printf does formatted buffer write.
void Printf(Io *io, char *format,...) {
	va_list args;
	va_start(args, format); // Initialize the argument list
	vprintf(io->writer, format, args); // Write formatted output to buffer
	va_end(args); // End the argument list
}

// PrintIntLn prints Int array in a single line.
void PrintIntLn(Io *io, int a[]) {
	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		printf("%d ", a[i]); // Print each integer
	}
	printf("\n");
}

// PrintStringLn prints string array in a single line.
void PrintStringLn(Io *io, char *a[]) {
	for (int i = 0; i < sizeof(a) / sizeof(char *); i++) {
		printf("%s ", a[i]); // Print each string
	}
	printf("\n");
}

// Log print single value to standard output (contest server ignores this so you don't have to remove when finishing)
void Log(char *name, int value) {
	printf("%s=%d\n", name, value); // Log the value to stderr
}

// Logf print formatted output to standard output (contest server ignores this so you don't have to remove when finishing)
void Logf(char *format,...) {
	va_list args;
	va_start(args, format); // Initialize the argument list
	vprintf(stderr, format, args); // Log formatted output to stderr
	va_end(args); // End the argument list
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
void bfs(int start, int nodes[][200000], void (*fn)(int)) {
	int frontier[100000] = {start}; // Initialize the frontier with the start node
	bool visited[100000] = {}; // Track visited nodes

	for (int i = 0; i < sizeof(frontier) / sizeof(int); i++) {
		int next[100000] = {}; // Prepare for the next frontier
		for (int j = 0; j < sizeof(frontier) / sizeof(int); j++) {
			if (visited[frontier[j]]) {
				continue; // Skip visited nodes
			}
			visited[frontier[j]] = true; // Mark the node as visited
			fn(frontier[j]); // Execute the provided function on the node
			for (int k = 0; k < sizeof(nodes[frontier[j]]) / sizeof(int); k++) {
				if (!visited[nodes[frontier[j]][k]]) {
					next[sizeof(next) / sizeof(int)] = nodes[frontier[j]][k]; // Add unvisited neighbors to the next frontier
				}
			}
		}
		frontier[0] = next[0]; // Move to the next frontier
	}
}

// Helper function to get unvisited neighbors for BFS
int *bfsFrontier(int node, int nodes[][200000], bool visited[]) {
	int next[100000] = {};
	for (int i = 0; i < sizeof(nodes[node]) / sizeof(int); i++) {
		if (!visited[nodes[node][i]]) {
			next[sizeof(next) / sizeof(int)] = nodes[node][i]; // Add unvisited neighbor to the list
		}
	}
	return next; // Return the list of unvisited neighbors
}

// Depth-First Search (DFS) implementation
void dfs(int node, int nodes[][200000], void (*fn)(int)) {
	bool visited[100000] = {}; // Track visited nodes
	dfsRecur(node, -1, nodes, visited, fn); // Start the recursive DFS
}

// Recursive DFS helper function
void dfsRecur(int node, int parent, int nodes[][200000], bool visited[], void (*fn)(int)) {
	visited[node] = true; // Mark the node as visited
	fn(node); // Execute the provided function on the node
	for (int i = 0; i < sizeof(nodes[node]) / sizeof(int); i++) {
		if (!visited[nodes[node][i]]) {
			dfsRecur(nodes[node][i], node, nodes, visited, fn); // Recursively visit unvisited neighbors
		}
	}
}

// DFS with two fun