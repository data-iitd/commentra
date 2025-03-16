#include <iostream>
#include <vector>
#define MAX 101
#define WHITE 0
#define BLACK 2
#define GRAY 1

int time, n;
int d[MAX], f[MAX], color[MAX] = {WHITE}; // initialize depth, finish, and color arrays
std::vector<std::vector<int>> g(MAX, std::vector<int>(MAX, 0)); // 2D adjacency matrix g

void visit(int u) { // function to perform Depth First Search (DFS) from vertex 'u'
    color[u] = GRAY; // mark the current vertex as 'gray'
    d[u] = ++time; // assign depth value to the current vertex

    for (int i = 0; i < n; i++) { // iterate through all the adjacent vertices of 'u'
        if (g[u][i] == 0) // if there is no edge between 'u' and 'i'
            continue;
        if (color[i] == WHITE) // if 'i' is not yet visited
            visit(i); // recursively call DFS on 'i'
    }

    color[u] = BLACK; // mark the current vertex as 'black'
    f[u] = ++time; // assign finish value to the current vertex
}

void dfs() { // function to perform DFS on the entire graph
    time = 0; // initialize time counter

    for (int i = 0; i < n; i++) // iterate through all the vertices in the graph
        if (color[i] == WHITE) // if 'i' is not yet visited
            visit(i); // recursively call DFS on 'i'

    for (int i = 0; i < n; i++) // print the depth, finish, and vertex number for each vertex
        std::cout << i + 1 << " " << d[i] << " " << f[i] << std::endl;
}

int main() { // main function
    std::cin >> n; // read the number of vertices in the graph

    for (int i = 0; i < n; i++) { // iterate through each vertex in the graph
        int x, y;
        std::cin >> x >> y; // read the number of edges and their destinations for the current vertex

        for (int j = 0; j < y; j++) { // iterate through all the edges for the current vertex
            int z;
            std::cin >> z; // read the destination vertex for the current edge
            g[x - 1][z - 1] = 1; // mark that there is an edge between 'x' and 'z'
        }
    }

    dfs(); // call DFS function to perform DFS on the entire graph
    return 0;
}

// <END-OF-CODE>
