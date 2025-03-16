
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Point {
    int name;
    struct Point **friends;
    int *lengths;
    int friendCount;
} Point;

void dfs(Point *p, int length) {
    bool alreadyKnown = p->colors[p->name]!= -1;
    if (alreadyKnown) return;

    if (length % 2 == 0) {
        p->colors[p->name] = 0;
    } else {
        p->colors[p->name] = 1;
    }

    for (int i = 0; i < p->friendCount; i++) {
        dfs(p->friends[i], length + p->lengths[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Point *points = (Point *)malloc(sizeof(Point) * n);
    for (int i = 0; i < n; i++) {
        points[i].name = i;
        points[i].colors = (int *)malloc(sizeof(int) * n);
        memset(points[i].colors, -1, sizeof(int) * n);
    }

    for (int i = 0; i < m; i++) {
        int me, you, length;
        scanf("%d %d %d", &me, &you, &length);
        me--;
        you--;
        points[me].friends = (Point **)realloc(points[me].friends, sizeof(Point *) * (points[me].friendCount + 1));
        points[me].lengths = (int *)realloc(points[me].lengths, sizeof(int) * (points[me].friendCount + 1));
        points[me].friends[points[me].friendCount] = &points[you];
        points[me].lengths[points[me].friendCount] = length;
        points[me].friendCount++;

        points[you].friends = (Point **)realloc(points[you].friends, sizeof(Point *) * (points[you].friendCount + 1));
        points[you].lengths = (int *)realloc(points[you].lengths, sizeof(int) * (points[you].friendCount + 1));
        points[you].friends[points[you].friendCount] = &points[me];
        points[you].lengths[points[you].friendCount] = length;
        points[you].friendCount++;
    }

    dfs(&points[0], 0);

    for (int i = 0; i < n; i++) {
        printf("%d\n", points[i].colors[i]);
    }

    for (int i = 0; i < n; i++) {
        free(points[i].colors);
        free(points[i].friends);
        free(points[i].lengths);
    }
    free(points);

    return 0;
}
