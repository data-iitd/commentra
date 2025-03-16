#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

const int maxn = 1e5 + 5; // Define a constant for the maximum number of nodes

struct Node {
    int x, y, id; // Define a structure for nodes with x, y coordinates and an id
}node[maxn];

struct Edge {
    int u, v, val; // Define a structure for edges with u, v nodes and a value
    bool operator <(const Edge& rhs) const { // Overload the less-than operator for sorting edges by value
        return val < rhs.val;
    }
}e[maxn << 1]; // Define an array for edges with a size of up to 2*maxn

int par[maxn]; // Define an array for storing the parent of each node
int n; // Define an integer for the number of nodes

bool cmp1(const Node &a, const Node &b) { // Define a comparison function to sort nodes by x coordinate
    return a.x < b.x;
}

bool cmp2(const Node &a, const Node &b) { // Define a comparison function to sort nodes by y coordinate
    return a.y < b.y;
}

void init() { // Define a function to initialize the parent array
    for (int i = 0; i <= n; i ++)
        par[i] = i;
}

int findpar(int x) { // Define a function to find the root of a node using path compression
    return par[x] = (par[x] == x ? x : findpar(par[x]));
}

void unite(int x, int y) { // Define a function to merge two sets
    x = findpar(x), y = findpar(y);
    if (x == y) return;
    par[x] = y;
}

int main(int argc, char const *argv[]) {
    
    cin >> n; // Read the number of nodes

    init(); // Initialize the parent array

    for (int i = 1; i <= n; i ++) {
        scanf("%d%d", &node[i].x, &node[i].y); // Read the coordinates of each node
        node[i].id = i; // Assign an id to each node
    }

    sort(node + 1, node + n + 1, cmp1); // Sort nodes by x coordinate and create edges based on x differences

    int cnt = 0; // Initialize a counter for edges
    for (int i = 2; i <= n; i ++)
        e[cnt ++] = (Edge){node[i - 1].id, node[i].id, node[i].x - node[i - 1].x}; // Create edges based on x differences
    
    sort(node + 1, node + n + 1, cmp2); // Sort nodes by y coordinate and create edges based on y differences
    for (int i = 2; i <= n; i ++)
        e[cnt ++] = (Edge){node[i - 1].id, node[i].id, node[i].y - node[i - 1].y}; // Create edges based on y differences

    sort(e, e + cnt); // Sort all edges by their values

    long long ans = 0; // Initialize a variable to store the total weight of the minimum spanning tree
    for (int i = 0; i < cnt; i ++) {
        int u = e[i].u, v = e[i].v, val = e[i].val;
        if (findpar(u) == findpar(v)) continue; // Skip if u and v are already in the same set
        unite(u, v); // Merge u and v
        ans += val; // Add the edge value to the total weight
    }

    cout << ans << endl; // Output the total weight of the minimum spanning tree

    return 0;
}
