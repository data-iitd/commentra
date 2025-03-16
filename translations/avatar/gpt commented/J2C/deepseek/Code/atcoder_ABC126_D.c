#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

// Array to store colors assigned to each point
int colors[MAX_N];

// Structure representing a point in the graph
typedef struct Point {
    int name;
    struct Point** friends;
    int friend_count;
} Point;

// Function to create a new point
Point* createPoint(int name) {
    Point* p = (Point*)malloc(sizeof(Point));
    p->name = name;
    p->friends = (Point**)malloc(MAX_N * sizeof(Point*));
    p->friend_count = 0;
    return p;
}

// Function to establish friendship between two points
void becomeFriend(Point* p1, Point* p2) {
    p1->friends[p1->friend_count++] = p2;
    p2->friends[p2->friend_count++] = p1;
}

// Depth-First Search (DFS) to assign colors based on friendship lengths
void dfs(Point* p, int length) {
    // Check if the point has already been colored
    if (colors[p->name] != -1) return;

    // Assign color based on the length (even or odd)
    colors[p->name] = length % 2 == 0 ? 0 : 1;

    // Recursively visit all friends of the current point
    for (int i = 0; i < p->friend_count; i++) {
        Point* friend = p->friends[i];
        dfs(friend, length + 1);
    }
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Initialize colors array with -1
    memset(colors, -1, sizeof(colors));

    // Create an array of Point objects
    Point* points[n];
    for (int i = 0; i < n; i++) {
        points[i] = createPoint(i);
    }

    int m = n - 1;
    printf("Enter the edges (format: me you length):\n");
    for (int i = 0; i < m; i++) {
        int me, you, length;
        scanf("%d %d %d", &me, &you, &length);
        becomeFriend(points[me - 1], points[you - 1]);
    }

    // Start DFS from the first point (index 0)
    dfs(points[0], 0);

    // Output the colors assigned to each point
    for (int i = 0; i < n; i++) {
        printf("Point %d: Color %d\n", i + 1, colors[i]);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(points[i]->friends);
        free(points[i]);
    }

    return 0;
}
