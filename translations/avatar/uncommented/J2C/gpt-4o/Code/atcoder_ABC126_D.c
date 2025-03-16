#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

typedef struct Point {
    int name;
    struct FriendNode* friends;
    int friendCount;
} Point;

typedef struct FriendNode {
    Point* friend;
    int length;
    struct FriendNode* next;
} FriendNode;

int colors[MAX_N];

void dfs(Point* p, int length);

int main() {
    int n, m;
    scanf("%d", &n);
    m = n - 1;

    memset(colors, -1, sizeof(colors));

    Point* points = (Point*)malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        points[i].name = i;
        points[i].friends = NULL;
        points[i].friendCount = 0;
    }

    while (m-- > 0) {
        int me, you, length;
        scanf("%d %d %d", &me, &you, &length);
        me--; you--; // Convert to 0-based index

        // Add friend for me
        FriendNode* newFriendMe = (FriendNode*)malloc(sizeof(FriendNode));
        newFriendMe->friend = &points[you];
        newFriendMe->length = length;
        newFriendMe->next = points[me].friends;
        points[me].friends = newFriendMe;
        points[me].friendCount++;

        // Add friend for you
        FriendNode* newFriendYou = (FriendNode*)malloc(sizeof(FriendNode));
        newFriendYou->friend = &points[me];
        newFriendYou->length = length;
        newFriendYou->next = points[you].friends;
        points[you].friends = newFriendYou;
        points[you].friendCount++;
    }

    dfs(&points[0], 0);

    for (int i = 0; i < n; i++) {
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
    if (colors[p->name] != -1) return;

    colors[p->name] = (length % 2 == 0) ? 0 : 1;

    FriendNode* current = p->friends;
    while (current) {
        dfs(current->friend, length + current->length);
        current = current->next;
    }
}

// <END-OF-CODE>
