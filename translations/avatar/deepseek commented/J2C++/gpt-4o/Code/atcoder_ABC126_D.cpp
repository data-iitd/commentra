#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Point {
public:
    int name;
    unordered_map<Point*, int> friends;

    Point(int name) : name(name) {} // Constructor to initialize the point with its name

    void becomeFriend(Point* p, int length) {
        friends[p] = length; // Add the friend and the length of the edge
    }
};

vector<int> colors; // Step 2: Declare a vector to store the color of each node

void dfs(Point* p, int length) {
    if (colors[p->name] != -1) return; // If the color is already known, return

    colors[p->name] = (length % 2 == 0) ? 0 : 1; // Color the current point based on the length

    for (auto& entry : p->friends) { // Iterate through the friends of the current point
        Point* friendPoint = entry.first; // Get the friend point
        int length2 = entry.second; // Get the length of the edge to the friend
        dfs(friendPoint, length + length2); // Recursively call DFS for the friend
    }
}

int main() {
    int n;
    cin >> n; // Read the number of nodes
    int m = n - 1; // Calculate the number of edges
    colors.resize(n, -1); // Step 2: Initialize the colors vector with size n and fill with -1

    vector<Point*> points(n); // Step 3: Create a vector to store the points (nodes)
    for (int i = 0; i < n; i++) {
        points[i] = new Point(i); // Step 3: Initialize each point with its name
    }

    while (m-- > 0) { // Step 4: Read the edges and their lengths
        int me, you, length;
        cin >> me >> you >> length; // Read the nodes and the length of the edge
        me--; you--; // Adjust for 0-based index
        points[me]->becomeFriend(points[you], length); // Update the friends list for the first node
        points[you]->becomeFriend(points[me], length); // Update the friends list for the second node
    }

    dfs(points[0], 0); // Step 5: Perform a DFS starting from the first point

    for (int c : colors) { // Step 6: Output the color of each node
        cout << c << endl;
    }

    // Clean up dynamically allocated memory
    for (Point* point : points) {
        delete point;
    }

    return 0;
}

// <END-OF-CODE>
