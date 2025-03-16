#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Read the values of N and K from input
    int N, K;
    cin >> N >> K;

    // Read the list L of integers from input
    vector<int> L(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> L[i];
    }

    // Insert -1 at the beginning of the list L
    L[0] = -1;

    // Initialize the path vector with the first element 1
    vector<int> path;
    path.push_back(1);

    // Initialize index tracker to 0
    int ind = 0;

    // Initialize count to 0
    int count = 0;

    // Initialize current position to 1
    int x = 1;

    // Initialize loop start index to -1
    int t = -1;

    // Initialize flag to indicate loop detection
    bool flag = false;

    // Initialize an unordered_map to keep track of indices of elements in path
    unordered_map<int, int> Hash;

    // Main loop to traverse the path
    for (int i = 0; i <= N; ++i) {
        // Get the next element in the path
        int ne = L[x];

        // Check if the next element is already in the Hash
        if (Hash.find(ne) != Hash.end()) {
            // Loop detected, set flag and record the start index
            flag = true;
            t = Hash[ne];
            break;
        }

        // Append the next element to the path and update index
        path.push_back(ne);
        ind++;

        // Update the Hash with the current index
        Hash[ne] = ind;

        // Move to the next element
        x = ne;
    }

    // Check if a loop is detected
    if (flag) {
        // Create a loop slice from the detected start index to the end
        vector<int> loop(path.begin() + t, path.end());

        // If K is within the bounds of the path length, print the K-th element
        if (K < path.size()) {
            cout << path[K] << endl;
        } else {
            // Adjust K for the loop length
            K = K - path.size();
            K = K % loop.size();
            // Print the K-th element of the loop
            cout << loop[K] << endl;
        }
    } else {
        // If no loop, print the (K-1)-th element of the path
        cout << path[K - 1] << endl;
    }

    return 0;
}

// <END-OF-CODE>
