
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

const int maxn = 1e5 + 5; // maximum number of nodes in the graph

struct Node {
    int x, y, id; // x and y coordinates, id of each node
}node[maxn];

struct Edge {
    int u, v, val; // u and v are the ids of the nodes connected by the edge, the value of the edge
}e[maxn << 1];

int par[maxn]; // parent array to keep track of the parent of each node in the disjoint set data structure
int n; // number of nodes in the graph

// Comparator function for sorting nodes based on their x-coordinates
bool cmp1(const Node &a, const Node &b) {
    return a.x < b.x;
}

// Comparator function for sorting nodes based on their y-coordinates
bool cmp2(const Node &a, const Node &b) {
    return a.y < b.y;
}

// Initialization function for the disjoint set data structure
void init() {
    for (int i = 0; i <= n; i ++)
        par[i] = i; // each node initially belongs to its own set
}

// Function to find the representative of a set
int findpar(int x) {
    return par[x] = (par[x] == x ? x : findpar(par[x])); // path compression is used to reduce the height of the tree
}

// Function to merge two sets
void unite(int x, int y) {
    x = findpar(x), y = findpar(y);
    if (x == y) return; // no need to merge if they already belong to the same set
    par[x] = y; // merge by making the root of set y as the parent of the root of set x
}

int main(int argc, char const *argv[]) {
    
    cin >> n; // read the number of nodes in the graph

    init(); // initialize the disjoint set data structure

    // Read the coordinates of each node and assign an id to it
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d", &node[i].x, &node[i].y);
        node[i].id = i; // id is just the index of the node in the node array
    }

    // Sort the nodes based on their x-coordinates
    sort(node + 1, node + n + 1, cmp1);

    int cnt = 0; // initialize the counter for the number of edges
    // Create edges between adjacent nodes based on their x-coordinates
    for (int i = 2; i <= n; i ++) {
        e[cnt++] = (Edge){node[i - 1].id, node[i].id, node[i].x - node[i - 1].x};
    }

    // Sort the nodes based on their y-coordinates
    sort(node + 1, node + n + 1, cmp2);
    // Create edges between adjacent nodes based on their y-coordinates
    for (int i = 2; i <= n; i ++) {
        e[cnt++] = (Edge){node[i - 1].id, node[i].id, node[i].y - node[i - 1].y};
    }

    // Sort the edges based on their values
    sort(e, e + cnt);

    long long ans = 0; // initialize the answer to 0
    // Process each edge in the sorted order
    for (int i = 0; i < cnt; i ++) {
        int u = e[i].u, v = e[i].v, val = e[i].val;
        // Skip if the nodes are already in the same set
        if (findpar(u) == findpar(v)) continue;
        // Merge the sets of the nodes and add the value of the edge to the answer
        unite(u, v);
        ans += val;
    }

    cout << ans << endl; // print the final answer

    return 0;
}