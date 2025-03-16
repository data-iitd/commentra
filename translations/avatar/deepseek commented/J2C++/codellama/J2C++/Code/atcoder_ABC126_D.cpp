#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int colors[100000]; // Step 2: Declare an array to store the color of each node

int main() {
    int n; // Step 1: Initialize a Scanner object to read input
    cin >> n; // Read the number of nodes
    int m = n - 1; // Calculate the number of edges
    for (int i = 0; i < n; i++) {
        colors[i] = -1; // Step 2: Set all colors to -1 initially
    }

    vector<Point> points(n); // Step 3: Create an array to store the points (nodes)
    for (int i = 0; i < n; i++) {
        points[i] = Point(i); // Step 3: Initialize each point with its name
    }

    while (m-- > 0) { // Step 4: Read the edges and their lengths
        int me, you, length; // Read the first node and adjust for 0-based index
        cin >> me >> you >> length;
        points[me - 1].becomeFriend(points[you - 1], length); // Update the friends list for the first node
        points[you - 1].becomeFriend(points[me - 1], length); // Update the friends list for the second node
    }

    dfs(points[0], 0); // Step 5: Perform a DFS starting from the first point

    for (int c : colors) { // Step 6: Output the color of each node
        cout << c << endl;
    }

    return 0;
}

void dfs(Point p, int length) {
    bool alreadyKnown = colors[p.name] != -1; // Check if the color of the current point is already known
    if (alreadyKnown) return; // If the color is already known, return

    if (length % 2 == 0) { // Check if the length of the path is even
        colors[p.name] = 0; // Color the current point as 0
    } else {
        colors[p.name] = 1; // Color the current point as 1
    }

    for (auto entry : p.friends) { // Iterate through the friends of the current point
        Point friend = entry.first; // Get the friend point
        int length2 = entry.second; // Get the length of the edge to the friend
        dfs(friend, length + length2); // Recursively call DFS for the friend
    }
}

struct Point {
    int name;
    map<Point, int> friends;

    Point(int name) {
        this->name = name;
    }

    void becomeFriend(Point p, int length) {
        this->friends[p] = length; // Add the friend and the length of the edge
    }
};

