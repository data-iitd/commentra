#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

// Adjacency list to represent the graph
static int **g; 

// Function to calculate the maximum matching in the graph
static int maxMatching(int v, int p) {
    int a = 0; // Count of pairs in matching
    int o = 0; // Count of unmatched vertices
    
    // Iterate through all adjacent vertices of v
    for (int i = 0; i < g[v][0]; ++i) {
        // Skip the parent vertex to avoid cycles
        if (g[v][i + 1] == p) continue; 
        
        // Recursively find the matching for the adjacent vertex
        int r = maxMatching(g[v][i + 1], v); 
        a += r / 2; // Update count of pairs
        o += r % 2; // Update count of unmatched vertices
    }
    
    // Return the total matching count
    return 2 * a + MIN(1, o) + 1; 
} 

int main() {
    // Initialize scanner for input
    MyScanner sc = new MyScanner(); 
    // Initialize output writer
    out = new PrintWriter(new BufferedOutputStream(System.out)); 
    
    // Read the number of vertices
    int n = sc.nextInt(); 
    // Initialize the adjacency list for the graph
    g = malloc(n * sizeof(int *)); 
    for (int i = 0; i < n; ++i) {
        g[i] = malloc(1 * sizeof(int)); 
        g[i][0] = 0; 
    }
    
    // Read edges and populate the adjacency list
    for (int i = 0; i < n - 1; ++i) {
        int a = sc.nextInt() - 1; // Read vertex a
        int b = sc.nextInt() - 1; // Read vertex b
        g[a][0]++; // Increment the number of adjacent vertices
        g[a] = realloc(g[a], (g[a][0] + 1) * sizeof(int)); 
        g[a][g[a][0]] = b; // Add edge to the graph
        g[b][0]++; // Increment the number of adjacent vertices
        g[b] = realloc(g[b], (g[b][0] + 1) * sizeof(int)); 
        g[b][g[b][0]] = a; // Add edge to the graph (undirected)
    }
    
    // Calculate maximum matching starting from vertex 0
    int m = maxMatching(0, -1) / 2; 
    
    // Determine the winner based on the matching result
    out.println(2 * m == n ? "Second" : "First"); 
    
    // Close the output writer
    out.close(); 
} 

// Output writer for printing results
static PrintWriter out; 

// Custom scanner class for efficient input reading
static struct MyScanner {
    FILE *br; // Buffered reader for input
    char *st; // Tokenizer for parsing input
    
    // Constructor to initialize the buffered reader
    MyScanner() { 
        br = fopen("input.txt", "r"); 
    } 
    
    // Method to read the next token
    char *next() { 
        while (st == NULL || !strtok(st, " ")) { 
            st = NULL; 
            char *str = malloc(100000 * sizeof(char)); 
            fgets(str, 100000, br); 
            st = strtok(str, " "); 
            free(str); 
        } 
        return st; 
    } 
    
    // Method to read the next integer
    int nextInt() { 
        return atoi(next()); 
    } 
    
    // Method to read the next long
    long nextLong() { 
        return atol(next()); 
    } 
    
    // Method to read the next double
    double nextDouble() { 
        return atof(next()); 
    } 
    
    // Method to read the next line
    char *nextLine() { 
        char *str = malloc(100000 * sizeof(char)); 
        fgets(str, 100000, br); 
        return str; 
    } 
}

