#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the number of nodes N
    int N;
    cin >> N;

    // Initialize adjacency list to store the graph
    vector<vector<int>> adj(N + 1);

    // Read N-1 edges and populate the adjacency list
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Initialize deque for BFS and seen array to track visited nodes
    deque<int> que;
    que.push_back(1);
    vector<int> seen(N + 1, 0);
    seen[1] = 1;

    // Array to store parent nodes
    vector<int> par(N + 1, 0);

    // Array to count the number of children for each node
    vector<int> child_num(N + 1, 0);

    // Perform BFS to find parent and child relationships
    while (!que.empty()) {
        int v = que.front();
        que.pop_front();
        for (int u : adj[v]) {
            if (seen[u] == 0) {
                seen[u] = 1;
                par[u] = v;
                child_num[v]++;
                que.push_back(u);
            }
        }
    }

    // Find leaf nodes (nodes with no children)
    deque<int> seq;
    for (int i = 1; i <= N; ++i) {
        if (child_num[i] == 0) {
            seq.push_back(i);
        }
    }

    // Process leaf nodes to determine the winning strategy
    while (!seq.empty()) {
        int c = seq.back();
        seq.pop_back();
        seen[c] = 0;
        if (seen[par[c]] == 0) {
            cout << "First" << endl;
            return 0;
        }
        seen[par[c]] = 0;
        child_num[par[par[c]]]--;
        if (child_num[par[par[c]]] == 0) {
            seq.push_back(par[par[c]]);
        }
    }

    // If no winning strategy is found for the first player, print 'Second'
    cout << "Second" << endl;

    return 0;
}

// <END-OF-CODE>
