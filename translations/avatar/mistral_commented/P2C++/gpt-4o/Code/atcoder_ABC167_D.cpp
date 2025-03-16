#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Taking the number of nodes 'N' and the number of edges 'K' as input
    int N, K;
    cin >> N >> K;

    // Initializing the list 'L' with the given number of edges
    vector<int> L(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> L[i];
    }

    // Adding a special node with index -1 at the beginning of the list 'L'
    L.insert(L.begin(), -1);

    // Initializing an empty vector 'path' to store the shortest path
    vector<int> path;
    path.push_back(1);

    // Initializing variables 'ind' and 'count'
    int ind = 0;
    bool flag = false;
    int x = 1, t = -1;

    // Creating an empty hash table 'Hash'
    unordered_map<int, int> Hash;

    // Traversing through all the nodes from 0 to 'N'
    for (int i = 0; i <= N; ++i) {
        // Getting the next edge 'ne' from the current node 'x'
        int ne = L[x];

        // Checking if the current node 'ne' is already in the hash table 'Hash'
        if (Hash.find(ne) != Hash.end()) {
            // Setting the boolean variable 'flag' to true and storing the index of the previous occurrence of the node 'ne' in 't'
            flag = true;
            t = Hash[ne];
            break;
        }

        // Appending the next edge 'ne' to the list 'path'
        path.push_back(ne);

        // Incrementing the index 'ind' and storing it in the hash table 'Hash' with the key as the current node 'ne' and value as 'ind'
        ind++;
        Hash[ne] = ind;

        // Updating the current node 'x' to the next node 'ne'
        x = ne;
    }

    // Checking if there is a cycle in the graph
    if (flag) {
        // Storing the list of nodes in the cycle 'loop'
        vector<int> loop(path.begin() + t, path.end());

        // Checking if the length of the path is less than 'K'
        if (path.size() < K) {
            // Printing the 'K'th node in the path
            cout << path[K] << endl;
        } else {
            // Updating the value of 'K' by subtracting the length of the path and taking the modulo with the length of the cycle 'loop'
            K = K - path.size();
            K = K % loop.size();

            // Printing the 'K'th node in the cycle 'loop'
            cout << loop[K] << endl;
        }
    } else {
        // If there is no cycle in the graph, then we simply print the 'K'th node in the path
        cout << path[K - 1] << endl;
    }

    return 0;
}

// <END-OF-CODE>
