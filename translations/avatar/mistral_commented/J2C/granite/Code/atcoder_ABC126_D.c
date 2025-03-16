

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Point {
    int name;
    struct Point **friends;
    int *lengths;
    int friend_count;
} Point;

void dfs(Point *p, int length) {
    bool already_known = p->colors[p->name]!= -1;
    if (already_known) return;

    if (length % 2 == 0) {
        p->colors[p->name] = 0;
    } else {
        p->colors[p->name] = 1;
    }

    for (int i = 0; i < p->friend_count; i++) {
        dfs(p->friends[i], length + p->lengths[i]);
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    m = n - 1;

    Point *points = (Point *)malloc(sizeof(Point) * n);
    for (int i = 0; i < n; i++) {
        points[i].name = i;
        points[i].colors = (int *)malloc(sizeof(int) * n);
        memset(points[i].colors, -1, sizeof(int) * n);
    }

    while (m-- > 0) {
        int me, you, length;
        scanf("%d %d %d", &me, &you, &length);
        me--;
        you--;

        points[me].friends = (Point **)realloc(points[me].friends, sizeof(Point *) * (points[me].friend_count + 1));
        points[me].friends[points[me].friend_count] = &points[you];
        points[me].lengths = (int *)realloc(points[me].lengths, sizeof(int) * (points[me].friend_count + 1));
        points[me].lengths[points[me].friend_count] = length;
        points[me].friend_count++;

        points[you].friends = (Point **)realloc(points[you].friends, sizeof(Point *) * (points[you].friend_count + 1));
        points[you].friends[points[you].friend_count] = &points[me];
        points[you].lengths = (int *)realloc(points[you].lengths, sizeof(int) * (points[you].friend_count + 1));
        points[you].lengths[points[you].friend_count] = length;
        points[you].friend_count++;
    }

    dfs(&points[0], 0);

    for (int i = 0; i < n; i++) {
        printf("%d\n", points[i].colors[i]);
    }

    return 0;
}
