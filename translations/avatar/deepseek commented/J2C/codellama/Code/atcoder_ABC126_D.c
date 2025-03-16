#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100000

typedef struct {
    int name;
    int *friends;
    int *lengths;
    int numFriends;
} Point;

int colors[MAX_NODES];

void dfs(Point *p, int length) {
    int alreadyKnown = colors[p->name] != -1;
    if (alreadyKnown) return;

    if (length % 2 == 0) {
        colors[p->name] = 0;
    } else {
        colors[p->name] = 1;
    }

    for (int i = 0; i < p->numFriends; i++) {
        Point *friend = p->friends[i];
        int length2 = p->lengths[i];
        dfs(friend, length + length2);
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    m = n - 1;
    Point *points = (Point *) malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        points[i].name = i;
        points[i].numFriends = 0;
        points[i].friends = NULL;
        points[i].lengths = NULL;
    }

    while (m-- > 0) {
        int me, you;
        int length;
        scanf("%d %d %d", &me, &you, &length);
        me--;
        you--;
        points[me].numFriends++;
        points[me].friends = (Point **) realloc(points[me].friends, points[me].numFriends * sizeof(Point *));
        points[me].lengths = (int *) realloc(points[me].lengths, points[me].numFriends * sizeof(int));
        points[me].friends[points[me].numFriends - 1] = &points[you];
        points[me].lengths[points[me].numFriends - 1] = length;
        points[you].numFriends++;
        points[you].friends = (Point **) realloc(points[you].friends, points[you].numFriends * sizeof(Point *));
        points[you].lengths = (int *) realloc(points[you].lengths, points[you].numFriends * sizeof(int));
        points[you].friends[points[you].numFriends - 1] = &points[me];
        points[you].lengths[points[you].numFriends - 1] = length;
    }

    dfs(&points[0], 0);

    for (int i = 0; i < n; i++) {
        printf("%d\n", colors[i]);
    }

    return 0;
}

