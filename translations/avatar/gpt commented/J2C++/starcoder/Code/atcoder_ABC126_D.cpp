#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

// Array to store colors assigned to each point
int colors[100000];

// Class representing a point in the graph
class Point {
public:
    int name; // Unique identifier for the point
    map<Point, int> friends; // Map to store friends and their friendship lengths
    
    // Constructor to initialize the point with its name
    Point(int name) {
        this->name = name;
        this->friends = map<Point, int>(); // Initialize friends map
    }
    
    // Method to establish friendship with another point
    void becomeFriend(Point p, int length) {
        this->friends[p] = length; // Add friend with the specified length
    }
};

// Depth-First Search (DFS) to assign colors based on friendship lengths
void dfs(Point p, int length) {
    // Check if the point has already been colored
    bool alreadyKnown = colors[p.name]!= -1;
    if (alreadyKnown) return; // Exit if already colored
    
    // Assign color based on the length (even or odd)
    if (length % 2 == 0) {
        colors[p.name] = 0; // Even length -> color 0
    } else {
        colors[p.name] = 1; // Odd length -> color 1
    }
    
    // Recursively visit all friends of the current point
    for (pair<Point, int> entry : p.friends) {
        Point friend = entry.first; // Get the friend point
        int length2 = entry.second; // Get the length of friendship
        dfs(friend, length + length2); // Recursive DFS call
    }
}

int main() {
    // Create a scanner to read input
    int n;
    cin >> n;
    
    // Calculate the number of edges (m = n - 1 for a tree)
    int m = n - 1;
    
    // Initialize colors array with -1 (indicating uncolored)
    fill(colors, colors + n, -1);
    
    // Create an array of Point objects
    Point points[n];
    
    // Initialize each Point object with its index
    for (int i = 0; i < n; i++) {
        points[i] = Point(i);
    }
    
    // Read edges and establish friendships between points
    while (m-- > 0) {
        int me, you, length;
        cin >> me >> you >> length; // Read first point (0-indexed) and length
        me--; // Convert to 0-indexed
        you--; // Convert to 0-indexed
        
        // Establish friendship in both directions
        points[me].becomeFriend(points[you], length);
        points[you].becomeFriend(points[me], length);
    }
    
    // Start DFS from the first point (index 0)
    dfs(points[0], 0);
    
    // Output the colors assigned to each point
    for (int c : colors) {
        cout << c << endl;
    }
    
    return 0;
}

