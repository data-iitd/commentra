#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int name; // The name of the point
    struct FriendNode* friends; // Pointer to the list of friends
} Point;

typedef struct FriendNode {
    Point* friend; // Pointer to the friend point
    int length; // Length of the friendship
    struct FriendNode* next; // Pointer to the next friend node
} FriendNode;

int* colors; // Array to store colors of points
int n; // Number of points

void becomeFriend(Point* p1, Point* p2, int length) {
    FriendNode* newFriend = (FriendNode*)malloc(sizeof(FriendNode));
    newFriend->friend = p2;
    newFriend->length = length;
    newFriend->next = p1->friends;
    p1->friends = newFriend;
}

void dfs(Point* p, int length) {
    if (colors[p->name] != -1) return; // Return if already visited

    colors[p->name] = (length % 2 == 0) ? 0 : 1; // Assign color based on length

    for (FriendNode* node = p->friends; node != NULL; node = node->next) {
        dfs(node->friend, length + node->length); // Recursive DFS call
    }
}

int main() {
    scanf("%d", &n); // Read number of points
    int m = n - 1; // Number of friendships
    colors = (int*)malloc(n * sizeof(int)); // Allocate memory for colors
    Point* points = (Point*)malloc(n * sizeof(Point)); // Allocate memory for points

    for (int i = 0; i < n; i++) { // Initialize points
        points[i].name = i;
        points[i].friends = NULL; // Initialize friends list
        colors[i] = -1; // Mark as unvisited
    }

    while (m-- > 0) { // Read friendships
        int me, you, length;
        scanf("%d %d %d", &me, &you, &length);
        me--; you--; // Convert to 0-based index
        becomeFriend(&points[me], &points[you], length); // Establish friendship
        becomeFriend(&points[you], &points[me], length); // Establish friendship
    }

    dfs(&points[0], 0); // Start DFS from the first point

    for (int i = 0; i < n; i++) { // Print colors
        printf("%d\n", colors[i]);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        FriendNode* node = points[i].friends;
        while (node != NULL) {
            FriendNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(points);
    free(colors);

    return 0;
}

// <END-OF-CODE>
