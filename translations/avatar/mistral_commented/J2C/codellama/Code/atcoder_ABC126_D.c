
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POINTS 100000
#define MAX_FRIENDSHIPS 100000

typedef struct {
    int name;
    int length;
    struct Point *friend;
} Friendship;

typedef struct {
    int name;
    int color;
    int numFriends;
    Friendship *friends;
} Point;

void dfs(Point *p, int length) {
    if (p->color != -1) return;

    if (length % 2 == 0) {
        p->color = 0;
    } else {
        p->color = 1;
    }

    for (int i = 0; i < p->numFriends; i++) {
        dfs(p->friends[i].friend, length + p->friends[i].length);
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    m = n - 1;
    Point *points = (Point *)malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        points[i].name = i;
        points[i].color = -1;
        points[i].numFriends = 0;
        points[i].friends = (Friendship *)malloc(MAX_FRIENDSHIPS * sizeof(Friendship));
    }

    while (m-- > 0) {
        int me, you;
        int length;
        scanf("%d %d %d", &me, &you, &length);
        points[me].friends[points[me].numFriends].friend = &points[you];
        points[me].friends[points[me].numFriends].length = length;
        points[me].numFriends++;
        points[you].friends[points[you].numFriends].friend = &points[me];
        points[you].friends[points[you].numFriends].length = length;
        points[you].numFriends++;
    }

    dfs(&points[0], 0);

    for (int i = 0; i < n; i++) {
        printf("%d\n", points[i].color);
    }

    return 0;
}

