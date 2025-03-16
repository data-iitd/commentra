
#include <stdio.h>
#include <string.h>

typedef long long ll;

/**
 * Bit Matching Algorithm
 *
 * Time Complexity: O(EV)
 */
typedef struct {
    int *G[2*MN]; // Graph representation using adjacency list
    int match[2*MN]; // Array to store the match of each node
    bool used[2*MN]; // Array to keep track of used nodes in DFS
} BitMatching;

/// Initialize the graph
void init(BitMatching *bm) {
    for (int i = 0; i < 2*MN; i++) {
        bm->G[i] = NULL; // Clear all edges
    }
}

/// Add an edge between node a and node b in the bipartite graph
void add(BitMatching *bm, int a, int b) {
    int *p = (int *)malloc(sizeof(int));
    *p = b+MN;
    bm->G[a] = (int *)realloc(bm->G[a], sizeof(int)*(bm->G[a]?bm->G[a][0]+1:1));
    bm->G[a][bm->G[a][0]] = *p;
    bm->G[a][0]++;
    bm->G[*p] = (int *)realloc(bm->G[*p], sizeof(int)*(bm->G[*p]?bm->G[*p][0]+1:1));
    bm->G[*p][bm->G[*p][0]] = a;
    bm->G[*p][0]++;
}

/// Depth-First Search to find augmenting paths
bool dfs(BitMatching *bm, int v) {
    bm->used[v] = true; // Mark the node as visited
    for (int i = 0; i < bm->G[v][0]; i++) {
        int u = bm->G[v][i], w = bm->match[u];
        if (w < 0 || (!bm->used[w] && dfs(bm, w))) { // If the node is not matched or can find an augmenting path
            bm->match[v] = u; // Assign the match
            bm->match[u] = v; // Assign the match
            return true; // Return true as we found an augmenting path
        }
    }
    return false; // Return false if no augmenting path is found
}

/// Execute the bipartite matching algorithm
int exec(BitMatching *bm) {
    int res = 0; // Initialize the result
    memset(bm->match, -1, sizeof(bm->match)); // Initialize all matches to -1 (no match)
    for (int v = 0; v < MN; v++) {
        if (bm->match[v] < 0) { // If the node is not matched
            memset(bm->used, 0, sizeof(bm->used)); // Reset the used array
            if (dfs(bm, v)) { // Perform DFS from the node
                res++; // Increment the result if an augmenting path is found
            }
        }
    }
    return res; // Return the total number of matches found
}

const int MN = 520;
BitMatching bm; // Create an instance of BitMatching with maximum number of vertices as 520

/// Function to compute the greatest common divisor (GCD) of two numbers
ll gcd(ll a, ll b) {
    if (b == 0) return a; // Base case: if b is 0, return a
    return gcd(b, a%b); // Recursive call: compute GCD of b and the remainder of a divided by b
}

int main() {
    while (true) {
        int n, m;
        scanf("%d%d", &n, &m); // Read the number of elements in the two sets
        if (!n) break; // If n is 0, break the loop
        init(&bm); // Initialize the bipartite graph
        int a[n], b[m]; // Arrays to store the elements of the two sets
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]); // Read the elements of the first set
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]); // Read the elements of the second set
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (gcd(a[i], b[j])!= 1) { // Check if the GCD is not 1
                    add(&bm, i, j); // Add an edge between the corresponding nodes if GCD is not 1
                }
            }
        }
        printf("%d\n", exec(&bm)); // Execute the bipartite matching and print the result
    }
    return 0;
}
