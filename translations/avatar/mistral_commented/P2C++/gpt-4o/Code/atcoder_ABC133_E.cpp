#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Set recursion limit
const int MAX_RECURSION_LIMIT = 10000000;

// Initialize an empty graph using unordered_map
unordered_map<int, vector<int>> graph;

// Define the modulo constant
const int MOD = 1e9 + 7;

// Define a recursive function dfs to calculate the answer
int dfs(int fro, int to, int f) {
    // Initialize case number and color number
    int caseNum = (f == K) ? 1 : 0;
    int colorNum = (f == K) ? (K - 1) : (K - 2);

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
        caseNum = (1LL * caseNum * pat) % MOD;
        colorNum--;
    }

    // Return the final case number
    return caseNum;
}

int main() {
    // Read input: number of nodes N and color limit K
    int N, K;
    cin >> N >> K;

    // Read edges between nodes and add them to the graph
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    // Call the dfs function with initial values and print the result
    int ans = dfs(0, -1, K);
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
