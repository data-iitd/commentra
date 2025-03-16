#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

int main() {
    // Read the first line of input containing the number of nodes 'n' and edges 'm'
    int n, m;
    cin >> n >> m;

    // Initialize a vector 'p' of numbers from 1 to 'n'
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i + 1;
    }

    // Read the second line of input containing the heights of the nodes
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    // Create a map 'hp' to store node number as key and height as value
    unordered_map<int, int> hp;
    for (int i = 0; i < n; ++i) {
        hp[p[i]] = h[i];
    }

    // Initialize an empty map 'path' to store the graph
    unordered_map<int, vector<int>> path;
    for (int i = 1; i <= n; ++i) {
        path[i] = vector<int>();
    }

    // Read 'm' lines of input containing edges and add them to the 'path' map
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    // Initialize a counter 'c' to store the number of valid paths
    int c = 0;

    // Iterate through each node in the graph and check if it forms a valid path
    for (const auto& [i, v] : path) {
        // Initialize a flag 'f' to check if the current node is a valid starting point
        bool f = false;
        // Iterate through each neighbor of the current node and check if it is a valid ending point
        for (int j : v) {
            // If the height of the current node is less than or equal to the height of its neighbor,
            // then it is not a valid path and we set the flag 'f' to true and break the loop
            if (hp[i] <= hp[j]) {
                f = true;
                break;
            }
        }
        // If the flag 'f' is still false after checking all neighbors, then this node forms a valid path
        // and we increment the counter 'c'
        if (!f) {
            c++;
        }
    }

    // Print the final result, i.e., the number of valid paths
    cout << c << endl;

    return 0;
}

// <END-OF-CODE>
