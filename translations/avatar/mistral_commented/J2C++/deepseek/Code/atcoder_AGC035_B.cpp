#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Main method where the program starts execution.
int main() {
    int numNode, numEdge;
    cin >> numNode >> numEdge;

    // Initializing the connect array to store the list of neighbors for each node.
    vector<int> connect[numNode];

    // Reading the edges and adding them to the connect array.
    for (int i = 0; i < numEdge; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Adjusting the node indices to be 0-based.
        connect[a].push_back(b); // Adding the second node index to the first node's list of neighbors.
        connect[b].push_back(a); // Adding the first node index to the second node's list of neighbors.
    }

    // Checking if the number of edges is odd. If it is, then the graph is not bipartite, and we print -1 and exit.
    if (numEdge % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    // Initializing the visited, odd, and print arrays and objects.
    vector<int> visited(numNode, 0);
    vector<bool> odd(numNode, false);
    queue<int> q;
    vector<pair<int, int>> edges;

    // Calling the bfs method with the first node.
    q.push(0);
    visited[0] = 1;

    while (!q.empty()) {
        int crt = q.front();
        q.pop();

        // Iterating through the neighbors of the current node.
        for (int child : connect[crt]) {
            // Skipping the neighbor if it is already visited.
            if (visited[child] == 1) {
                continue;
            }

            // If the neighbor has already been assigned an odd component, then we add an edge between the current and neighbor nodes.
            // Otherwise, we swap the components and continue the traversal.
            if (visited[child] == 2) {
                edges.push_back({crt + 1, child + 1});
                odd[crt] = !odd[crt];
            } else {
                q.push(child);
                visited[child] = 1;
                if (odd[crt]) {
                    edges.push_back({child + 1, crt + 1});
                    odd[child] = !odd[child];
                } else {
                    edges.push_back({crt + 1, child + 1});
                    odd[crt] = !odd[crt];
                }
            }
        }

        // Marking the current node as visited with component 2.
        visited[crt] = 2;
    }

    // Printing the output.
    for (auto &edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}
