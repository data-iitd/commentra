#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

vector<int> colors; // Step 2: Declare a vector to store the color of each node

void dfs(pair<int, vector<pair<int, int>>>& p, int length) {
    bool alreadyKnown = colors[p.first] != -1; // Check if the color of the current point is already known
    if (alreadyKnown) return; // If the color is already known, return

    if (length % 2 == 0) { // Check if the length of the path is even
        colors[p.first] = 0; // Color the current point as 0
    } else {
        colors[p.first] = 1; // Color the current point as 1
    }

    for (auto& entry : p.second) { // Iterate through the friends of the current point
        int friendIndex = entry.first; // Get the friend index
        int length2 = entry.second; // Get the length of the edge to the friend
        dfs(make_pair(friendIndex, p.second), length + length2); // Recursively call DFS for the friend
    }
}

int main() {
    int n, m;
    cin >> n; // Read the number of nodes
    m = n - 1; // Calculate the number of edges
    colors.assign(n, -1); // Step 2: Initialize the colors vector with size n and set all colors to -1

    vector<pair<int, vector<pair<int, int>>>> points(n); // Step 3: Create a vector to store the points (nodes)
    for (int i = 0; i < n; i++) {
        points[i] = make_pair(i, vector<pair<int, int>>()); // Step 3: Initialize each point with its name and an empty friends list
    }

    while (m-- > 0) { // Step 4: Read the edges and their lengths
        int me, you, length;
        cin >> me >> you >> length;
        me--; // Adjust for 0-based index
        you--; // Adjust for 0-based index
        points[me].second.emplace_back(you, length); // Update the friends list for the first node
        points[you].second.emplace_back(me, length); // Update the friends list for the second node
    }

    dfs(points[0], 0); // Step 5: Perform a DFS starting from the first point

    for (int c : colors) { // Step 6: Output the color of each node
        cout << c << endl;
    }

    return 0;
}
