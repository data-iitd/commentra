
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables
    int N, K;
    cin >> N >> K;

    // Declare graph
    vector<vector<int>> graph(N);

    // Read edges between nodes and add them to the graph
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    // Define a recursive function dfs to calculate the answer
    int mod = 1000000007;
    function<int(int, int, int)> dfs = [&](int fro, int to, int f) {
        // Initialize case number and color number
        int caseNum = 1 if (f == K) else 0;
        int colorNum = K - 1 if (f == K) else K - 2;

        // Iterate through the neighbors of the current node
        for (int u : graph[fro]) {
            // Skip the target node
            if (u == to) continue;

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
    };

    // Call the dfs function with initial values and print the result
    cout << dfs(0, -1, K) << "\n";

    return 0;
}

