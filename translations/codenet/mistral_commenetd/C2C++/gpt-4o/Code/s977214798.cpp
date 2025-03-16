#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to read an integer from standard input
int32_t nextint() {
    char c = getchar();
    while (c != '-' && (c < '0' || '9' < c)) c = getchar();
    bool s = false;
    if (c == '-') { s = true; c = getchar(); }
    uint32_t x = 0;
    while ('0' <= c && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return s ? -x : x;
}

int n;

// Function to calculate the result of the given expression p(a, b)
int p(int a, int b) {
    // Check if a is smaller than b
    if (a < b) {
        return a + b * n;
    } else {
        return b + a * n;
    }
}

// 2D vector a of size n x (n-1)
vector<vector<int>> a(1000, vector<int>(999));

// Vectors e1, e2 and d of size 1000000 each
vector<int> e1(1000000, 0);
vector<int> e2(1000000, 0);
vector<int> d(1000000, 0);

// Boolean vector b of size 1000000
vector<bool> b(1000000, false);

// Function to perform Depth First Search (DFS) from a given vertex 'from'
int f(int from) {
    // Check if vertex 'from' has already been visited
    if (b[from]) return -1;
    // If vertex 'from' has already been processed, return its depth
    if (d[from]) return d[from];
    // Mark vertex 'from' as visited
    b[from] = true;
    // Initialize maximum depth as 0
    int maxDepth = 0;
    // Traverse to the adjacent vertices of 'from'
    int to;
    to = e1[from];
    // If the adjacent vertex 'to' is not yet visited, perform DFS recursively and update the maximum depth
    if (to != 0) {
        int now = f(to);
        if (now < 0) return now;
        if (now > maxDepth) maxDepth = now;
    }
    // Traverse to the next adjacent vertex of 'from'
    to = e2[from];
    // If the adjacent vertex 'to' is not yet visited, perform DFS recursively and update the maximum depth
    if (to != 0) {
        int now = f(to);
        if (now < 0) return now;
        if (now > maxDepth) maxDepth = now;
    }
    // Mark vertex 'from' as not visited
    b[from] = false;
    // Update the depth of vertex 'from' with the maximum depth found during DFS
    return d[from] = maxDepth + 1;
}

int main() {
    // Read the number of vertices n from standard input
    n = nextint();
    // Initialize 2D vector a of size n x (n-1)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            // Read an edge weight from standard input and store it in the corresponding position of vector a
            a[i][j] = nextint() - 1;
        }
    }
    // Initialize vectors e1, e2 and d with zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 2; j++) {
            // Read an edge from standard input and store it in the corresponding position of vectors e1 or e2 based on its direction
            int from = p(i, a[i][j]);
            int to = p(i, a[i][j + 1]);
            if (e1[from] == 0) {
                e1[from] = to;
            } else if (e2[from] == 0) {
                e2[from] = to;
            } else {
                // If there is a cycle in the graph, print '-1' and exit the program
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    // Initialize an empty stack or array to store the vertices in Depth First Search order
    int ans = 0;
    // Perform Depth First Search from each vertex and update the answer with the maximum depth found
    for (int i = 0; i < n; i++) {
        int from = p(i, a[i][0]);
        int now = f(from);
        if (now < 0) {
            ans = -1;
            break;
        }
        if (now > ans) ans = now;
    }
    // Print the answer
    cout << ans << endl;
}

// <END-OF-CODE>
