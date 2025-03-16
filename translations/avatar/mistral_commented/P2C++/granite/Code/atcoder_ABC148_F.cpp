
#include <bits/stdc++.h>
using namespace std;

// Function to take input as an integer
int inp(){
    int x;
    cin >> x;
    return x;
}

// Function to take input as a list
vector<int> inpl(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    return a;
}

// Input the number of nodes, starting and ending nodes
int n, ta, ao;
cin >> n >> ta >> ao;
ta--; ao--;

// Initialize an adjacency list
vector<vector<int>> g(n);

// Read edges and add them to the graph
for(int i=0;i<n-1;i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
}

// Initialize distance arrays for both nodes
vector<int> ta_dist(n, -1);
vector<int> ao_dist(n, -1);

// Initialize distances for starting and ending nodes
ta_dist[ta] = 0;
ao_dist[ao] = 0;

// Function to perform Depth First Search from a node and calculate distances
void dfs(vector<vector<int>>& g, vector<int>& dist, int node){
    for(int v: g[node]){
        if(dist[v]!= -1) continue;
        dist[v] = dist[node] + 1;
        dfs(g, dist, v);
    }
}

// Perform Depth First Search from starting and ending nodes
dfs(g, ta_dist, ta);
dfs(g, ao_dist, ao);

// Calculate the answer
int res = 0;
for(int i=0;i<n;i++){
    if(ta_dist[i] == -1 || ao_dist[i] == -1 || ta_dist[i] > ao_dist[i]) continue;
    res = max(res, ao_dist[i]);
}

// Print the answer
cout << res-1 << endl;

