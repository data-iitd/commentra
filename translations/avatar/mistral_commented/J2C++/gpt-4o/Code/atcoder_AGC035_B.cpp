#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Main function where the program starts execution.
int main() {
    int numNode, numEdge;
    cin >> numNode >> numEdge; // Reading the number of nodes and edges from the input.

    // Initializing the connect vector to store the list of neighbors for each node.
    vector<vector<int>> connect(numNode);
    
    // Reading the edges and adding them to the connect vector.
    for (int i = 0; i < numEdge; i++) {
        int a, b;
        cin >> a >> b; // Reading the first and second node indices.
        connect[a - 1].push_back(b - 1); // Adding the second node index to the first node's list of neighbors.
        connect[b - 1].push_back(a - 1); // Adding the first node index to the second node's list of neighbors.
    }

    // Checking if the number of edges is odd. If it is, then the graph is not bipartite, and we print -1 and exit.
    if (numEdge % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    // Initializing the visited, odd, and print variables.
    vector<int> visited(numNode, 0);
    vector<bool> odd(numNode, false);
    stringstream print; // Using stringstream to store the output.

    // Recursive depth-first search function to perform bipartite traversal.
    function<void(int, int)> dfs = [&](int crt, int parent) {
        // Marking the current node as visited.
        visited[crt] = 1;

        // Iterating through the neighbors of the current node.
        for (int child : connect[crt]) {
            // Skipping the neighbor if it is the parent node or already visited.
            if (child == parent || visited[child] == 1) {
                continue;
            }

            // If the neighbor has already been assigned an odd component, then we add an edge between the current and neighbor nodes.
            // Otherwise, we swap the components and continue the traversal.
            if (visited[child] == 2) {
                print << (crt + 1) << " " << (child + 1) << "\n";
                odd[crt] = !odd[crt];
            } else {
                dfs(child, crt);
                if (odd[child]) {
                    print << (child + 1) << " " << (crt + 1) << "\n";
                    odd[child] = !odd[child];
                } else {
                    print << (crt + 1) << " " << (child + 1) << "\n";
                    odd[crt] = !odd[crt];
                }
            }
        }

        // Marking the current node as visited with component 2.
        visited[crt] = 2;
    };

    // Calling the dfs function with the first node and -1 as the parent node.
    dfs(0, -1);

    // Printing the output.
    cout << print.str();
    
    return 0;
}

// <END-OF-CODE>
