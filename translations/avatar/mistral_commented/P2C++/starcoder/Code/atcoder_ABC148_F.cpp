#include <bits/stdc++.h>
using namespace std;

// Function to take input as an integer
int inp() {
    int n;
    cin >> n;
    return n;
}

// Function to take input as a list
vector<int> inpl() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    return v;
}

// Input the number of nodes, starting and ending nodes
int n, ta, ao;
cin >> n >> ta >> ao;
ta--; ao--;

// Initialize an adjacency list
vector<vector<int>> g(n);

// Read edges and add them to the graph
for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
}

// Initialize distance arrays for both nodes
vector<int> ta_dist(n), ao_dist(n);

// Initialize distances for starting and ending nodes
ta_dist[ta] = 0;
ao_dist[ao] = 0;

// Depth First Search from starting node to calculate distances from starting node
void ta_dfs(int node) {
    for (int v : g[node]) {
        if (ta_dist[v]!= -1) continue;
        ta_dist[v] = ta_dist[node] + 1;
        ta_dfs(v);
    }
}

// Depth First Search from ending node to calculate distances from ending node
void ao_dfs(int node) {
    for (int v : g[node]) {
        if (ao_dist[v]!= -1) continue;
        ao_dist[v] = ao_dist[node] + 1;
        ao_dfs(v);
    }
}

// Perform Depth First Search from starting and ending nodes
ao_dfs(ao);
ta_dfs(ta);

// Calculate the answer
int res = 0;
for (int i = 0; i < n; i++) {
    if (ta_dist[i] == -1 || ao_dist[i] == -1 || ta_dist[i] > ao_dist[i]) continue;
    res = max(res, ao_dist[i]);
}

// Print the answer
cout << res-1 << endl;

// 