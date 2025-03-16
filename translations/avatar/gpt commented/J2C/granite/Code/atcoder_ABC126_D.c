
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Array to store colors assigned to each point
int colors[1000];

// Structure to represent a point in the graph
typedef struct Point {
    int name; // Unique identifier for the point
    struct Point* friends[1000]; // Array to store friends
    int friendship_lengths[1000]; // Array to store friendship lengths
    int num_friends; // Number of friends
} Point;

// Function to add a friend to a point
void add_friend(Point* p, Point* friend, int length) {
    p->friends[p->num_friends] = friend;
    p->friendship_lengths[p->num_friends] = length;
    p->num_friends++;
}

// Function to assign colors based on friendship lengths using DFS
void dfs(Point* p, int length) {
    // Check if the point has already been colored
    bool already_known = colors[p->name]!= -1;
    if (already_known) return; // Exit if already colored

    // Assign color based on the length (even or odd)
    if (length % 2 == 0) {
        colors[p->name] = 0; // Even length -> color 0
    } else {
        colors[p->name] = 1; // Odd length -> color 1
    }

    // Recursively visit all friends of the current point
    for (int i = 0; i < p->num_friends; i++) {
        Point* friend = p->friends[i]; // Get the friend point
        int length2 = p->friendship_lengths[i]; // Get the length of friendship
        dfs(friend, length + length2); // Recursive DFS call
    }
}

int main() {
    // Create a scanner to read input
    int n; // Number of points (nodes)
    scanf("%d", &n);

    // Calculate the number of edges (m = n - 1 for a tree)
    int m = n - 1;

    // Initialize colors array with -1 (indicating uncolored)
    memset(colors, -1, sizeof(colors));

    // Create an array of Point objects
    Point points[n];

    // Initialize each Point object with its index
    for (int i = 0; i < n; i++) {
        points[i].name = i;
        points[i].num_friends = 0;
    }

    // Read edges and establish friendships between points
    while (m-- > 0) {
        int me, you, length; // Read first point (0-indexed), second point (0-indexed), and length of the friendship
        scanf("%d %d %d", &me, &you, &length);
        add_friend(&points[me - 1], &points[you - 1], length); // Establish friendship in both directions
        add_friend(&points[you - 1], &points[me - 1], length);
    }

    // Start DFS from the first point (index 0)
    dfs(&points[0], 0);

    // Output the colors assigned to each point
    for (int i = 0; i < n; i++) {
        printf("%d\n", colors[i]);
    }

    return 0;
}

