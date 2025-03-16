#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000
#define MOD 1000000007

// Function to read an integer from standard input
int getInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to calculate the minimum sum of divisors of N
int minSumOfDivisors(int N) {
    int sqrtN = (int)sqrt(N);
    int min = N;

    for (int i = 1; i <= sqrtN; i++) {
        if (N % i != 0) {
            continue;
        }

        int num = i + (N / i) - 2;
        if (num < min) {
            min = num;
        }
    }

    return min;
}

// Main function
int main() {
    int N = getInt(); // Read the integer N from standard input
    int result = minSumOfDivisors(N); // Calculate the minimum sum of divisors
    printf("%d\n", result); // Print the result
    return 0;
}

// Graph structure to represent a graph with n vertices and edges
typedef struct {
    int n;
    int **edges;
} Graph;

// Function to create a new graph with n vertices
Graph* newGraph(int n) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->n = n;
    g->edges = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        g->edges[i] = (int *)malloc(n * sizeof(int));
    }
    return g;
}

// Function to add an undirected edge between vertices u and v
void addEdge(Graph *g, int u, int v) {
    g->edges[u][v] = 1; // Assuming adjacency matrix representation
    g->edges[v][u] = 1; // Undirected edge
}

// Depth-first search function
void dfs(int c, Graph *g, int *visited) {
    visited[c] = 1; // Mark the current vertex as visited

    for (int v = 0; v < g->n; v++) {
        if (g->edges[c][v] && !visited[v]) {
            dfs(v, g, visited); // Recursively visit unvisited neighbors
        }
    }
}

// Function to check if a number is prime
int isPrime(int n) {
<<<<<<< HEAD
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
=======
    if (n < 2) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else if (n % 2 == 0) {
        return 0;
    }
>>>>>>> 98c87cb78a (data updated)

    int sqrtN = (int)sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Function to calculate the absolute value
int abs(int a) {
    return a < 0 ? -a : a;
}

// Function to calculate power with modulo
int powMod(int n, int p) {
<<<<<<< HEAD
    if (p == 0) return 1;
    if (p % 2 == 0) {
=======
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
>>>>>>> 98c87cb78a (data updated)
        int t = powMod(n, p / 2);
        return (t * t) % MOD;
    } else {
        return (n * powMod(n, p - 1)) % MOD;
    }
}

// Function to print an integer array
void printIntArray(int *array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

<<<<<<< HEAD
// Function to reverse a string
=======
// Function to reverse a string (not used in main)
>>>>>>> 98c87cb78a (data updated)
void reverse(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

