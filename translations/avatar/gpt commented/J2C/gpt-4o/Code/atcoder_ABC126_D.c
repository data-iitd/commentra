#include <stdio.h>
#include <stdlib.h>

#define MAX_POINTS 1000 // Assuming a maximum number of points

// Structure to represent a point in the graph
typedef struct Point {
    int name; // Unique identifier for the point
    struct FriendNode* friends; // Pointer to the list of friends
    int friendCount; // Number of friends
} Point;

// Structure to represent a friend and the length of friendship
typedef struct FriendNode {
    Point* friendPoint; // Pointer to the friend point
    int length; // Length of friendship
    struct FriendNode* next; // Pointer to the next friend
} FriendNode;

// Array to store colors assigned to each point
int colors[MAX_POINTS];

// Function to create a new point
Point* createPoint(int name) {
    Point* p = (Point*)malloc(sizeof(Point));
    p->name = name;
    p->friends = NULL;
    p->friendCount = 0;
    return p;
}

// Function to establish friendship between two points
void becomeFriend(Point* p1, Point* p2, int length) {
    FriendNode* newFriend = (FriendNode*)malloc(sizeof(FriendNode));
    newFriend->friendPoint = p2;
    newFriend->length = length;
    newFriend->next = p1->friends;
    p1->friends = newFriend;
    p1->friendCount++;
}

// Depth-First Search (DFS) to assign colors based on friendship lengths
void dfs(Point* p, int length) {
    // Check if the point has already been colored
    if (colors[p->name] != -1) return; // Exit if already colored

    // Assign color based on the length (even or odd)
    colors[p->name] = (length % 2 == 0) ? 0 : 1;

    // Recursively visit all friends of the current point
    FriendNode* current = p->friends;
    while (current != NULL) {
        dfs(current->friendPoint, length + current->length); // Recursive DFS call
        current = current->next;
    }
}

int main() {
    // Create a scanner to read input
    int n;
    scanf("%d", &n); // Read the number of points (nodes)

    // Initialize colors array with -1 (indicating uncolored)
    for (int i = 0; i < n; i++) {
        colors[i] = -1;
    }

    // Create an array of Point pointers
    Point* points[MAX_POINTS];

    // Initialize each Point object with its index
    for (int i = 0; i < n; i++) {
        points[i] = createPoint(i);
    }

    // Read edges and establish friendships between points
    for (int m = n - 1; m > 0; m--) {
        int me, you, length;
        scanf("%d %d %d", &me, &you, &length); // Read points and length
        me--; you--; // Convert to 0-indexed
        becomeFriend(points[me], points[you], length); // Establish friendship
        becomeFriend(points[you], points[me], length); // Establish friendship in both directions
    }

    // Start DFS from the first point (index 0)
    dfs(points[0], 0);

    // Output the colors assigned to each point
    for (int i = 0; i < n; i++) {
        printf("%d\n", colors[i]);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        FriendNode* current = points[i]->friends;
        while (current != NULL) {
            FriendNode* temp = current;
            current = current->next;
            free(temp);
        }
        free(points[i]);
    }

    return 0;
}

// <END-OF-CODE>
