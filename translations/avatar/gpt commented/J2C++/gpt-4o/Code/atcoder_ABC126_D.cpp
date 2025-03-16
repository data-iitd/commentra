#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Class representing a point in the graph
class Point {
public:
    int name; // Unique identifier for the point
    unordered_map<Point*, int> friends; // Map to store friends and their friendship lengths

    // Constructor to initialize the point with its name
    Point(int name) : name(name) {}

    // Method to establish friendship with another point
    void becomeFriend(Point* p, int length) {
        friends[p] = length; // Add friend with the specified length
    }
};

// Array to store colors assigned to each point
vector<int> colors;

void dfs(Point* p, int length) {
    // Check if the point has already been colored
    if (colors[p->name] != -1) return; // Exit if already colored

    // Assign color based on the length (even or odd)
    colors[p->name] = (length % 2 == 0) ? 0 : 1; // Even length -> color 0, Odd length -> color 1

    // Recursively visit all friends of the current point
    for (const auto& entry : p->friends) {
        Point* friendPoint = entry.first; // Get the friend point
        int length2 = entry.second; // Get the length of friendship
        dfs(friendPoint, length + length2); // Recursive DFS call
    }
}

int main() {
    // Create a scanner to read input
    int n;
    cin >> n;

    // Calculate the number of edges (m = n - 1 for a tree)
    int m = n - 1;

    // Initialize colors array with -1 (indicating uncolored)
    colors.resize(n, -1);

    // Create an array of Point objects
    vector<Point*> points(n);
    for (int i = 0; i < n; i++) {
        points[i] = new Point(i); // Initialize each Point object with its index
    }

    // Read edges and establish friendships between points
    while (m-- > 0) {
        int me, you, length;
        cin >> me >> you >> length; // Read first point, second point, and length of friendship
        me--; you--; // Convert to 0-indexed

        // Establish friendship in both directions
        points[me]->becomeFriend(points[you], length);
        points[you]->becomeFriend(points[me], length);
    }

    // Start DFS from the first point (index 0)
    dfs(points[0], 0);

    // Output the colors assigned to each point
    for (int c : colors) {
        cout << c << endl;
    }

    // Clean up dynamically allocated memory
    for (Point* point : points) {
        delete point;
    }

    return 0;
}

// <END-OF-CODE>
