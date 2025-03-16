#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000
#define MOD 1000000007

int getInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int N = getInt();
    int sqrtN = (int)sqrt(N);

    int minVal = N;
    for (int i = 1; i <= sqrtN; i++) {
        if (N % i != 0) {
            continue;
        }

        int num = i + (N / i) - 2;
        minVal = min(minVal, num);
    }

    printf("%d\n", minVal);
    return 0;
}

typedef struct {
    int n;
    int **edges;
} Graph;

Graph* NewGraph(int n) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->n = n;
    g->edges = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        g->edges[i] = (int *)malloc(n * sizeof(int));
    }
    return g;
}

void AddEdge(Graph *g, int u, int v) {
    g->edges[u][v] = 1; // Assuming an adjacency matrix representation
    g->edges[v][u] = 1; // Undirected graph
}

void dfs(int c, int **edges, bool *visited, int n) {
    visited[c] = true;

    for (int v = 0; v < n; v++) {
        if (edges[c][v] && !visited[v]) {
            dfs(v, edges, visited, n);
        }
    }
}

int abs(int a) {
    return a < 0 ? -a : a;
}

int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return (t * t) % MOD;
    } else {
        return (n * powMod(n, p - 1)) % MOD;
    }
}

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int sqrtN = (int)sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void reverse(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

// Additional utility functions can be added as needed

// Note: Memory management (freeing allocated memory) should be handled appropriately in a complete implementation.

