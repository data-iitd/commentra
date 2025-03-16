#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MOD 1000000007

// Function to read an integer from input
int getInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to calculate the minimum value based on divisors
int calculateMin(int N) {
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
    // Read an integer N from input
    int N = getInt();
    // Calculate the minimum value found
    int min = calculateMin(N);
    // Print the minimum value found
    printf("%d\n", min);
<<<<<<< HEAD
=======
    
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// Function to calculate x % mod
int calcMod(int x) {
    return x % MOD;
}

// Function to reverse a string
void reverse(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
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

    int sqrtN = (int)sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to compute (n^p) % mod using exponentiation by squaring
int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return calcMod(t * t);
    } else {
        return calcMod(n * powMod(n, p - 1));
    }
}

// Function to find the minimum value among a variable number of integers
int min(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int num = va_arg(args, int);
        if (num < res) {
            res = num;
        }
    }
    va_end(args);
    return res;
}

// Function to find the maximum value among a variable number of integers
int max(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int num = va_arg(args, int);
        if (num > res) {
            res = num;
        }
    }
    va_end(args);
    return res;
}

// Function to print an integer array in a formatted way
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

// Function to check if a string exists in a slice of strings
bool strSearch(char **a, int size, const char *b) {
    for (int i = 0; i < size; i++) {
        if (strcmp(a[i], b) == 0) {
            return true;
        }
    }
    return false;
}

// Function to compute the absolute value of an integer
int abs(int a) {
    return a < 0 ? -a : a;
}

// Function to compute p raised to the power of q
int pow(int p, int q) {
    return (int)pow((double)p, (double)q);
}

<<<<<<< HEAD
// Function to create a new graph (not used in main)
=======
// Graph structure to represent a graph with n nodes
>>>>>>> 98c87cb78a (data updated)
typedef struct {
    int n;
    int **edges;
} Graph;

<<<<<<< HEAD
=======
// Function to create a new graph with n nodes
>>>>>>> 98c87cb78a (data updated)
Graph* NewGraph(int n) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->n = n;
    g->edges = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        g->edges[i] = (int *)malloc(n * sizeof(int));
    }
    return g;
}

<<<<<<< HEAD
void AddEdge(Graph *g, int u, int v) {
    g->edges[u][v] = 1; // Assuming undirected graph
    g->edges[v][u] = 1; // Assuming undirected graph
}

// Depth-first search (DFS) algorithm to traverse the graph (not used in main)
void dfs(int c, int **edges, bool *visited, int n) {
    visited[c] = true;
=======
// Function to add an undirected edge between nodes u and v
void AddEdge(Graph *g, int u, int v) {
    g->edges[u][v] = 1; // Assuming adjacency matrix representation
    g->edges[v][u] = 1; // Undirected edge
}

// Depth-first search (DFS) algorithm to traverse the graph
void dfs(int c, int **edges, bool *visited, int n) {
    visited[c] = true;

>>>>>>> 98c87cb78a (data updated)
    for (int v = 0; v < n; v++) {
        if (edges[c][v] && !visited[v]) {
            dfs(v, edges, visited, n);
        }
    }
}

<<<<<<< HEAD
// Free the graph memory (not used in main)
void FreeGraph(Graph *g) {
=======
// Free the graph memory
void freeGraph(Graph *g) {
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < g->n; i++) {
        free(g->edges[i]);
    }
    free(g->edges);
    free(g);
}

// <END-OF-CODE>
