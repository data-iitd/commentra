
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#ifdef __cplusplus
#include <bits/stdc++.h>
#endif

// Function to read an integer from input
int32_t nextint(void) {
    char c = getchar_unlocked(); // Read a character
    // Skip non-digit characters until a digit or '-' is found
    while (c!= '-' && (c < '0' || '9' < c)) c = getchar_unlocked(); 
    bool s = false; // Flag for negative numbers
    if (c == '-') { // Check for negative sign
        s = true; 
        c = getchar_unlocked(); // Read the next character
    }
    uint32_t x = 0; // Variable to store the integer value
    // Convert characters to integer
    while ('0' <= c && c <= '9') { 
        x = x * 10 + c - '0'; 
        c = getchar_unlocked(); 
    }
    return s? -x : x; // Return the integer value, negated if necessary
}

int n; // Variable to store the number of nodes

// Function to calculate a unique identifier for a pair of nodes
int p(int a, int b) {
    if (a < b) {
        return a + b * n; // Return a unique index based on the order of a and b
    } else {
        return b + a * n; // Return a unique index based on the order of a and b
    }
}

int a[1000][999]; // Adjacency list representation of the graph

// Arrays to store edges and distances
int e1[1000000]; 
int e2[1000000];
int d[1000000]; // Array to store computed distances
bool b[1000000]; // Visited flag for nodes

// Recursive function to compute the maximum distance from a given node
int f(int from) {
    if (b[from]) return -1; // Return -1 if the node has already been visited (cycle detected)
    if (d[from]) return d[from]; // Return the computed distance if already calculated
    b[from] = true; // Mark the node as visited
    int to;
    to = e1[from]; // Get the first edge
    int max = 0; // Variable to track the maximum distance
    if (to!= 0) {
        int now = f(to); // Recursively compute distance for the first edge
        if (now < 0) return now; // Return if a cycle is detected
        if (now > max) max = now; // Update max if a longer distance is found
    }
    to = e2[from]; // Get the second edge
    if (to!= 0) {
        int now = f(to); // Recursively compute distance for the second edge
        if (now < 0) return now; // Return if a cycle is detected
        if (now > max) max = now; // Update max if a longer distance is found
    }
    b[from] = false; // Unmark the node as visited for future calls
    return d[from] = max + 1; // Store and return the computed distance
}

int main(void) {
    n = nextint(); // Read the number of nodes
    // Read the adjacency list from input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            a[i][j] = nextint() - 1; // Store edges, adjusting for 0-based indexing
        }
    }
    // Build the edge representation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 2; j++) {
            int from = p(i, a[i][j]); // Get unique index for the current edge
            int to = p(i, a[i][j + 1]); // Get unique index for the next edge
            // Store the edges in e1 and e2
            if (e1[from] == 0) {
                e1[from] = to; // Assign the first edge
            } else if (e2[from] == 0) {
                e2[from] = to; // Assign the second edge
            } else {
                puts("-1"); // Output -1 if more than two edges are found
                return 0; // Exit the program
            }
        }
    }
    int ans = 0; // Variable to store the final answer
    // Compute the maximum distance for each node
    for (int i = 0; i < n; i++) {
        int from = p(i, a[i][0]); // Get unique index for the starting edge
        int now = f(from); // Compute the distance
        if (now < 0) {
            ans = -1; // Set answer to -1 if a cycle is detected
            break; // Exit the loop
        }
        if (now > ans) ans = now; // Update the answer if a longer distance is found
    }
    printf("%d\n", ans); // Output the final answer
}


Translate the above C code to C++ and end with comment "