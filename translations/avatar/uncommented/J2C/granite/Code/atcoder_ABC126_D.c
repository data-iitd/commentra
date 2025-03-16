
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
    int name;
    struct Point *friends;
    int friends_length;
} Point;

void dfs(Point *p, int length) {
    bool alreadyKnown = p->color!= -1;
    if (alreadyKnown) return;
    if (length % 2 == 0) {
        p->color = 0;
    } else {
        p->color = 1;
    }
    for (int i = 0; i < p->friends_length; i++) {
        dfs(p->friends[i], length + p->friends[i]->distance);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Point *points = (Point *)malloc(sizeof(Point) * n);
    for (int i = 0; i < n; i++) {
        points[i].name = i;
        points[i].color = -1;
        points[i].friends = NULL;
        points[i].friends_length = 0;
    }
    for (int i = 0; i < m; i++) {
        int me, you, length;
        scanf("%d %d %d", &me, &you, &length);
        me--;
        you--;
        points[me].friends = (Point *)realloc(points[me].friends, sizeof(Point) * (points[me].friends_length + 1));
        points[me].friends[points[me].friends_length] = &points[you];
        points[me].friends_length++;
        points[you].friends = (Point *)realloc(points[you].friends, sizeof(Point) * (points[you].friends_length + 1));
        points[you].friends[points[you].friends_length] = &points[me];
        points[you].friends_length++;
        points[me].distance = length;
        points[you].distance = length;
    }
    dfs(&points[0], 0);
    for (int i = 0; i < n; i++) {
        printf("%d\n", points[i].color);
    }
    return 0;
}

