#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 

// Constant for modulo operation
const int MOD = 1000000007; 

// Structure to represent a Union-Find data structure
typedef struct { 
    int n; // Number of elements
    int* par; // Parent array
    int* rank; // Rank array for union by rank
} UnionFindTree; 

// Method to execute the main logic
void doIt() { 
    // Read the number of elements (nodes)
    int n; 
    scanf("%d", &n); 
    // Initialize Union-Find data structure with n elements
    UnionFindTree utf = {n, (int*)malloc(n * sizeof(int)), (int*)malloc(n * sizeof(int))}; 
    // Initialize each element to be its own parent and rank to 0
    for (int i = 0; i < n; i++) { 
        utf.par[i] = i; 
        utf.rank[i] = 0; 
    } 
    // Read the number of connections (edges)
    int m; 
    scanf("%d", &m); 
    
    // Process each connection
    for (int i = 0; i < m; i++) { 
        // Read the two nodes to unite and the weight (not used in this implementation)
        int x, y, z; 
        scanf("%d %d %d", &x, &y, &z); 
        // Unite the two nodes
        unite(&utf, x - 1, y - 1); 
    } 
    
    // Count the number of unique connected components
    int cnt = 0; 
    for (int i = 0; i < n; i++) { 
        // Check if the current node is a root of a component
        if (utf.par[i] == i) { 
            cnt++; 
        } 
    } 
    
    // Output the count of unique connected components
    printf("%d\n", cnt); 
} 

// Method to unite the sets containing x and y
void unite(UnionFindTree* utf, int x, int y) { 
    x = find(utf, x); 
    y = find(utf, y); 
    // If they are already in the same set, do nothing
    if (x == y) return; 
    // Union by rank
    if (utf->rank[x] < utf->rank[y]) 
        utf->par[x] = y; 
    else { 
        utf->par[y] = x; 
        if (utf->rank[x] == utf->rank[y]) 
            utf->rank[x]++; 
    } 
} 

// Method to find the root of the set containing x with path compression
int find(UnionFindTree* utf, int x) { 
    if (utf->par[x] == x) { 
        return x; 
    } else { 
        return utf->par[x] = find(utf, utf->par[x]); 
    } 
} 

// Method to check if x and y are in the same set
bool same(UnionFindTree* utf, int x, int y) { 
    return find(utf, x) == find(utf, y); 
} 

// Main method to start the program
int main() { 
    doIt(); 
    return 0; 
} 

