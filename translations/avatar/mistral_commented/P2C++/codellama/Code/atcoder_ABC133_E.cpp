#######
// Import necessary libraries
#######
#include <bits/stdc++.h>
using namespace std;

#######
// Initialize an empty graph using vector
#######
vector<vector<int>> graph;

#######
// Read input: number of nodes N and color limit K
#######
int N, K;
cin >> N >> K;

#######
// Read edges between nodes and add them to the graph
#######
graph.resize(N);
for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
}

#######
// Define a recursive function dfs to calculate the answer
#######
const int mod = 1e9 + 7;
int dfs(int fro, int to, int f) {
    // Initialize case number and color number
    int caseNum = 1;
    int colorNum = K - 1;

    // Iterate through the neighbors of the current node
    for (int u : graph[fro]) {
        // Skip the target node
        if (u == to) {
            continue;
        }

        // Recursively call dfs on the neighbor and update case number
        int pat = dfs(u, fro, colorNum);
        if (pat == 0) {
            caseNum = 0;
            break;
        }
        caseNum = (caseNum * pat) % mod;
        colorNum--;
    }

    // Return the final case number
    return caseNum;
}

#######
// Call the dfs function with initial values and print the result
#######
int ans = dfs(0, -1, K);
cout << ans << endl;

