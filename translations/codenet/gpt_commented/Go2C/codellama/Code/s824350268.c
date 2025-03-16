
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants for buffer sizes and modulo value
const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

// Scanner for reading input
FILE *sc = stdin;

// Graph structure to represent a graph with n nodes
typedef struct {
	int n;
	int **edges;
} Graph;

// NewGraph creates a new graph with n nodes
Graph *NewGraph(int n) {
	Graph *g = malloc(sizeof(Graph));
	g->n = n;
	g->edges = malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		g->edges[i] = malloc(sizeof(int));
	}
	return g;
}

// AddEdge adds an undirected edge between nodes u and v
void AddEdge(Graph *g, int u, int v) {
	g->edges[v] = realloc(g->edges[v], (g->edges[v][0] + 1) * sizeof(int));
	g->edges[v][g->edges[v][0]] = u;
	g->edges[u] = realloc(g->edges[u], (g->edges[u][0] + 1) * sizeof(int));
	g->edges[u][g->edges[u][0]] = v;
}

// Depth-first search (DFS) algorithm to traverse the graph
void dfs(int c, int **edges, int *visited) {
	// Mark the current node as visited
	visited[c] = 1;

	// Recursively visit all adjacent nodes
	for (int i = 0; i < edges[c][0]; i++) {
		if (visited[edges[c][i]] == 1) {
			continue;
		}
		dfs(edges[c][i], edges, visited);
	}
}

// Helper function to read an integer from input
int getInt() {
	int i;
	fscanf(sc, "%d", &i);
	return i;
}

// Helper function to read a string from input
char *getString() {
	char *s = malloc(sizeof(char));
	fscanf(sc, "%s", s);
	return s;
}

// Function to return the absolute value of an integer
int abs(int a) {
	return a < 0 ? -a : a;
}

// Function to compute p raised to the power of q
int pow(int p, int q) {
	if (q == 0) {
		return 1;
	} else if (q % 2 == 0) {
		return pow(p, q / 2) * pow(p, q / 2);
	} else {
		return p * pow(p, q - 1);
	}
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
int min(int nums, ...) {
	va_list args;
	va_start(args, nums);
	int res = va_arg(args, int);
	for (int i = 0; i < nums; i++) {
		res = res < va_arg(args, int) ? res : va_arg(args, int);
	}
	va_end(args);
	return res;
}

// Function to find the maximum value among a variable number of integers
int max(int nums, ...) {
	va_list args;
	va_start(args, nums);
	int res = va_arg(args, int);
	for (int i = 0; i < nums; i++) {
		res = res > va_arg(args, int) ? res : va_arg(args, int);
	}
	va_end(args);
	return res;
}

// Function to check if a string exists in a slice of strings
int strSearch(char **a, char *b) {
	for (int i = 0; i < sizeof(a); i++) {
		if (strcmp(a[i], b) == 0) {
			return 1;
		}
	}
	return 0;
}

// Function to print an integer array in a formatted way
void printIntArray(int *array) {
	char *strArray = malloc(sizeof(char));
	sprintf(strArray, "%d", array);
	printf("%s\n", strArray);
}

// Function to calculate x % mod
int calcMod(int x) {
	return x % mod;
}

// Function to reverse a string
char *reverse(char *s) {
	int len = strlen(s);
	char *r = malloc(len * sizeof(char));
	for (int i = 0, j = len - 1; i < j; i++, j--) {
		r[i] = s[j];
		r[j] = s[i];
	}
	return r;
}

// Function to check if a number is prime
int isPrime(int n) {
	if (n < 2) {
		return 0;
	} else if (n == 2) {
		return 1;
	} else if (n % 2 == 0) {
		return 0;
	}

	// Check for factors from 3 to the square root of n
	int sqrtN = sqrt(n);
	for (int i = 3; i <= sqrtN; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}

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
		if (N % i != 0) {
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
	printf("%d\n", min);
	return 0;
}

