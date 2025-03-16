
#####
#include <bits/stdc++.h>
using namespace std;

#####
// Define a recursive function dfs to calculate the answer
#####
const int MOD = 1e9 + 7;
int dfs(int fro, int to, int f, vector<vector<int>>& graph) {
    // Initialize case number and color number
    int caseNum = 1;
    if (f == 0) {
        caseNum = 0;
    }
    int colorNum = f - 1;
    if (f == 0) {
        colorNum = f;
    }

    // Iterate through the neighbors of the current node
    for (int u : graph[fro]) {
        // Skip the target node
        if (u == to) {
            continue;
        }

        // Recursively call dfs on the neighbor and update case number
        int pat = dfs(u, fro, colorNum, graph);
        if (pat == 0) {
            caseNum = 0;
            break;
        }
        caseNum = 1LL * caseNum * pat % MOD;
        colorNum--;
    }

    // Return the final case number
    return caseNum;
}

#####
// Main function to read input and call the dfs function
#####
int main() {
    // Read input: number of nodes N and color limit K
    int N, K;
    cin >> N >> K;

    // Initialize an empty graph using vector
    vector<vector<int>> graph(N);

    // Read edges between nodes and add them to the graph
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // Call the dfs function with initial values and print the result
    int ans = dfs(0, -1, K, graph);
    cout << ans << endl;

    return 0;
}

