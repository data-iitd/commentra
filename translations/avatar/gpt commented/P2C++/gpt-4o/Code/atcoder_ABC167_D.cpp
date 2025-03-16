#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Read input values for N and K
    int N, K;
    cin >> N >> K;

    // Read the list L of length N
    vector<int> L(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> L[i];
    }
    L[0] = -1; // Insert a placeholder value at the beginning of the list

    // Initialize variables for path tracking and loop detection
    vector<int> path;
    path.push_back(1); // Start the path with the first node
    int ind = 0;       // Index to track the position in the path
    int x = 1;         // Current node starting from 1
    int t = -1;        // To store the index of the start of the loop if found
    bool flag = false; // Flag to indicate if a loop is detected
    unordered_map<int, int> Hash; // Map to store the last index of each node

    // Iterate through the nodes to detect loops
    for (int i = 0; i <= N; ++i) {
        int ne = L[x]; // Get the next node from the list L
        // Check if the next node has been visited before
        if (Hash.find(ne) != Hash.end()) {
            flag = true; // Set the flag to indicate a loop is found
            t = Hash[ne]; // Store the index where the loop starts
            break; // Exit the loop since a cycle is detected
        }
        // Append the next node to the path
        path.push_back(ne);
        ind++; // Increment the index
        Hash[ne] = ind; // Update the last index of the current node
        x = ne; // Move to the next node
    }

    // Check if a loop was detected
    if (flag) {
        vector<int> loop(path.begin() + t, path.end()); // Extract the loop from the path
        // Check if K is within the length of the path
        if (K < path.size()) {
            cout << path[K] << endl; // Print the K-th node in the path
        } else {
            K = K - path.size(); // Adjust K to account for the full path length
            K = K % loop.size(); // Get the position within the loop
            cout << loop[K] << endl; // Print the K-th node in the loop
        }
    } else {
        cout << path[K - 1] << endl; // If no loop, print the K-th node in the path
    }

    return 0;
}

// <END-OF-CODE>
