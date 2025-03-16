#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000

typedef struct Point {
    int name;
    struct FriendNode* friends;
} Point;

typedef struct FriendNode {
    Point* point;
    int length;
    struct FriendNode* next;
} FriendNode;

int colors[MAX_NODES]; // Array to store the color of each node

void dfs(Point* p, int length);

int main() {
    int n, m;
    scanf("%d", &n); // Read the number of nodes
    m = n - 1; // Calculate the number of edges
    memset(colors, -1, sizeof(colors)); // Set all colors to -1 initially

    Point* points = (Point*)malloc(n * sizeof(Point)); // Create an array to store the points (nodes)
    for (int i = 0; i < n; i++) {
        points[i].name = i; // Initialize each point with its name
        points[i].friends = NULL; // Initialize the friends list
    }

    while (m-- > 0) { // Read the edges and their lengths
        int me, you, length;
        scanf("%d %d %d", &me, &you, &length);
        me--; // Adjust for 0-based index
        you--; // Adjust for 0-based index

        // Add friend for the first node
        FriendNode* newFriend1 = (FriendNode*)malloc(sizeof(FriendNode));
        newFriend1->point = &points[you];
        newFriend1->length = length;
        newFriend1->next = points[me].friends;
        points[me].friends = newFriend1;

        // Add friend for the second node
        FriendNode* newFriend2 = (FriendNode*)malloc(sizeof(FriendNode));
        newFriend2->point = &points[me];
        newFriend2->length = length;
        newFriend2->next = points[you].friends;
        points[you].friends = newFriend2;
    }

    dfs(&points[0], 0); // Perform a DFS starting from the first point

    for (int i = 0; i < n; i++) { // Output the color of each node
        printf("%d\n", colors[i]);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        FriendNode* current = points[i].friends;
        while (current) {
            FriendNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(points);

    return 0;
}

void dfs(Point* p, int length) {
    if (colors[p->name] != -1) return; // If the color is already known, return

    colors[p->name] = (length % 2); // Color the current point based on the length

    FriendNode* current = p->friends; // Iterate through the friends of the current point
    while (current) {
        dfs(current->point, length + current->length); // Recursively call DFS for the friend
        current = current->next;
    }
}

// <END-OF-CODE>
